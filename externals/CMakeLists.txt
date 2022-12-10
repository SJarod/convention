# externals' CMakeLists

# adding an external CMake based library
set(OPTION1_NAME ON)	# optional or depending on the library
set(OPTION2_NAME OFF)	# optional or depending on the library
add_subdirectory(lib_directory_name)

# adding a library from sources (interface library)
add_library(lib_build_name INTERFACE)
target_sources(lib_build_name INTERFACE
	filename.hpp
	filename.cpp
)
target_include_directories(lib_build_name INTERFACE lib_directory/include)