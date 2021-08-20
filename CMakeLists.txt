cmake_minimum_required(VERSION 3.0)
project(graphics_engine)

find_package(OpenGL REQUIRED)

include_directories(include)

add_executable(window_test src/Display.cpp)
target_link_libraries(window_test ${OPENGL_LIBRARY})