cmake_minimum_required(VERSION 3.20)

project(forensicpp)

#set(CMAKE_CXX_COMPILER clang)
set(CMAKE_CXX_FLAGS_DEBUG_INIT "-g")
set(CMAKE_CXX_STANDARD 17)
set(VERSION_STRING "0.1")

add_compile_definitions(VERSION_STRING="${VERSION_STRING}")

# Add path for custom modules
# list(APPEND CMAKE_MODULE_PATH "${CMAKE_CURRENT_SOURCE_DIR}/cmake/Modules/")

find_package(ftxui REQUIRED)
get_target_property(FTXUI_COMPONENT_INCLUDES ftxui::component INTERFACE_INCLUDE_DIRECTORIES)
get_target_property(FTXUI_DOM_INCLUDES ftxui::dom INTERFACE_INCLUDE_DIRECTORIES)
get_target_property(FTXUI_SCREEN_INCLUDES ftxui::screen INTERFACE_INCLUDE_DIRECTORIES)

set(FORENSICPP_SRCS
    ${FTXUI_COMPONENT_INCLUDES}
    ${FTXUI_DOM_INCLUDES}
    ${FTXUI_SCREEN_INCLUDES}
    # ui
    include/forensicpp/ui/etl_component.h
    include/forensicpp/ui/etl_result_component.h
    include/forensicpp/ui/main_component.h

    include/forensicpp/ui/tabs/extract/etl_extract_component.h
    include/forensicpp/ui/tabs/extract/data_source_component.h
    include/forensicpp/ui/tabs/extract/data_summary_component.h
    include/forensicpp/ui/tabs/extract/search_query_component.h

    include/forensicpp/ui/tabs/transform/etl_transform_component.h

    include/forensicpp/ui/tabs/load/etl_load_component.h

    include/forensicpp/ui/tabs/plugins/etl_plugins_component.h
    
    src/forensicpp/ui/etl_component.cc
    src/forensicpp/ui/etl_result_component.cc
    src/forensicpp/ui/main_component.cc

    src/forensicpp/ui/tabs/extract/etl_extract_component.cc
    src/forensicpp/ui/tabs/extract/data_source_component.cc
    src/forensicpp/ui/tabs/extract/data_summary_component.cc
    src/forensicpp/ui/tabs/extract/search_query_component.cc

    src/forensicpp/ui/tabs/transform/etl_transform_component.cc

    src/forensicpp/ui/tabs/load/etl_load_component.cc

    src/forensicpp/ui/tabs/plugins/etl_plugins_component.cc
    # main
    src/forensicpp/main.cc
)

add_executable(forensicpp
    ${FORENSICPP_SRCS}
)

target_include_directories(forensicpp
    PUBLIC
      $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
)

target_link_libraries(forensicpp
    ftxui::component
    ftxui::dom
    ftxui::screen
)

install(TARGETS forensicpp DESTINATION bin)