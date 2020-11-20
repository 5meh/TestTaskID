#include "leftmenu.h"
#include <QPushButton>
#include <QLabel>
#include <QFileDialog>
#include <QMovie>

LeftMenu::LeftMenu(QWidget *parent):
    QWidget(parent),
    loadBtn(nullptr),
    removeBtn(nullptr)
{
    QPalette Pal(palette());
    Pal.setColor(QPalette::Background, Qt::black);
    setAutoFillBackground(true);
    setPalette(Pal);
    setLayout(&m_Layout);

    captionLabel = new QLabel("WIZARD", this);
    fileNameLabel = new QLabel("",this);
    fileNameLabel->hide();
    fileNameLabel->setStyleSheet("color:white;border: 1px solid white");
    captionLabel->setStyleSheet("color:white;");

    loadBtn = new QPushButton(tr("&Load"), this);
    loadBtn->setStyleSheet(":enabled{color:white; border: 1px solid white} "
                           ":hover{background-color: white}"
                           ":disabled { color:black, border: 1px solid black; background-color: gray");
    removeBtn = new QPushButton(tr("Remove"), this);
    removeBtn->setStyleSheet(":enabled{color:white; border: 1px solid white} "
                              ":hover{  background-color: white}"
                             ":disabled { color:black, border: 1px solid black; background-color: gray");

    loadBtn->setFixedWidth(100);
    removeBtn->setFixedWidth(100);
    loaderLabel = new QLabel(this);
    movie = new QMovie(loaderLabel);
    movie->setFileName(":/loader.gif");
    movie->setScaledSize(QSize(80,80));
    loaderLabel->hide();
    loaderLabel->setMovie(movie);

    connect(loadBtn,&QAbstractButton::clicked,this, &LeftMenu::load);
    connect(removeBtn, &QAbstractButton::clicked, this, &LeftMenu::remove);

    m_Layout.addWidget(captionLabel,0,0,1,-1,Qt::AlignLeft);
    m_Layout.addWidget(loadBtn, 1, 0, Qt::AlignTop);
    m_Layout.addWidget(removeBtn,1,1, Qt::AlignTop);
    m_Layout.addWidget(fileNameLabel,3,0,1,2,Qt::AlignHCenter);
    m_Layout.addWidget(loaderLabel,4,0,1,2,Qt::AlignHCenter);

    QWidget* menuSpacer = new QWidget(this);
    menuSpacer->setAttribute(Qt::WA_TransparentForMouseEvents);
    menuSpacer->setContentsMargins(0,0,0,0);
    menuSpacer->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
    menuSpacer->setStyleSheet("background-color: black; border: none;");
    menuSpacer->setFixedHeight(800);
    m_Layout.addWidget(menuSpacer, 5, 0, -1, -1, Qt::AlignTop);

    m_Layout.setContentsMargins(0,0,0,0);
}

void LeftMenu::load()
{
    fileName = QFileDialog::getOpenFileName(this, tr("Open File"),
                                                    "D://",
                                        tr("Model (*.obj)"));
     if(fileName.isEmpty())
         return;
    QFileInfo info(fileName);
    fileNameLabel->setText(info.fileName());
    fileNameLabel->show();
    loaderLabel->show();
    movie->start();
    loadBtn->setDisabled(true);
    removeBtn->setDisabled(true);
    emit loadedObjPath(fileName);
}

void LeftMenu::stopLoadingAnimation()
{
    movie->stop();
    loaderLabel->hide();
    loadBtn->setDisabled(false);
    removeBtn->setDisabled(false);
}

void LeftMenu::remove()
{
    fileNameLabel->clear();
    fileNameLabel->hide();
    emit removeBtnClicked();
}
