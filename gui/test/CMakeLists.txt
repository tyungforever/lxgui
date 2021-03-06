set(SRCROOT ${PROJECT_SOURCE_DIR}/gui/test)
include_directories(${PROJECT_SOURCE_DIR}/include)
include_directories(${SFML_INCLUDE_DIR})
include_directories(${LUA_INCLUDE_DIR})
include_directories(${FREETYPE_INCLUDE_DIRS})
include_directories(${PNG_INCLUDE_DIR})
include_directories(${ZLIB_INCLUDE_DIR})
include_directories(${GLEW_INCLUDE_DIR})
include_directories(${OPENGL_INCLUDE_DIR})

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${PROJECT_SOURCE_DIR}/gui/test/bin)

add_executable(lxgui-test
    ${SRCROOT}/main.cpp
)

target_link_libraries(lxgui-test lxgui-gl)
target_link_libraries(lxgui-test lxgui-input-sfml)
target_link_libraries(lxgui-test lxgui)
target_link_libraries(lxgui-test lxgui-luapp)
target_link_libraries(lxgui-test lxgui-xml)
target_link_libraries(lxgui-test lxgui-utils)
target_link_libraries(lxgui-test ${LUA_LIBRARY})
target_link_libraries(lxgui-test ${FREETYPE_LIBRARY})
target_link_libraries(lxgui-test ${PNG_LIBRARY})
target_link_libraries(lxgui-test ${ZLIB_LIBRARY})
target_link_libraries(lxgui-test ${SFML_WINDOW_LIBRARY})
target_link_libraries(lxgui-test ${SFML_SYSTEM_LIBRARY})
target_link_libraries(lxgui-test ${GLEW_LIBRARY})
target_link_libraries(lxgui-test ${OPENGL_LIBRARY})

if(WINDOWS AND MSVC)
    target_link_libraries(lxgui-test user32)
endif()
