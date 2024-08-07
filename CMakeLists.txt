cmake_minimum_required(VERSION 3.10)
project(PhotoWorkflow)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTORCC ON)

# Support for cross-compilation
if(CMAKE_SYSTEM_NAME STREQUAL "Windows")
    set(CMAKE_PREFIX_PATH $ENV{MXE_PREFIX}/qt5)
    set(Qt5_DIR $ENV{MXE_PREFIX}/qt5/lib/cmake/Qt5)
    set(BOOST_ROOT $ENV{MXE_PREFIX})
endif()

# Find required packages
find_package(Qt5 COMPONENTS Widgets REQUIRED)
find_package(OpenCV REQUIRED)
find_package(Boost REQUIRED COMPONENTS filesystem system)

include_directories(${CMAKE_SOURCE_DIR}
                    ${CMAKE_SOURCE_DIR}/gui
                    ${OpenCV_INCLUDE_DIRS}
                    ${Boost_INCLUDE_DIRS})

set(SOURCE_FILES
    main.cpp
    file_manager.cpp
    image_converter.cpp
    gui/main_window.cpp
    gui/create_job_dialog.cpp)

add_executable(PhotoWorkflow ${SOURCE_FILES})
target_link_libraries(PhotoWorkflow Qt5::Widgets ${OpenCV_LIBS} ${Boost_LIBRARIES})

# Configuration for CPack
include(InstallRequiredSystemLibraries)
set(CPACK_PACKAGE_NAME "PhotoWorkflow")
set(CPACK_PACKAGE_VERSION "1.0.0")
set(CPACK_PACKAGE_CONTACT "gennaro.mazzacane@gmail.com")
set(CPACK_PACKAGE_DESCRIPTION_SUMMARY "Photo Workflow Application")
set(CPACK_PACKAGE_VENDOR "MageSoftw")

if(WIN32)
    set(CPACK_GENERATOR "NSIS")
    set(CPACK_PACKAGE_INSTALL_DIRECTORY "PhotoWorkflow")
    set(CPACK_NSIS_MODIFY_PATH ON)
    set(CPACK_NSIS_ENABLE_UNINSTALL_BEFORE_INSTALL ON)
    set(CPACK_NSIS_DISPLAY_NAME "PhotoWorkflow")
    set(CPACK_NSIS_PACKAGE_NAME "PhotoWorkflow")
    set(CPACK_PACKAGE_EXECUTABLES "PhotoWorkflow" "PhotoWorkflow")
    set(CPACK_NSIS_MUI_ICON "${CMAKE_SOURCE_DIR}/eab290ac-4e82-479f-b62e-9fb1d759a300.ico")
    set(CPACK_NSIS_MUI_UNIICON "${CMAKE_SOURCE_DIR}/eab290ac-4e82-479f-b62e-9fb1d759a300.ico")
else()
    set(CPACK_GENERATOR "TGZ")
endif()

set(CPACK_PACKAGE_FILE_NAME "PhotoWorkflow-${CPACK_PACKAGE_VERSION}-${CMAKE_SYSTEM_NAME}")

install(TARGETS PhotoWorkflow DESTINATION bin)
install(DIRECTORY ${CMAKE_SOURCE_DIR}/gui DESTINATION include FILES_MATCHING PATTERN "*.h")

# Install Qt plugins and libraries
if(WIN32)
    include(InstallRequiredSystemLibraries)
    get_target_property(QT_QMAKE_EXECUTABLE Qt5::qmake IMPORTED_LOCATION)
    get_filename_component(QT_BIN_DIR "${QT_QMAKE_EXECUTABLE}" DIRECTORY)
    find_program(WINDEPLOYQT_EXECUTABLE windeployqt HINTS "${QT_BIN_DIR}")
    add_custom_command(TARGET PhotoWorkflow POST_BUILD
        COMMAND "${CMAKE_COMMAND}" -E env PATH="${QT_BIN_DIR}" "${WINDEPLOYQT_EXECUTABLE}" "$<TARGET_FILE:PhotoWorkflow>"
        COMMENT "Running windeployqt..."
    )
    install(DIRECTORY "$<TARGET_FILE_DIR:PhotoWorkflow>/" DESTINATION bin)
endif()

include(CPack)
