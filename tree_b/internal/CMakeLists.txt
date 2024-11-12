set(component internal)

add_library(${component} SHARED "")

set_property(TARGET ${component}
    PROPERTY PUBLIC_HEADER
    class.hpp # headers that are made public
)

target_sources(${component}
    PRIVATE
    class.cpp # source
    class.hpp # header that are kept private
)

target_link_libraries(${component}
    PUBLIC lib1_build_name
    PUBLIC lib2_build_name
    PRIVATE lib3_build_name
)

target_include_directories(${component} PRIVATE "${CMAKE_CURRENT_LIST_DIR}")
target_include_directories(${component} PUBLIC "${CMAKE_CURRENT_LIST_DIR}/..")

add_subdirectory(folder)