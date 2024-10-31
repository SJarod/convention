set(component ${BUILD_NAME})

add_executable(${component})

target_sources(${component}
    PRIVATE
    main.cpp
)
