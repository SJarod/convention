set(component folder)

add_executable(${component})

target_sources(${component}
    PRIVATE
    class2.cpp
)