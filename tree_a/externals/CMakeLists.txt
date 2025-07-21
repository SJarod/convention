# externals' CMakeLists

# adding an external library based on CMake
set(OPTION1_NAME ON)	# optional or depending on the library
set(OPTION2_NAME OFF)	# optional or depending on the library
add_subdirectory(lib_directory_name)

# adding a library from sources (interface library)
# only header files, no source files
add_library(lib_build_name INTERFACE)
target_sources(lib_build_name INTERFACE
	filename.hpp
	filename.cpp
)
target_include_directories(lib_build_name INTERFACE lib_directory/include)

# adding a pre compiled static/shared library (interface)
# https://cmake.org/cmake/help/latest/command/add_library.html#imported-libraries
add_library(target_name SHARED IMPORTED GLOBAL)
set_target_properties(target_name PROPERTIES
	LINKER_LANGUAGE CXX
 	IMPORTED_IMPLIP_DEBUG path_to_libd.lib
  	IMPORTED_IMPLIB_RELEASE path_to_lib.lib
   	IMPORTED_LOCATION_DEBUG path_to_libd.dll
    	IMPORTED_LOCATION_RELEASE path_to_lib.dll
     	MAP_IMPORTED_CONFIG_MINSIZEREL Release
      	MAP_IMPORTED_CONFIG_RELWITHDEBINFO Release
)
target_include_directories(target_name INTERFACE "dir")
target_link_directories(target_name INTERFACE "dir")
# may require changing workspace directory (cwd, pwd) regarding the IDE
configure_file(path_to_lib.dll ${CMAKE_BINARY_DIR}/path_to_lib.dll COPYONLY)
# for install
install(FILES path_to_lib.dll TYPE BIN)
