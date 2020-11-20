#ifndef WIDGET_H
#define WIDGET_H

#include <QMainWindow>
#include <QPushButton>
#include <QToolBar>

class ButtonHoverWatcher : public QObject
{
    Q_OBJECT
public:
    explicit ButtonHoverWatcher(QString normIcon,QString hovIcon, QObject * parent = Q_NULLPTR);
    virtual bool eventFilter(QObject * watched, QEvent * event) Q_DECL_OVERRIDE;
private:
    QString normalIconPath;
    QString hoveredIconPath;
};



class Widget : public QMainWindow
{
    Q_OBJECT
public:
    explicit Widget(QWidget *parent = 0);
    ButtonHoverWatcher * maximizeButtonWatcher;
    QPushButton* maximizeButton;
    ButtonHoverWatcher * minimizeButtonWatcher;
    QPushButton* minimizeButton;
    ButtonHoverWatcher * closeButtonWatcher;
    QPushButton* closeButton;

    QToolBar* toolBar;
private:
    void initTitleButtons();
    void initToolBar();
};

#endif // WIDGET_H
