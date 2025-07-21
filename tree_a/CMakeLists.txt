# CMake version
cmake_minimum_required(VERSION 3.21)

# C++ standard version
set(CMAKE_CXX_STANDARD 20)

set(PROJECT_NAME project_name)
set(BUILD_NAME build_name) # executable or library

# initiating project given its name
project(${PROJECT_NAME})

# using the external libraries in the ./externals directory
add_subdirectory(externals)

# defining every header files in a variable named HEADERS
set(HEADERS
    include/filename.hpp
)

# defining every source files in a variable named SOURCES
set(SOURCES
    src/main.cpp

    src/filename.cpp
)


# define a definition macro in the entire project
add_compile_definitions(MY_MACRO)


# project's result (choose between executable or static library)
add_executable(${BUILD_NAME} ${HEADERS} ${SOURCES})
add_library(${BUILD_NAME} STATIC ${SOURCES})

# defining include directory for the project (./include directory)
target_include_directories(${BUILD_NAME} PRIVATE include)

# using external libraries (optional)
# the libraries should be added in the externals' CMakeLists
target_link_libraries(${BUILD_NAME}
    PUBLIC lib1_build_name
    PUBLIC lib2_build_name
)


# build events
add_custom_command(TARGET ${BUILD_NAME}
    POST_BUILD
    COMMAND
)


# installing build (using cmake --install command)
install(TARGETS ${BUILD_NAME})
# installing the include files
install(
    DIRECTORY include/
    TYPE INCLUDE
    FILES_MATCHING
    PATTERN *.h
    PATTERN *.hpp
    PATTERN *.inl
)
