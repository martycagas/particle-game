/**
 * @file    physics_object.hpp
 * @author  Martin Cagas
 * @date    2021-10-23
 *
 * @brief   Base class for representing any physics object in the game world.
 *
 * @section DESCRIPTION
 *
 * A part of a particle simulation game, this base class represents a physics object.
 *
 * Base class for a physics object. Has following properties:
 * - Position, its getter and setter
 * - Velocity, its getter and setter
 * - Mass, its getter and setter
 */

#pragma once

// Standard includes
#include <cstdlib>
#include <vector>

// "Game essentials" library includes
#include <vector2d.hpp>

class PhysicsObject
{
public:
    /**
     * @brief   Contructor.
     *
     * @param   initial_position    Initial position in the 2D space.
     * @param   initial_mass        Initial mass of the object.
     */
    PhysicsObject(Point2D initial_position, double initial_mass);

    /**
     * @brief   Default deconstructor.
     */
    ~PhysicsObject();

    /**
     * @brief   position_ setter.
     */
    void set_position(Point2D new_position);

    /**
     * @brief   position_ getter.
     */
    Point2D get_position(void) const;

    /**
     * @brief   velocity_ setter.
     */
    void set_velocity(Point2D new_velocity);

    /**
     * @brief   velocity_ getter.
     */
    Point2D get_velocity(void) const;

    /**
     * @brief   mass_ setter.
     */
    void set_mass(double new_mass);

    /**
     * @brief   mass_ getter.
     */
    double get_mass(void) const;

    /**
     * @brief   Iterates over a list of vectors of forces and sums them up with the velocity.
     *
     * @param   forces          The list of forces to integrate.
     */
    void integrate_forces(std::vector<Vector2D> forces);

protected:
    Point2D position_;   ///< Position in the game world's 2D space.
    Vector2D velocity_;  ///< Velocity in the game world's 2D space.
    double mass_;        ///< Mass for the gravitational force calculation.
};
