cmake_minimum_required(VERSION 3.10)

project(PhotoWorkflow)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_PREFIX_PATH "/opt/Qt/5.12.2/gcc_64/lib/cmake/Qt5")

find_package(Qt5 COMPONENTS Core Gui Widgets REQUIRED)
find_package(OpenCV REQUIRED)
find_package(Boost COMPONENTS filesystem system REQUIRED)

add_executable(PhotoWorkflow
    main.cpp
    file_manager.cpp
    file_manager.h
    image_converter.cpp
    image_converter.h
    gui/main_window.cpp
    gui/main_window.h
    gui/create_job_dialog.cpp
    gui/create_job_dialog.h
)

target_link_libraries(PhotoWorkflow
    Qt5::Core
    Qt5::Gui
    Qt5::Widgets
    ${OpenCV_LIBS}
    Boost::filesystem
    Boost::system
)
