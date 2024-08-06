cmake_minimum_required(VERSION 3.16)

project(PhotoWorkflow)

set(CMAKE_CXX_STANDARD 14)

# Specifica i percorsi delle librerie
set(OpenCV_DIR "C:/opencv/build")
set(BOOST_ROOT "C:/boost")
set(CMAKE_PREFIX_PATH "C:/Qt/5.12.2/gcc_64")

# Trova i pacchetti richiesti
find_package(Qt5 COMPONENTS Core Gui Widgets REQUIRED)
find_package(OpenCV REQUIRED)
find_package(Boost REQUIRED COMPONENTS filesystem system)

# Includi le directory
include_directories(${OpenCV_INCLUDE_DIRS} ${Boost_INCLUDE_DIRS})

# Aggiungi i file sorgente
add_executable(PhotoWorkflow 
    main.cpp 
    file_manager.cpp 
    image_converter.cpp 
    gui/main_window.cpp
    gui/create_job_dialog.cpp
)

# Collega le librerie
target_link_libraries(PhotoWorkflow Qt5::Core Qt5::Gui Qt5::Widgets ${OpenCV_LIBS} ${Boost_LIBRARIES})
