/**
 * @file    gravity_object.cpp
 * @author  Martin Cagas
 * @date    2021-10-17
 *
 * @brief   Class representing a "source" of gravity in the game world.
 *
 * @section DESCRIPTION
 *
 * A part of a particle simulation game, this class derives PhysicsObject and provides a method for
 * physics calculation.
 */

#include "gravity_object.hpp"

GravityObject::GravityObject() : PhysicsObject(), is_enabled_(true) {}

void GravityObject::enable(void) { is_enabled_ = true; }

void GravityObject::disable(void) { is_enabled_ = false; }

bool GravityObject::get_is_enabled(void) { return is_enabled_; }

Vector2D GravityObject::calculate_force(PhysicsObject &to_object) const
{
    if (!is_enabled_) {
        return Vector2D(0, 0);
    }
    else {
        // Simplified computation, see doxygen comments in the header file for explanation.
        double combined_mass = 0;
        double this_mass = mass_;
        double other_mass = to_object.get_mass();

        double distance = position_.distance_to(to_object.get_position());
        Vector2D direction = position_.direction_to(to_object.get_position());

        if (to_object.get_mass() == 0) {
            combined_mass == this_mass;
        }
        else if (mass_ == 0) {
            combined_mass == other_mass;
        }
        else {
            combined_mass = this_mass * other_mass;
        }

        if (combined_mass == 0) {
            return Vector2D(0, 0);
        }
        else {
            return direction * (combined_mass / (distance * distance));
        }
    }
}
