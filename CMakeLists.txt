cmake_minimum_required(VERSION 3.13)
project(rrts)

set(CMAKE_CXX_STANDARD 17)

file(COPY ${CMAKE_CURRENT_SOURCE_DIR}/project/resources/
        DESTINATION ${CMAKE_CURRENT_BINARY_DIR}/.)

# temp - will change to sets when finished development
file(GLOB_RECURSE SRCS project/main/source/*.cpp)
file(GLOB_RECURSE HDRS project/main/include/*.h)
file(GLOB_RECURSE TST project/main/test/*.hpp)

file(GLOB_RECURSE BACK_SRCS project/backend/source/*.cpp)
file(GLOB_RECURSE BACK_HDRS project/backend/include/*.h)
file(GLOB_RECURSE BACK_TST project/backend/test/*.hpp)

set(STB_SRC lib/stb/stb_image.h)


if(EMSCRIPTEN)
    # Disabled - just output js file
#    set(CMAKE_EXECUTABLE_SUFFIX ".html")
    #set(CMAKE_CXX_FLAGS  "${CMAKE_CXX_FLAGS} --shell-file '${CMAKE_SOURCE_DIR}/project/web/www/index.html' ${GCC_COVERAGE_COMPILE_FLAGS}")
    file(COPY ${CMAKE_CURRENT_SOURCE_DIR}/project/web/www/ DESTINATION ${CMAKE_CURRENT_BINARY_DIR}/.)

    set(CMAKE_CXX_FLAGS  "${CMAKE_CXX_FLAGS} --preload-file '${CMAKE_SOURCE_DIR}/project/resources@/' -s USE_GLFW=3 -s WASM=1 -s GL_DEBUG=1 -s GL_ASSERTIONS=1 -s USE_WEBGL2=1 -s FULL_ES2=1 -s FULL_ES3=1 ${GCC_COVERAGE_COMPILE_FLAGS}")
endif()

include_directories(project/main/include)
include_directories(project/backend/include)
include_directories(lib/glm/glm)
include_directories(lib/stb)

add_executable(${PROJECT_NAME}_main project/main/main.cpp ${STB_SRC} ${SRCS} ${HDRS} ${BACK_SRCS} ${BACK_HDRS})

if(NOT EMSCRIPTEN)
    add_subdirectory(lib/googletest)
    add_subdirectory(lib/glfw)
    add_subdirectory(lib/glm)

    include_directories(lib/googletest/googletest/include)
    include_directories(lib/googletest/googlemock/include)
    include_directories(lib/glfw/include)

    link_directories(lib/googletest)
    link_directories(lib/glfw)
    link_directories(lib/glm)

    add_executable(backend_test ${BACK_TST} project/backend/main_test.cpp ${BACK_SRCS} ${BACK_HDRS})
    target_link_libraries(backend_test gtest gtest_main)

    add_executable(${PROJECT_NAME}_test ${TST} ${STB_SRC} project/main/main_test.cpp ${SRCS} ${HDRS})
    target_link_libraries(${PROJECT_NAME}_test gtest gtest_main)
endif()

target_link_libraries(${PROJECT_NAME}_main glfw GLEW GL GLU)
