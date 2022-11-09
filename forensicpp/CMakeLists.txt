cmake_minimum_required(VERSION 3.20)

project(forensicpp)

set(CMAKE_CXX_STANDARD 17)
set(VERSION_STRING "0.1")

add_compile_definitions(VERSION_STRING="${VERSION_STRING}")

# Add path for custom modules
# list(APPEND CMAKE_MODULE_PATH "${CMAKE_CURRENT_SOURCE_DIR}/cmake/Modules/")

find_package(ftxui REQUIRED)
get_target_property(FTXUI_COMPONENT_INCLUDES ftxui::component INTERFACE_INCLUDE_DIRECTORIES)
get_target_property(FTXUI_DOM_INCLUDES ftxui::dom INTERFACE_INCLUDE_DIRECTORIES)
get_target_property(FTXUI_SCREEN_INCLUDES ftxui::screen INTERFACE_INCLUDE_DIRECTORIES)

set(FORENSICPP_HEADERS
    ${FTXUI_COMPONENT_INCLUDES}
    ${FTXUI_DOM_INCLUDES}
    ${FTXUI_SCREEN_INCLUDES}
    src/color_info_sorted_2d.h
)

set(FORENSICPP_SRCS
    src/main.cc
)

add_executable(forensicpp
    ${FORENSICPP_HEADERS}
    ${FORENSICPP_SRCS}
)

target_link_libraries(forensicpp
    ftxui::component
    ftxui::dom
    ftxui::screen
)

install(TARGETS forensicpp DESTINATION bin)