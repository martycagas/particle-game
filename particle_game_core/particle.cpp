/**
 * @file    particle.cpp
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

#include "particle.hpp"

Particle::Particle(void) : PhysicsObject() {}

void Particle::setup(Point2D new_position, Vector2D new_velocity)
{
    position_ = new_position;
    velocity_ = new_velocity;
}

void Particle::draw(void) const {}
