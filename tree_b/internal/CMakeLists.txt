set(component internal)

add_executable(${component})

set_property(TARGET ${component}
    PROPERTY PUBLIC_HEADER
    class.hpp # headers that are made public
)

target_sources(${component}
    PRIVATE
    class.cpp # source
    class.hpp # header that are kept private
)

add_subdirectory(folder)