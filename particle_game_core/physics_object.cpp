/**
 * @file    physics_object.cpp
 * @author  Martin Cagas
 *
 * @brief   Base class for any physics-enabled object.
 */

#include "physics_object.hpp"

using namespace essentials;

PhysicsObject::PhysicsObject(void) : position_(0.0, 0.0), velocity_(0.0, 0.0), mass_(0.0) {}

PhysicsObject::PhysicsObject(Point2D initial_position, double initial_mass)
    : position_(initial_position), velocity_(0.0, 0.0), mass_(initial_mass)
{
}

void PhysicsObject::set_position(Point2D position) { position_ = position; }

Point2D PhysicsObject::get_position(void) const { return position_; }

void PhysicsObject::set_velocity(Point2D velocity) { velocity_ = velocity; }

Point2D PhysicsObject::get_velocity(void) const { return velocity_; }

void PhysicsObject::set_mass(double mass) { mass_ = mass; }

double PhysicsObject::get_mass(void) const { return mass_; }

void PhysicsObject::integrate_forces(std::vector<Vector2D> forces)
{
    for (Vector2D force : forces) {
        velocity_ += force;
    }
}

void PhysicsObject::update(void) { position_ += velocity_; }
