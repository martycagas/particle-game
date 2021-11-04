/**
 * @file    gravity_object.cpp
 * @author  Martin Cagas
 *
 * @brief   Class capable of computing its own gravitational pull on other objects.
 */

#include "gravity_object.hpp"

using namespace essentials;

GravityObject::GravityObject() : PhysicsObject(), is_enabled_(false) {}

void GravityObject::enable(void) { is_enabled_ = true; }

void GravityObject::disable(void) { is_enabled_ = false; }

bool GravityObject::get_is_enabled(void) { return is_enabled_; }

Vector2D GravityObject::calculate_force(const PhysicsObject &to_object) const
{
    if (!is_enabled_) {
        return Vector2D(0.0, 0.0);
    }
    else {
        // Simplified computation, see doxygen comments in the header file for explanation.
        double combined_mass = 0.0;
        double this_mass = mass_;
        double other_mass = to_object.get_mass();

        double distance = position_.distance_to(to_object.get_position());
        Vector2D direction = position_.direction_to(to_object.get_position());

        if (to_object.get_mass() == 0.0) {
            combined_mass == this_mass;
        }
        else if (mass_ == 0.0) {
            combined_mass == other_mass;
        }
        else {
            combined_mass = this_mass * other_mass;
        }

        if (combined_mass == 0.0) {
            return Vector2D(0.0, 0.0);
        }
        else {
            return direction * (combined_mass / (distance * distance));
        }
    }
}
