cmake_minimum_required(VERSION 3.10)

project(PhotoWorkflow)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTORCC ON)

find_package(Qt5 COMPONENTS Widgets REQUIRED)
find_package(OpenCV REQUIRED)
find_package(Boost REQUIRED filesystem system)

include_directories(${Qt5Widgets_INCLUDE_DIRS} ${OpenCV_INCLUDE_DIRS} ${Boost_INCLUDE_DIRS})

set(SOURCE_FILES
    main.cpp
    file_manager.cpp
    image_converter.cpp
    gui/main_window.cpp
    gui/create_job_dialog.cpp
)

add_executable(PhotoWorkflow ${SOURCE_FILES})

target_link_libraries(PhotoWorkflow Qt5::Widgets ${OpenCV_LIBS} ${Boost_LIBRARIES})
