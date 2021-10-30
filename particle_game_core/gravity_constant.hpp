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

#pragma once

// Standard includes
#include <cstdlib>

// "Game essentials" library includes
#include <vector2d.hpp>

// Local includes
#include "physics_object.hpp"
#include "gravity_object.hpp"

class GravityConstant : GravityObject
{
public:
    /**
     * @brief   Contructor.
     */
    GravityConstant();

    /**
     * @brief   gravity_angle_ setter.
     */
    void set_gravity_angle(double new_gravity_angle);

    /**
     * @brief   gravity_angle_ getter.
     */
    double get_gravity_angle(void) const;

    /**
     * @brief   gravity_strength_ setter.
     */
    void set_gravity_strength(double new_gravity_strength);

    /**
     * @brief   gravity_strength_ getter.
     */
    double get_gravity_strength(void) const;

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
    Vector2D calculate_force(const ::PhysicsObject &to_object) const;

protected:
    double gravity_angle_;     ///< Direction of the gravity in radians. 0 means straight down.
    double gravity_strength_;  ///< Strength of the gravitational force.
};
