#include "widget.h"

#include <QLabel>
#include <QLayout>
#include <QSplitter>
#include <QSizePolicy>
#include <QEvent>

ButtonHoverWatcher::ButtonHoverWatcher(QString normIcon,QString hovIcon, QObject * parent):
    QObject(parent),
    normalIconPath(normIcon),
    hoveredIconPath(hovIcon)
{

}

bool ButtonHoverWatcher::eventFilter(QObject * watched, QEvent * event)
{
    QPushButton * button = qobject_cast<QPushButton*>(watched);
    if (!button) {
        return false;
    }

    if (event->type() == QEvent::Enter) {
        // The push button is hovered by mouse
        button->setIcon(QIcon(hoveredIconPath));
        return true;
    }

    if (event->type() == QEvent::Leave){
        // The push button is not hovered by mouse
        button->setIcon(QIcon(normalIconPath));
        return true;
    }

    return false;
}

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
    //this->setContentsMargins(0,0,0,0);
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

    QSplitter* split = new QSplitter(Qt::Orientation::Horizontal, this);
    split->setSizePolicy(QSizePolicy::Fixed, QSizePolicy::Expanding);
    split->setAttribute(Qt::WA_TransparentForMouseEvents);
    split->setFixedWidth(10);
    split->setStyleSheet("background-color: white; border: none;");

    toolBar->addWidget(split);
    toolBar->addWidget(closeButton);
    toolBar->layout()->setContentsMargins(0,0,0,0);
    toolBar->setContentsMargins(0,0,0,0);
    toolBar->layout()->setAlignment(minimizeButton, Qt::AlignRight);
    toolBar->layout()->setAlignment(maximizeButton, Qt::AlignRight);
    toolBar->layout()->setAlignment(closeButton, Qt::AlignRight);
    toolBar->layout()->setAlignment(titleLabel, Qt::AlignLeft);
#endif

}

void Widget::initTitleButtons()
{
    //Create the min/max/close buttons
    minimizeButtonWatcher = new ButtonHoverWatcher(":/icons/images/minimize_app.png", ":/icons/images/minimize_app_hovered.png", this);
    minimizeButton = new QPushButton(QIcon(":/icons/images/minimize_app.png"),"");
    minimizeButton->installEventFilter(minimizeButtonWatcher);

    maximizeButtonWatcher = new ButtonHoverWatcher(":/icons/images/max_app.png", ":/icons/images/max_app_ hovered.png", this);
    maximizeButton = new QPushButton(QIcon(":/icons/images/max_app.png"),"");
    maximizeButton->installEventFilter(maximizeButtonWatcher);

    closeButtonWatcher = new ButtonHoverWatcher(":/icons/images/close_app.png", ":/icons/images/close_app_hovered.png", this);
    closeButton = new QPushButton(QIcon(":/icons/images/close_app.png"),"");
    closeButton->installEventFilter(closeButtonWatcher);

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
