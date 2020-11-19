#ifndef LEFTMENU_H
#define LEFTMENU_H

#include <QObject>
#include <QWidget>
#include <QVBoxLayout>
#include <QGridLayout>


class QLabel;
class QPushButton;
class QLineEdit;
#include <QMovie>
//class QMovie;

class LeftMenu: public QWidget
{
    Q_OBJECT
public:
    LeftMenu(QWidget *parent = nullptr);
      QMovie *movie;//uh lazy to make private access etc
private:
      QPushButton* loadBtn;
      QPushButton* removeBtn;
      QLabel* captionLabel;
      QLabel* fileNameLabel;
      QLabel* loaderLabel;
      QGridLayout m_Layout;
      QString fileName;
signals:
      void loadedObjPath(QString path);
      void removeBtnClicked();
private slots:
      void load();
      void remove();
};

#endif // LEFTMENU_H
