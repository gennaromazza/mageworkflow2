cmake_minimum_required(VERSION 3.10)

project(PhotoWorkflow)

set(CMAKE_CXX_STANDARD 17)

find_package(Qt5 REQUIRED COMPONENTS Core Gui Widgets)
find_package(OpenCV REQUIRED)
find_package(Boost REQUIRED COMPONENTS filesystem system)

include_directories(${Qt5Widgets_INCLUDE_DIRS} ${OpenCV_INCLUDE_DIRS} ${Boost_INCLUDE_DIRS})
add_definitions(${Qt5Widgets_DEFINITIONS})

set(SOURCE_FILES
    main.cpp
    file_manager.cpp
    image_converter.cpp
    gui/main_window.cpp
    gui/create_job_dialog.cpp
)

set(HEADER_FILES
    file_manager.h
    image_converter.h
    gui/main_window.h
    gui/create_job_dialog.h
)

add_executable(PhotoWorkflow ${SOURCE_FILES} ${HEADER_FILES})

target_link_libraries(PhotoWorkflow Qt5::Core Qt5::Gui Qt5::Widgets ${OpenCV_LIBS} ${Boost_LIBRARIES})
