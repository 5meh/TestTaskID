#ifndef LEFTMENU_H
#define LEFTMENU_H

#include <QObject>
#include <QWidget>
#include <QVBoxLayout>
#include <QGridLayout>


class QLabel;
class QPushButton;
class QLineEdit;

class LeftMenu: public QWidget
{
    Q_OBJECT
public:
    LeftMenu(QWidget *parent = nullptr);
private:
      QPushButton* loadBtn;
      QPushButton* removeBtn;
      QLabel* captionLabel;
      QLineEdit* loadFolder;
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
