/**
 * @file    physics_object.hpp
 * @author  Martin Cagas
 * @date    2021-10-23
 *
 * @brief   Base class for representing any physics object in the game world.
 *
 * @section DESCRIPTION
 *
 * A part of a particle simulation game, this base class represents a physics object.
 *
 * Base class for a physics object. Has following properties:
 * - Position, its getter and setter
 * - Velocity, its getter and setter
 * - Mass, its getter and setter
 */

#include "physics_object.hpp"

PhysicsObject::PhysicsObject(Point2D initial_position, double initial_mass)
    : position_(initial_position), velocity_(0), mass_(initial_mass)
{
}

PhysicsObject::~PhysicsObject() = default;

void PhysicsObject::set_position(Point2D new_position) { position_ = new_position; }

Point2D PhysicsObject::get_position(void) const { return position_; }

void PhysicsObject::set_velocity(Point2D new_velocity) { velocity_ = new_velocity; }

Point2D PhysicsObject::get_velocity(void) const { return velocity_; }

void PhysicsObject::set_mass(double new_mass) { mass_ = new_mass; }

double PhysicsObject::get_mass(void) const { return mass_; }
