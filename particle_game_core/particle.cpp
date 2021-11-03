/**
 * @file    particle.cpp
 * @author  Martin Cagas
 *
 * @brief   Class representing a particle in the game world.
 */

#include "particle.hpp"

using namespace essentials;

Particle::Particle(void) : PhysicsObject() {}

void Particle::setup(Point2D position, Vector2D velocity)
{
    position_ = position;
    velocity_ = velocity;
}

void Particle::draw(void) const {}
