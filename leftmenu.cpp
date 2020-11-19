#include "leftmenu.h"
#include <QPushButton>
#include <QLabel>
#include <QFileDialog>

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

    captionLabel = new QLabel(tr("WIZARD"), this);
    //captionLabel->setStyleSheet(" color : white;background-color: white;");

    loadBtn = new QPushButton(tr("&Load"), this);
    removeBtn = new QPushButton(tr("Remove"), this);
    connect(loadBtn,&QAbstractButton::clicked,this, &LeftMenu::load);
    connect(removeBtn, &QAbstractButton::clicked, this, &LeftMenu::remove);

    m_Layout.addWidget(captionLabel,1,0,0,2,Qt::AlignHCenter);
    m_Layout.addWidget(loadBtn, 2, 0, Qt::AlignHCenter);
    m_Layout.addWidget(removeBtn,2,1, Qt::AlignHCenter);

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
    emit loadedObjPath(fileName);
}

void LeftMenu::remove()
{
    emit removeBtnClicked();
}
