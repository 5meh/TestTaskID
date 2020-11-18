#include "leftmenu.h"
#include <QPushButton>
#include <QLabel>

LeftMenu::LeftMenu(QWidget *parent):
    QWidget(parent),
    loadBtn(nullptr),
    removeBtn(nullptr)
{
    QPalette Pal(palette());
    Pal.setColor(QPalette::Background, Qt::red);
    setAutoFillBackground(true);
    setPalette(Pal);
    setLayout(&m_Layout);

    captionLabel = new QLabel(tr("WIZARD"), this);
    loadBtn = new QPushButton(tr("&Load"), this);
    removeBtn = new QPushButton(tr("Remove"), this);
    m_Layout.addWidget(captionLabel,0,0,0,2,Qt::AlignHCenter);

    m_Layout.addWidget(loadBtn, 1, 0, Qt::AlignHCenter);
    m_Layout.addWidget(removeBtn,1,1, Qt::AlignHCenter);
}
