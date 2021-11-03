/**
 * @file    world.cpp
 * @author  Martin Cagas
 *
 * @brief   Class representing the contents of the game world.
 */

#include "world.hpp"

World::World(void) : particle_limit_(1000) {}

void World::set_particle_limit(std::size_t particle_limit)
{
    particle_limit_ = particle_limit;
}

std::size_t World::get_particle_limit() { return particle_limit_; }
