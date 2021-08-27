cmake_minimum_required(VERSION 3.2)
project(graphics_engine)

find_package(OpenGL REQUIRED)
find_package(glfw3 REQUIRED)
find_package(Threads REQUIRED)
find_package(GLEW REQUIRED)

add_definitions(-DGLEW_STATIC)

include_directories(include)

set(LIBS
    ${OPENGL_LIBRARIES}
    glfw3
    dl 
    Threads::Threads 
    ${GLEW_LIBRARIES}
)

set(SOURCES
    src/Display.cpp
)

add_executable(projection_test src/projection_test.cpp ${SOURCES})
target_link_libraries(projection_test ${LIBS})
