/**
 * @file    gravity_constant.hpp
 * @author  Martin Cagas
 *
 * @brief   Class exerting the same gravitational pull on all objects.
 */

#pragma once

// Standard includes
#define _USE_MATH_DEFINES
#include <cmath>
#include <cstdlib>

// "Game essentials" library includes
#include <angle.hpp>
#include <vector2d.hpp>

// Local includes
#include "gravity_object.hpp"

/**
 * @class   GravityConstant
 *
 * @brief   Class exerting the same gravitational pull on all objects.
 *
 * @section DESCRIPTION
 *
 * This class derives from GravityObject. The gravitational force caluculation method is overriden
 * with a method returning a constant vector (i.e. this GravityObject exerts the exact same force on
 * all other objects).
 *
 * @section USAGE
 *
 * @code
 *
 * @endcode
 */
class GravityConstant : public GravityObject
{
public:
    /**
     * @brief   Contructor.
     *
     * @details
     *
     * Initialises the angle to 270 degrees - i.e. "straight down".
     *
     * Initialises the strength to 10.0.
     */
    GravityConstant(void);

    /**
     * @brief   gravity_angle_ setter.
     *
     * @param   New angle in radians.
     */
    void set_gravity_angle_from_rad(double gravity_rad_angle);

    /**
     * @brief   Alternate gravity_angle_ setter.
     *
     * @param   New angle in degrees.
     */
    void set_gravity_angle_from_deg(double gravity_deg_angle);

    /**
     * @brief   gravity_angle_ getter.
     *
     * @return  Gravity angle in radians.
     */
    double get_gravity_angle_as_rad(void) const;

    /**
     * @brief   Alternate gravity_angle_ getter.
     *
     * @return  Gravity angle in degrees.
     */
    double get_gravity_angle_as_deg(void) const;

    /**
     * @brief   gravity_strength_ setter.
     */
    void set_gravity_strength(double gravity_strength);

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
    essentials::Vector2D calculate_force(const PhysicsObject &to_object) const;

protected:
    essentials::Angle gravity_angle_;  ///< Direction of the gravity in radians.
    double gravity_strength_;          ///< Strength of the gravitational force.
};
