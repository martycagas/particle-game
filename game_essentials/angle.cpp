/**
 * @file    angle.cpp
 * @author  Martin Cagas
 *
 * @brief   An angle with conversion functions.
 */

#include "angle.hpp"

using namespace essentials;

Angle::Angle(void) : radians_(0.0) {}

Angle::Angle(double degrees) : radians_(deg_to_rad(degrees)) {}

void Angle::set_from_radians(double radians) { radians_ = radians; }

double Angle::get_as_radians(void) const { return radians_; }

void Angle::set_from_degrees(double degrees) { radians_ = deg_to_rad(degrees); }

double Angle::get_as_degrees(void) const { return rad_to_deg(radians_); }

inline double Angle::rad_to_deg(double radians) { return radians * (180.0 / M_PI); }

inline double Angle::deg_to_rad(double degrees) { return degrees * (M_PI / 180.0); }
