cmake_minimum_required(VERSION 3.0.2 FATAL_ERROR)

project(ooview)

set(PROJECT_LONGNAME "OceanOptics Spectrometer Viewer")
set(PROJECT_VERSION "0.1")

set(CMAKE_INCLUDE_CURRENT_DIR ON)
set(CMAKE_AUTOMOC ON)

find_package(Qt5Widgets REQUIRED)
find_package(Qt5PrintSupport REQUIRED) # required for QCustomPlot

# UI_HEADERS
# add ui files
file(GLOB_RECURSE UI_FILES *.ui)

qt5_wrap_ui(UI_HEADERS ${UI_FILES})

# CODE_FILES
file(GLOB_RECURSE CODE_FILES src/*.cpp)

# EXTERN_FILES
# Include directories
include_directories(extern/qcustomplot)

# CPP Files
set(QCUSTOMPLOT_FILES extern/qcustomplot/qcustomplot.cpp)

# Add everything to EXTERN_FILES
list(APPEND EXTERN_FILES ${QCUSTOMPLOT_FILES})

add_executable(${CMAKE_PROJECT_NAME} WIN32
    ${UI_HEADERS}
    ${CODE_FILES}
    ${EXTERN_FILES}
    ${RESOURCE_FILES}
    ${WINDOWS_RES_FILE}
)

target_link_libraries(${CMAKE_PROJECT_NAME}
    Qt5::Widgets
    Qt5::PrintSupport
)
