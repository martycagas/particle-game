/**
 * @file    particle.hpp
 * @author  Martin Cagas
 *
 * @brief   Class representing a particle in the game world.
 *
 * @section DESCRIPTION
 *
 * A part of a particle simulation game, this a base class for all particles in the system.
 *
 * A particle needs to implement following features:
 * - Define the particle's type and features
 * - Implement a way of drawing said particle
 */

#pragma once

// Standard includes
#include <cstdlib>
#include <vector>

// vcpkg includes
#include <raylib.h>

// "Game essentials" library includes
#include <vector2d.hpp>

// Local includes
#include "physics_object.hpp"

/**
 * @brief   Class representing a particle in the game world.
 */
class Particle : public PhysicsObject
{
public:
    /**
     * @brief   Contructor.
     *
     * There is no reason to attempt to initialise anything in the contructor for now, because this
     * object will be pooled. That means creating a large amount of instances ahead of the time and
     * reusing them as needed.
     */
    Particle(void);

    /**
     * @brief   Sets a new state to the particle.
     */
    void setup(essentials::Point2D position, essentials::Vector2D velocity);

    /**
     * @brief   Draws the particle on screen.
     */
    void draw(void) const;

private:
};
