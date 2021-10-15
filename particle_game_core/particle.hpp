/**
 * @file    particle.hpp
 * @author  Martin Cagas
 * @date    2021-10-01
 *
 * @brief   Class representing a particle in the game world.
 *
 * @section DESCRIPTION
 *
 * A part of a particle simulation game, this a base class for all particles in the system.
 *
 * A particle needs to implement following features:
 * - Define the particle's type and features.
 * - Implement a way of drawing said particle.
 * - Keep track and update particle's speed and position.
 * - Handle interactions with other particles in the game world.
 */

#pragma once

#include <cstdlib>

/**
 * @brief   Class representing a particle in the game world.
 */
class Particle
{
public:
    /**
     * @brief   Contructor.
     */
    Particle();

    /**
     * @brief   Deconstructor.
     */
    ~Particle();

private:
    
};
