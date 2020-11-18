#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "vtkOpenGLRenderWindow.h"
#include "QVTKOpenGLWindow.h"
#include <vtkActor.h>
#include <vtkGenericOpenGLRenderWindow.h>
#include <vtkNamedColors.h>
#include <vtkNew.h>
#include <vtkPolyDataMapper.h>
#include <vtkProperty.h>
#include <vtkRenderWindow.h>
#include <vtkRenderer.h>
#include <vtkSphereSource.h>
#include <vtkVersion.h>
#include <vtkOpenGLRenderWindow.h>
#include <QVTKOpenGLNativeWidget.h>

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
 private slots:
    void browse();

private:
    QVTKOpenGLNativeWidget* widget;
    //QVTKOpenGLNativeWidget * ptr;
    //Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
