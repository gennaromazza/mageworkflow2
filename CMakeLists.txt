cmake_minimum_required(VERSION 3.10)

project(PhotoWorkflow)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTORCC ON)

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
set(CPACK_PACKAGE_CONTACT "your_email@example.com")
set(CPACK_PACKAGE_DESCRIPTION_SUMMARY "Photo Workflow Application")
set(CPACK_PACKAGE_VENDOR "Your Company")
set(CPACK_PACKAGE_FILE_NAME "PhotoWorkflow-${CPACK_PACKAGE_VERSION}-win64")
set(CPACK_RESOURCE_FILE_LICENSE "${CMAKE_SOURCE_DIR}/LICENSE")
set(CPACK_RESOURCE_FILE_README "${CMAKE_SOURCE_DIR}/README.md")

install(TARGETS PhotoWorkflow DESTINATION bin)
install(DIRECTORY ${CMAKE_SOURCE_DIR}/gui DESTINATION include FILES_MATCHING PATTERN "*.h")

include(CPack)
