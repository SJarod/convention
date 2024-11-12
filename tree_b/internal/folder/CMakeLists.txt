set(component folder)

add_library(${component} STATIC "")

set_property(TARGET ${component}
    PROPERTY PUBLIC_HEADER
    class2.hpp
)

target_sources(${component}
    PRIVATE
    class2.cpp
    class2.hpp
)

target_link_libraries(${component}
    PUBLIC lib1_build_name
    PUBLIC lib2_build_name
    PRIVATE lib3_build_name
)

target_include_directories(${component} PRIVATE "${CMAKE_CURRENT_LIST_DIR}")
target_include_directories(${component} PUBLIC "${CMAKE_CURRENT_LIST_DIR}/..")