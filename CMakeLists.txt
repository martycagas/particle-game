## ######################################################################### ##
## CMakeList.txt : Top-level CMake project file                              ##
## - Define project                                                          ##
## - Define global requirements (build type, standard, compile options, ...) ##
## - Add the src subdirectory                                                ##
## ######################################################################### ##

cmake_minimum_required(VERSION 3.8)

project("particle-game" VERSION 0.1)

# Set CMake project build type to release if not set
if(NOT CMAKE_BUILD_TYPE)
    set(CMAKE_BUILD_TYPE Debug)
endif()

# Set the minimal language level
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# Add general compile options
add_compile_options(-Wall)

# Add compile options specific to the release and debug builds
set(CMAKE_CXX_FLAGS_DEBUG   "${CMAKE_CXX_FLAGS_DEBUG} -DDEBUG")
set(CMAKE_CXX_FLAGS_RELEASE "${CMAKE_CXX_FLAGS_RELEASE} -O3")

# Add the sources subdirectory
add_subdirectory(src)

# Add the tests subdirectory
#add_subdirectory(tests)
