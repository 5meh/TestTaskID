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
    fileNameLabel = new QLabel("Test",this);
    fileNameLabel->setStyleSheet("color:white;");
    captionLabel->setStyleSheet("color:white;");

    loadBtn = new QPushButton(tr("&Load"), this);

    removeBtn = new QPushButton(tr("Remove"), this);
    //loadBtn->setStyleSheet("color:white; background-color: black;border: 2px solid white;");
    //loadBtn->setStyleSheet(QString("QPushButton#") + loadBtn->objectName() + QString("background-color: rgb(224, 0, 0); border-style: inset "));
    //removeBtn->setStyleSheet("color:white; background-color: black;border: 2px solid white;");
    loadBtn->setFixedWidth(100);
    removeBtn->setFixedWidth(100);
    loaderLabel = new QLabel(this);
    movie = new QMovie(loaderLabel);
    movie->setFileName(":/loader.gif");
    loaderLabel->setMovie(movie);

    connect(loadBtn,&QAbstractButton::clicked,this, &LeftMenu::load);
    connect(removeBtn, &QAbstractButton::clicked, this, &LeftMenu::remove);

    m_Layout.addWidget(captionLabel,0,0,1,2,Qt::AlignLeft);
    m_Layout.addWidget(loadBtn, 1, 0, Qt::AlignTop);
    m_Layout.addWidget(removeBtn,1,1, Qt::AlignTop);
    m_Layout.addWidget(fileNameLabel,3,0,1,2,Qt::AlignHCenter);
    m_Layout.addWidget(loaderLabel,4,0,1,2,Qt::AlignCenter);

    QWidget* menuSpacer = new QWidget(this);
    menuSpacer->setAttribute(Qt::WA_TransparentForMouseEvents);
    menuSpacer->setContentsMargins(0,0,0,0);
    menuSpacer->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Fixed);
    menuSpacer->setStyleSheet("background-color: white; border: none;");
    menuSpacer->setFixedHeight(20);
    m_Layout.addWidget(menuSpacer, 0, 0, 0, 2, Qt::AlignTop);

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
    fileNameLabel->setText(info.baseName());
    loaderLabel->show();
    movie->start();
    emit loadedObjPath(fileName);
}

void LeftMenu::remove()
{
    fileNameLabel->clear();
    emit removeBtnClicked();
}
