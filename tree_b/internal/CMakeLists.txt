set(component internal)

add_executable(${component})

target_sources(${component}
    PRIVATE
    class.cpp
)

add_subdirectory(folder)