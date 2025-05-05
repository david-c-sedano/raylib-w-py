cmake_minimum_required(VERSION 3.15)
project(raylib_w_py C)
add_subdirectory(vendor/raylib)

add_library(raylib_w_py MODULE 
    src/raylibwpy/raylib_w_py.c
    src/raylibwpy/modules/rcore_w_py.c
    src/raylibwpy/modules/rtext_w_py.c
    src/raylibwpy/modules/rstructs_w_py.c
)

target_link_libraries(raylib_w_py PRIVATE raylib)
find_package(Python3 REQUIRED COMPONENTS Interpreter Development)
target_include_directories(raylib_w_py PRIVATE ${Python3_INCLUDE_DIRS})
target_link_libraries(raylib_w_py PRIVATE ${Python3_LIBRARIES})

foreach(OUTPUT IN LISTS CMAKE_CONFIGURATION_TYPES)
    string(TOUPPER "${OUTPUT}" OUTPUT_UPPER)
    set_target_properties(raylib_w_py PROPERTIES
        LIBRARY_OUTPUT_DIRECTORY_${OUTPUT_UPPER} "${CMAKE_CURRENT_SOURCE_DIR}/src/raylibwpy"
    )
endforeach()

set_target_properties(raylib_w_py PROPERTIES
    PREFIX ""
    SUFFIX ".pyd"
    OUTPUT_NAME "raylibwpy"
)