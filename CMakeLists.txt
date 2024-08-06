cmake_minimum_required(VERSION 3.10)

project(PhotoWorkflow)

set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTORCC ON)

find_package(Qt5 COMPONENTS Widgets REQUIRED)
find_package(OpenCV REQUIRED)
find_package(Boost COMPONENTS filesystem system REQUIRED)

set(SOURCE_FILES
    main.cpp
    file_manager.cpp
    image_converter.cpp
    gui/main_window.cpp
    gui/create_job_dialog.cpp
)

add_executable(PhotoWorkflow ${SOURCE_FILES})

target_include_directories(PhotoWorkflow PRIVATE
    ${CMAKE_CURRENT_SOURCE_DIR}
    ${CMAKE_CURRENT_SOURCE_DIR}/gui
)

target_link_libraries(PhotoWorkflow PRIVATE
    Qt5::Widgets
    ${OpenCV_LIBS}
    Boost::filesystem
    Boost::system
)
