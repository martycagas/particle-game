/**
 * @file    gravity_object.hpp
 * @author  Martin Cagas
 *
 * @brief   Class capable of computing its own gravitational pull on other objects.
 */

#pragma once

// Standard includes
#include <cstdlib>

// "Game essentials" library includes
#include <vector2d.hpp>

// Local includes
#include "physics_object.hpp"

/**
 * @class   GravityObject
 *
 * @brief   Class capable of computing its own gravitational pull on other objects.
 *
 * @section DESCRIPTION
 *
 * A part of a particle simulation game, this class derives PhysicsObject and provides a method for
 * gravitational force calculation exerted on other objects.
 *
 * @section USAGE
 *
 * @code
 *
 * GravityObject gravity_object();
 *
 * gravity_object.set_position(Vector2D(10.0, 20.0));
 * gravity_object.set_mass(10.0);
 * gravity_object.enable();
 *
 * @endcode
 */
class GravityObject : public PhysicsObject
{
public:
    /**
     * @brief   Contructor.
     */
    GravityObject();

    /**
     * @brief   Enables the gravity object by setting is_enabled_ to true.
     */
    void enable(void);

    /**
     * @brief   Disables the gravity object by setting is_enabled_ to false.
     */
    void disable(void);

    /**
     * @brief   Returns true if the gravity object is enabled, false otherwise.
     */
    bool get_is_enabled(void);

    /**
     * @brief   Calculates the gravitational force exerted on another object.
     *
     * @details
     *
     * The computation itself is very simplified. In real world, there is an observed relation
     * between mass and gravitational force that is described by the gravitational constant. In this
     * system, we're already hitting the wall when the mass of any object is arbitrary. Therefore,
     * the gravitational force is only determined by the mass(es) and the distance in our case.
     *
     * @param   &to_object      A reference to the other object.
     *
     * @return  Vector2D representing the gravitational force.
     */
    virtual essentials::Vector2D calculate_force(const PhysicsObject &to_object) const;

protected:
    bool is_enabled_;  ///< True if the gravity object is enabled, false otherwise.
};
