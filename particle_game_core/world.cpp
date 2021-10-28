/**
 * @file    world.cpp
 * @author  Martin Cagas
 * @date    2021-09-30
 *
 * @brief   Class representing the contents of the game world.
 *
 * @section DESCRIPTION
 *
 * A part of a particle simulation game, this class represents the game world.
 *
 * A game world has following functions:
 * - Keep the constraints and state of the simulation world.
 * - Keep track of objects in the world.
 */

#include "world.hpp"

World::World(void) : particle_limit_(1000) {}

void World::set_particle_limit(std::size_t new_particle_limit)
{
    particle_limit_ = new_particle_limit;
}

std::size_t World::get_particle_limit() { return particle_limit_; }
