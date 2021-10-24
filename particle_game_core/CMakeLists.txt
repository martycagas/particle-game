## ####################################################### ##
## CMakeList.txt : particle game core library subdirectory ##
## - Find sources and add them to the library              ##
## - Make the library link-able in the project             ##
## ####################################################### ##

cmake_minimum_required(VERSION 3.8)

# Manually specify all.cpp sources in this directory
set(SOURCES_LIST
    emitter.cpp
    particle.cpp
    physics_object.cpp
    world.cpp
)

# Find all matching header files in this directory
file(GLOB_RECURSE HEADERS_LIST "*.hpp")

# Add all specified source files to the library
add_library(particle_game_core ${SOURCES_LIST} ${HEADERS_LIST})

# Link the game essentials library
target_link_libraries(particle_game_core LINK_PUBLIC game_essentials)

# Ensure the library is discoverable in the project
target_include_directories(particle_game_core PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})
