set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTORCC ON)

find_package(Qt5 COMPONENTS Widgets REQUIRED)

set(SOURCE_FILES
    main.cpp
    file_manager.cpp
    image_converter.cpp
    gui/main_window.cpp
    gui/create_job_dialog.cpp
)

set(UI_FILES
    gui/create_job_dialog.ui
)

qt5_wrap_ui(UI_HEADERS ${UI_FILES})

add_executable(PhotoWorkflow ${SOURCE_FILES} ${UI_HEADERS})

target_link_libraries(PhotoWorkflow Qt5::Widgets)
