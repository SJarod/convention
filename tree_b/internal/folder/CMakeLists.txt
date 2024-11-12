set(component folder)

add_library(${component} SHARED "")

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
)
