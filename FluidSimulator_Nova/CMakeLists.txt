add_executable(fluidsimulator-Nova
    main.cpp
)

add_executable(unitTest-Nova
    unitTest.cpp
)

target_link_libraries(fluidsimulator-Nova
    PRIVATE
    nova::tools
    nova::geometry
)

target_link_libraries(unitTest-Nova
    PRIVATE
    nova::tools
    nova::geometry
)


file(RELATIVE_PATH REL ${PROJECT_SOURCE_DIR} ${CMAKE_CURRENT_SOURCE_DIR})
 
install(TARGETS fluidsimulator-Nova RUNTIME DESTINATION ${REL})

## Build-in Libraries
find_package(OpenGL)
find_package(GLUT)
include_directories( ${OPENGL_INCLUDE_DIRS}  ${GLUT_INCLUDE_DIRS})

target_link_libraries(fluidsimulator-Nova
    PRIVATE
    ${OPENGL_gl_LIBRARY}
    ${OPENGL_glu_LIBRARY}
    ${GLUT_LIBRARIES})
