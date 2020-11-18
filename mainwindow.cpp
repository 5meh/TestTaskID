#include "mainwindow.h"
//#include "./ui_mainwindow.h"
#include <QFileDialog>
#include <QPushButton>
#include <vtkOBJImporter.h>
#include <vtkOBJReader.h>
#include <vtkCamera.h>
#include <QSurfaceFormat>
#include <QLabel>
#include <QLayout>
#include <QDockWidget>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent) 
{
    this->setWindowFlags(Qt::Window | Qt::WindowTitleHint | Qt::CustomizeWindowHint);
     this->setGeometry(200,200,600,800);
    QGridLayout* gridLay = new QGridLayout(this);
    //this->setLayout(gridLay);

    QPushButton* closeBtn = new QPushButton("X",this);
    QPushButton* maximizeBtn = new QPushButton("max", this);

    QVBoxLayout* titleButtonsLayout = new QVBoxLayout(this);
    titleButtonsLayout->addWidget(maximizeBtn, Qt::AlignRight);
    titleButtonsLayout->addWidget(closeBtn, Qt::AlignRight);
    //this->setLayout(new QVBoxLayout(this));

    //this->centralWidget()->layout()->addItem(titleButtonsLayout);
    //this->layout()->addItem(titleButtonsLayout);

   /* QSurfaceFormat::setDefaultFormat(QVTKOpenGLNativeWidget::defaultFormat());
    viewer = new QVTKOpenGLNativeWidget(this);

    setWindowFlags(Qt::Window | Qt::WindowTitleHint | Qt::CustomizeWindowHint);
    this->setGeometry(200,200,1000,6000);
    vtkSmartPointer<vtkOBJReader> reader =
        vtkSmartPointer<vtkOBJReader>::New();
      reader->SetFileName("D:\\Downloads\\soccer+ball\\soccer ball.obj");
      reader->Update();


       vtkNew<vtkGenericOpenGLRenderWindow> renderWindow;

       viewer->setRenderWindow(renderWindow);
      // Visualize
      vtkSmartPointer<vtkNamedColors> colors =
        vtkSmartPointer<vtkNamedColors>::New();
      vtkColor3d backgroundColor = colors->GetColor3d("SpringGreen");
      vtkColor3d actorColor      = colors->GetColor3d("HoneyDew");

      vtkSmartPointer<vtkPolyDataMapper> mapper =
        vtkSmartPointer<vtkPolyDataMapper>::New();
      mapper->SetInputConnection(reader->GetOutputPort());

      vtkSmartPointer<vtkActor> actor =
        vtkSmartPointer<vtkActor>::New();
      actor->SetMapper(mapper);
      actor->GetProperty()->SetDiffuseColor(actorColor.GetData());

      vtkSmartPointer<vtkRenderer> renderer =
        vtkSmartPointer<vtkRenderer>::New();
      renderer->AddActor(actor);
      renderer->SetBackground(backgroundColor.GetData());
      renderer->ResetCamera();
      renderer->GetActiveCamera()->Azimuth(30);
      renderer->GetActiveCamera()->Elevation(30);
      renderer->GetActiveCamera()->Dolly(1.5);
      renderer->ResetCameraClippingRange();
      viewer->renderWindow()->AddRenderer(renderer);



      //vtkSmartPointer<vtkGenericOpenGLRenderWindow> renderWindow =
      //vtkSmartPointer<vtkGenericOpenGLRenderWindow>::New();
      //renderWindow->AddRenderer(renderer);
      //viewer->setRenderWindow(renderWindow);
      //vtkSmartPointer<vtkRenderWindowInteractor> renderWindowInteractor =
      //vtkSmartPointer<vtkRenderWindowInteractor>::New();
      //renderWindowInteractor->SetRenderWindow(viewer->renderWindow());
      //renderWindow->Render();
      viewer->renderWindow()->Render();
       viewer->show();
        //renderWindowInteractor->Start();*/


       //QVTKOpenGLNativeWidget widget;
        widget =new QVTKOpenGLNativeWidget();

        vtkNew<vtkNamedColors> colors;

        vtkNew<vtkGenericOpenGLRenderWindow> renderWindow;

        widget->setRenderWindow(renderWindow);
        widget->resize(600, 600);

        vtkSmartPointer<vtkOBJReader> reader =
            vtkSmartPointer<vtkOBJReader>::New();

          reader->SetFileName("D:\\Downloads\\soccer+ball\\soccer ball.obj");
          reader->Update();

        //vtkNew<vtkSphereSource> sphereSource;

          vtkSmartPointer<vtkPolyDataMapper> mapper =
            vtkSmartPointer<vtkPolyDataMapper>::New();
          mapper->SetInputConnection(reader->GetOutputPort());

          vtkSmartPointer<vtkActor> actor =
            vtkSmartPointer<vtkActor>::New();
          actor->SetMapper(mapper);



        vtkSmartPointer<vtkRenderer> renderer =
          vtkSmartPointer<vtkRenderer>::New();
        renderer->AddActor(actor);
        //renderer->SetBackground(backgroundColor.GetData());
        renderer->ResetCamera();
        renderer->GetActiveCamera()->Azimuth(30);
        renderer->GetActiveCamera()->Elevation(30);
        renderer->GetActiveCamera()->Dolly(1.5);
        renderer->ResetCameraClippingRange();
        widget->renderWindow()->AddRenderer(renderer);

        widget->renderWindow()->AddRenderer(renderer);
        widget->renderWindow()->SetWindowName("RenderWindowNoUIFile");

        this->setCentralWidget(widget);
        this->centralWidget()->setLayout(new QVBoxLayout());
        centralWidget()->layout()->addItem(titleButtonsLayout);
         //widget.show();
           QVBoxLayout* leftMenu = new QVBoxLayout(this);


    QPushButton* browseBtn = new QPushButton(tr("&Browse"));
    QLabel* fileName = new QLabel(QString(reader->GetFileName()));
    leftMenu->addWidget(browseBtn);
    leftMenu->addWidget(fileName);

    QDockWidget *dock = new QDockWidget(tr("Customers"), this);
        dock->setAllowedAreas(Qt::LeftDockWidgetArea | Qt::RightDockWidgetArea);



    fileName->setStyleSheet("QLabel { background-color : red; color : blue; }");
    connect(browseBtn,&QPushButton::clicked, this, &MainWindow::browse);

    QHBoxLayout* lay = new QHBoxLayout(dock);
    lay->addWidget(fileName);
    lay->addWidget(browseBtn);
     dock->setLayout(lay);
     addDockWidget(Qt::RightDockWidgetArea, dock);

}

void MainWindow::browse()
{
    QString fileName = QFileDialog::getOpenFileName(this, tr("Open File"),
                                                    "D://",
                                                    tr("Model (*.obj)"));

}

MainWindow::~MainWindow()
{
    //delete ui;
}

