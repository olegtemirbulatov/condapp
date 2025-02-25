cmake_minimum_required(VERSION 3.5)

project(condapp VERSION 0.1 LANGUAGES CXX)

set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_INCLUDE_CURRENT_DIR ON)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(QT NAMES Qt5 REQUIRED COMPONENTS Widgets)
find_package(Qt5 REQUIRED COMPONENTS Widgets)
add_definitions(${Qt5Widgets_DEFINITIONS})
set(CMAKE_CXX_FLAGS "${Qt5Widgets_EXECUTABLE_COMPILE_FLAGS}")

set(PROJECT_SOURCES
        main.cpp
        userwindow.cpp
        measurementsimulator.cpp
        recounthelper.cpp
        stylehelper.cpp
        userwindow.h
        measurementsimulator.h
        recounthelper.h
        stylehelper.h
)

qt5_add_resources(RSC resources.qrc)

add_executable(${PROJECT_NAME} ${PROJECT_SOURCES} ${RSC})
target_include_directories(${PROJECT_NAME} PRIVATE ${Qt5Widgets_INCLUDES})
target_link_libraries(${PROJECT_NAME} PRIVATE Qt5::Widgets)
