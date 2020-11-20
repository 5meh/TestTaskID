#ifndef LEFTMENU_H
#define LEFTMENU_H

#include <QObject>
#include <QWidget>
#include <QGridLayout>

class QLabel;
class QPushButton;
class QLineEdit;
class QMovie;

class LeftMenu: public QWidget
{
    Q_OBJECT
public:
    LeftMenu(QWidget *parent = nullptr);
private:
      QPushButton* loadBtn;
      QPushButton* removeBtn;
      QLabel* captionLabel;
      QLabel* fileNameLabel;
      QLabel* loaderLabel;
      QGridLayout m_Layout;
      QString fileName;
public slots:
      void stopLoadingAnimation();
signals:
      void loadedObjPath(QString path);
      void removeBtnClicked();
private slots:
      void load();
      void remove();
private:
      QMovie *movie;
};

#endif // LEFTMENU_H
