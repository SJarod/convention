set(component test)

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


# build events
add_custom_command(TARGET ${component}
    POST_BUILD
    COMMAND
)


# installing build (using cmake --install command)
install(TARGETS ${component})
# installing the include files
install(
    DIRECTORY internal/
    DESTINATION include
    FILES_MATCHING
    PATTERN *.h
    PATTERN *.hpp
    PATTERN *.inl
)
