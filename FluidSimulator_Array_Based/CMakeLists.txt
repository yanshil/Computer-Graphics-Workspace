cmake_minimum_required (VERSION 2.8.11)

project(Fluid-ArrayBased)

add_executable(Fluid-ArrayBased ${SRC} "main.cpp")
add_executable(unitTest ${SRC} "unitTest.cpp")


## Build-in Libraries
find_package(OpenGL)
find_package(GLUT)
include_directories( ${OPENGL_INCLUDE_DIRS}  ${GLUT_INCLUDE_DIRS})

target_link_libraries(Fluid-ArrayBased
    PRIVATE
    ${OPENGL_gl_LIBRARY}
    ${OPENGL_glu_LIBRARY}
    ${GLUT_LIBRARIES})
