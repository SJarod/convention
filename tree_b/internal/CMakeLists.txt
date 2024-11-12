set(component internal)

add_library(${component} STATIC "")

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
    PUBLIC folder
)

target_include_directories(${component} PRIVATE "${CMAKE_CURRENT_LIST_DIR}")
target_include_directories(${component} PUBLIC "${CMAKE_CURRENT_LIST_DIR}/..")

add_subdirectory(folder)