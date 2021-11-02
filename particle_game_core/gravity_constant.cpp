/**
 * @file    gravity_constant.hpp
 * @author  Martin Cagas
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

using namespace essentials;

GravityConstant::GravityConstant()
    : GravityObject(), gravity_angle_(deg_to_rad(270)), gravity_strength_(10)
{
}

void GravityConstant::set_gravity_angle(double new_gravity_angle)
{
    gravity_angle_ = new_gravity_angle;
}

void GravityConstant::set_gravity_angle_from_deg(double new_gravity_deg_angle)
{
    gravity_angle_ = deg_to_rad(new_gravity_deg_angle);
}

double GravityConstant::get_gravity_angle(void) const { return gravity_angle_; }

double GravityConstant::get_gravity_angle_as_deg(void) const { return rad_to_deg(gravity_angle_); }

void GravityConstant::set_gravity_strength(double new_gravity_strength)
{
    gravity_strength_ = new_gravity_strength;
}

double GravityConstant::get_gravity_strength(void) const { return gravity_strength_; }

Vector2D GravityConstant::calculate_force(const PhysicsObject &to_object) const
{
    Vector2D ret = Vector2D();
    ret.set_from_angle(gravity_angle_);
    return ret * gravity_strength_;
}

inline double GravityConstant::rad_to_deg(double radians) { return radians * (180.0 / M_PI); }

inline double GravityConstant::deg_to_rad(double degrees) { return degrees * (M_PI / 180.0); }
