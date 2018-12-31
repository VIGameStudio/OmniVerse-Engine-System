cmake_minimum_required(VERSION 3.2)

project(OVE_System)
set(${PROJECT_NAME}_MAJOR_VERSION 0)
set(${PROJECT_NAME}_MINOR_VERSION 1)
set(${PROJECT_NAME}_REVISION_VERSION 1)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11 -Wall")

find_package(OpenGL REQUIRED)
find_package(X11 REQUIRED)

add_subdirectory(extern)
include_directories(src)

add_library(ove_system SHARED
    # System
    src/ove/system/fileio.hpp
    src/ove/system/fileio.cpp
    src/ove/system/window.hpp
    src/ove/system/window.cpp
    src/ove/system/x11/x11_window.hpp
    src/ove/system/x11/x11_window.cpp
    src/ove/system/xcb/xcb_window.hpp
    src/ove/system/xcb/xcb_window.cpp
)
target_link_libraries(ove_system ${X11_LIBRARY} ${OPENGL_LIBRARY})

add_executable(demo demo/main.cpp)
target_link_libraries(demo ove_system)

enable_testing()

add_executable(_test test/_test.cpp)
add_test(A_test _test)
target_link_libraries(_test ove_system)
