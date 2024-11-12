set(component ${BUILD_NAME})

add_executable(${component})

target_sources(${component}
    PRIVATE
    main.cpp
)

target_link_libraries(${component}
    PUBLIC lib1_build_name
    PUBLIC lib2_build_name
    PRIVATE lib3_build_name
)