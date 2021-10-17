## #################################### ##
## CMakeList.txt : Sources subdirectory ##
## - Include the raylib package         ##
## - Add source files using glob        ##
## - Add all aditional subdirectories   ##
## #################################### ##

cmake_minimum_required(VERSION 3.8)

# Requires at least version 3.0
find_package(raylib 3.0 CONFIG REQUIRED)

# Manually specify all.cpp sources in this directory
set(SOURCES_LIST
    main.cpp
)

# Find all matching header files in this directory
file(GLOB_RECURSE HEADERS_LIST "*.hpp")

# Add the source files to this project's executable
add_executable(${PROJECT_NAME} ${SOURCES_LIST} ${HEADERS_LIST})

# Include and link raylib
target_include_directories(${PROJECT_NAME} PRIVATE ${RAYLIB_INCLUDE_DIRS})
target_link_libraries(${PROJECT_NAME} PRIVATE ${RAYLIB_LIBRARIES})

# Link the core game logic as a library
target_link_libraries(${PROJECT_NAME} LINK_PUBLIC particle_game_core)
