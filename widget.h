#ifndef WIDGET_H
#define WIDGET_H

#include <QMainWindow>
#include <QPushButton>
#include <QToolBar>

class Widget : public QMainWindow
{
    Q_OBJECT
public:
    explicit Widget(QWidget *parent = 0);	

	QPushButton* maximizeButton = nullptr;
	QPushButton* minimizeButton = nullptr;
	QPushButton* closeButton = nullptr;	

    QToolBar* toolBar = nullptr;
private:
    void initTitleButtons();
    void initToolBar();
};

#endif // WIDGET_H
