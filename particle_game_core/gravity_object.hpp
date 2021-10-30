/**
 * @file    gravity_object.hpp
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

#pragma once

// Standard includes
#include <cstdlib>

// "Game essentials" library includes
#include <vector2d.hpp>

// Local includes
#include "physics_object.hpp"

class GravityObject : PhysicsObject
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
     * The computation itself is very simplified. In real world, there is an observed relation
     * between mass and gravitational force that is described by the gravitational constant. In this
     * system, we're already hitting the wall when the mass of any object is arbitrary. Therefore,
     * the gravitational force is only determined by the mass(es) and the distance in our case.
     *
     * @param   &to_object      A reference to the other object.
     *
     * @return  Vector2D representing the gravitational force.
     */
    virtual Vector2D calculate_force(const PhysicsObject &to_object) const;

protected:
    bool is_enabled_;  ///< Flag defining whether the gravity object is active.
};
