/**
 * @file    gravity_constant.cpp
 * @author  Martin Cagas
 *
 * @brief   Class exerting the same gravitational pull on all objects.
 */

#include "gravity_constant.hpp"

using namespace essentials;

GravityConstant::GravityConstant(void)
    : GravityObject(Vector2D(0.0, 0.0)), gravity_angle_(270.0), gravity_strength_(10.0)
{
}

void GravityConstant::set_gravity_angle_from_rad(double gravity_rad_angle)
{
    gravity_angle_.set_from_radians(gravity_rad_angle);
}

void GravityConstant::set_gravity_angle_from_deg(double gravity_deg_angle)
{
    gravity_angle_.set_from_degrees(gravity_deg_angle);
}

double GravityConstant::get_gravity_angle_as_rad(void) const
{
    return gravity_angle_.get_as_radians();
}

double GravityConstant::get_gravity_angle_as_deg(void) const
{
    return gravity_angle_.get_as_degrees();
}

void GravityConstant::set_gravity_strength(double gravity_strength)
{
    gravity_strength_ = gravity_strength;
}

double GravityConstant::get_gravity_strength(void) const { return gravity_strength_; }

Vector2D GravityConstant::calculate_force(const PhysicsObject &to_object) const
{
    Vector2D ret = Vector2D();
    ret.set_from_angle(gravity_angle_.get_as_radians());
    return ret * gravity_strength_;
}
