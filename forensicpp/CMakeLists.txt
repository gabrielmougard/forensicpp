cmake_minimum_required(VERSION 3.20)

project(forensicpp)

set(CMAKE_CXX_STANDARD 17)
set(VERSION_STRING "0.1")

add_compile_definitions(VERSION_STRING="${VERSION_STRING}")

# Add path for custom modules
# list(APPEND CMAKE_MODULE_PATH "${CMAKE_CURRENT_SOURCE_DIR}/cmake/Modules/")

find_package(Qt6Widgets REQUIRED)
find_package(Qt6Core REQUIRED)

# Automatic call to UIC compiler to generate header files for .ui descriptions.
qt_standard_project_setup()
set(forensicpp_QRC src/resources/forensicpp.qrc)
qt6_add_resources(FORENSICPP_QRC_SOURCES ${forensicpp_QRC})


set(FORENSICPP_HEADERS
    src/macosapp.h
)

set(FORENSICPP_SRCS
    src/macosapp.cc
    src/main.cc
)

add_executable(forensicpp MODULE
    ${FORENSICPP_HEADERS}
    ${FORENSICPP_SRCS}
    ${FORENSICPP_QRC_SOURCES}
)

target_link_libraries(forensicpp
    Qt6::Widgets
)

install(TARGETS forensicpp DESTINATION bin)