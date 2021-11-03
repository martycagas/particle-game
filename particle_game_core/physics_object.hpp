/**
 * @file    physics_object.hpp
 * @author  Martin Cagas
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
     * @brief   Empty (zero) contructor.
     *
     * Used in general for particles.
     */
    PhysicsObject(void);

    /**
     * @brief   Contructor.
     *
     * Used in general for gravity sources, emitters and other more permanent objects.
     *
     * @param   initial_position    Initial position in the 2D space.
     * @param   initial_mass        Initial mass of the object.
     */
    PhysicsObject(essentials::Point2D initial_position, double initial_mass);

    /**
     * @brief   position_ setter.
     */
    void set_position(essentials::Point2D position);

    /**
     * @brief   position_ getter.
     */
    essentials::Point2D get_position(void) const;

    /**
     * @brief   velocity_ setter.
     */
    void set_velocity(essentials::Point2D velocity);

    /**
     * @brief   velocity_ getter.
     */
    essentials::Point2D get_velocity(void) const;

    /**
     * @brief   mass_ setter.
     */
    void set_mass(double mass);

    /**
     * @brief   mass_ getter.
     */
    double get_mass(void) const;

    /**
     * @brief   Iterates over a list of vectors of forces and sums them up with the velocity.
     *
     * @param   forces          The list of forces to integrate.
     */
    void integrate_forces(std::vector<essentials::Vector2D> forces);

    /**
     * @brief   Updates the PhysicsObject's position using its current velocity.
     */
    void update(void);

protected:
    essentials::Point2D position_;   ///< Position in the game world's 2D space.
    essentials::Vector2D velocity_;  ///< Velocity in the game world's 2D space.
    double mass_;                    ///< Mass for the gravitational force calculation.
};
