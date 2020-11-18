#include "widget.h"

#include <QLabel>
#include <QLayout>
#include <QSplitter>
#include <QSizePolicy>

Widget::Widget(QWidget *parent)
	: QMainWindow(parent)
{	
	QPalette Pal(palette());
    Pal.setColor(QPalette::Background, Qt::white);
	setAutoFillBackground(true);
    setPalette(Pal);
    initToolBar();
}

void Widget::initToolBar()
{

#ifdef _WIN32

    toolBar = new QToolBar(this);
    toolBar->setMovable(false);
    toolBar->setFloatable(false);
    toolBar->setLayout(new QHBoxLayout(this));
    addToolBar(toolBar);

    //Create a transparent-to-mouse-events widget that pads right for a fixed width equivalent to min/max/close buttons
    QWidget* btnSpacer = new QWidget(toolBar);
    btnSpacer->setAttribute(Qt::WA_TransparentForMouseEvents);
    btnSpacer->setSizePolicy(QSizePolicy::Fixed, QSizePolicy::Expanding);
    btnSpacer->setStyleSheet("background-color: none; border: none;");
    btnSpacer->setFixedWidth(135 /* rough width of close/min/max buttons */);
    toolBar->addWidget(btnSpacer);
    toolBar->setStyleSheet("background-color: black; border: none;");

    QLabel* titleLabel = new QLabel("ObjViewer");
    titleLabel->setStyleSheet("QLabel { color : white; }");
    titleLabel->setAttribute(Qt::WA_TransparentForMouseEvents);

    QWidget* rightSpacer = new QWidget(toolBar);

    rightSpacer->setAttribute(Qt::WA_TransparentForMouseEvents);
    rightSpacer->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
    rightSpacer->setStyleSheet("background-color: none; border: none;");

    toolBar->addWidget(titleLabel);
    toolBar->addWidget(rightSpacer);
    initTitleButtons();

    toolBar->addWidget(minimizeButton);
    toolBar->addWidget(maximizeButton);
    QSplitter* split = new QSplitter(Qt::Orientation::Horizontal);
    split->setAttribute(Qt::WA_TransparentForMouseEvents);
    split->setFixedWidth(10);
    //split->setFixedHeight(80);

    split->setStyleSheet("background-color: white; border: none;");

    toolBar->addWidget(split);
    toolBar->addWidget(closeButton);

    toolBar->layout()->setAlignment(minimizeButton, Qt::AlignRight);
    toolBar->layout()->setAlignment(maximizeButton, Qt::AlignRight);
    toolBar->layout()->setAlignment(closeButton, Qt::AlignRight);
    toolBar->layout()->setAlignment(titleLabel, Qt::AlignLeft);
#endif

}

void Widget::initTitleButtons()
{
    //Create the min/max/close buttons
    minimizeButton = new QPushButton(QIcon(":/icons/images/minimize_app.png"),"");
    maximizeButton = new QPushButton(QIcon(":/icons/images/max_app.png"),"");
    closeButton = new QPushButton(QIcon(":/icons/images/close_app.png"),"");

    closeButton->iconSize().boundedTo(closeButton->size());

    closeButton->setStyleSheet("background-color: rgb(255, 140, 0); color: none");

    closeButton->setFlat(true);
    minimizeButton->setFlat(true);
    maximizeButton->setFlat(true);
    maximizeButton->setCheckable(true);

    closeButton->setIconSize(closeButton->size());
    minimizeButton->setIconSize(minimizeButton->size());
    maximizeButton->setIconSize(maximizeButton->size());

    minimizeButton->setFixedSize(80, 80);
    maximizeButton->setFixedSize(80, 80);
    closeButton->setFixedSize(80,80);
}
