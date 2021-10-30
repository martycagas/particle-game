/**
 * @file    gravity_constant.hpp
 * @author  Martin Cagas
 * @date    2021-10-29
 *
 * @brief   Class representing a constant gravitational force in the game world.
 *
 * @section DESCRIPTION
 *
 * A part of a particle simulation game, this class derives GravityObject. The gravitational force
 * caluculation method is overriden with a method returning a constant vector (i.e. this
 * GravityObject exerts the exact same force on all other objects).
 */

#include "gravity_constant.hpp"

GravityConstant::GravityConstant() : GravityObject() {}

void GravityConstant::set_gravity_angle(double new_gravity_angle)
{
    gravity_angle_ = new_gravity_angle;
}

double GravityConstant::get_gravity_angle(void) const { return gravity_angle_; }

void GravityConstant::set_gravity_strength(double new_gravity_strength)
{
    gravity_strength_ = new_gravity_strength;
}

double GravityConstant::get_gravity_strength(void) const { return gravity_strength_; }

Vector2D GravityConstant::calculate_force(const ::PhysicsObject &to_object) const
{
    Vector2D ret = Vector2D(0, 1);
    return ret * gravity_strength_;
}
