project(TestTaskDI LANGUAGES CXX)

set(VTK_DIR "C:\\Program Files (x86)\\VTK")
find_package(VTK REQUIRED)
include_directories(SYSTEM ${VTK_INCLUDE_DIRS})
include(${VTK_USE_FILE})

set(CMAKE_INCLUDE_CURRENT_DIR ON)

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

set(CMAKE_CXX_STANDARD 11)
set(CAKE_CXX_STANDARD_REQUIRED ON)

find_package(QT NAMES Qt6 Qt5 COMPONENTS Widgets REQUIRED)
find_package(Qt${QT_VERSION_MAJOR} COMPONENTS Widgets REQUIRED)


add_executable(TestTaskDI
    main.cpp  
    qwinwidget.cpp
    qwinwidget.h
    widget.cpp
    widget.h
    winnativewindow.cpp
    winnativewindow.h
    leftmenu.cpp
    leftmenu.h
    resources/icons.qrc
)


target_link_libraries(TestTaskDI PRIVATE Qt${QT_VERSION_MAJOR}::Widgets ${VTK_LIBRARIES})
