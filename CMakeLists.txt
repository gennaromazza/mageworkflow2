cmake_minimum_required(VERSION 3.10)
project(PhotoWorkflow)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_AUTOUIC ON)

find_package(Qt5 REQUIRED COMPONENTS Core Gui Widgets)
find_package(OpenCV REQUIRED)
find_package(Boost REQUIRED COMPONENTS filesystem system)

include_directories(${Qt5Widgets_INCLUDE_DIRS} ${OpenCV_INCLUDE_DIRS} ${Boost_INCLUDE_DIRS})
include_directories(${CMAKE_SOURCE_DIR})  # Include la directory principale
include_directories(${CMAKE_SOURCE_DIR}/gui)  # Include la directory gui
include_directories(${CMAKE_BINARY_DIR})  # Include la directory di build per i file UI generati

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

set(UI_FILES
    gui/main_window.ui
)

add_executable(PhotoWorkflow ${SOURCE_FILES} ${HEADER_FILES} ${UI_FILES})

target_link_libraries(PhotoWorkflow Qt5::Core Qt5::Gui Qt5::Widgets ${OpenCV_LIBS} ${Boost_LIBRARIES})
