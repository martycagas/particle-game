/**
 * @file    world.hpp
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

#pragma once

#include <cstdlib>
#include <vector>

/**
 * @brief   Class representing the contents of the game world.
 */
class World
{
public:
    enum class Directions
    {
        DIRECTION_TOP = 0,
        DIRECTION_BOTTOM,
        DIRECTION_LEFT,
        DIRECTION_RIGHT
    };

    /**
     * @brief   Contructor.
     */
    World(void);

    /**
     * @brief   particle_limit_ setter.
     */
    void set_particle_limit(std::size_t new_particle_limit);

    /**
     * @brief   particle_limit getter.
     */
    std::size_t get_particle_limit();

private:
    std::size_t particle_limit_;  ///< The maximum amount of particles allowed at one time.
};
