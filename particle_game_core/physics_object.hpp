/**
 * @file    physics_object.hpp
 * @author  Martin Cagas
 *
 * @brief   Base class for any physics-enabled object.
 */

#pragma once

// Standard includes
#include <cstdlib>
#include <vector>

// "Game essentials" library includes
#include <vector2d.hpp>

/**
 * @class   PhysicsObject
 *
 * @brief   Base class for any physics-enabled object.
 *
 * @section DESCRIPTION
 *
 * Has following properties:
 * - position
 * - velocity
 * - mass
 *
 * Has following methods:
 * - integrate_forces()
 * - update()
 *
 * @section USAGE
 *
 * This class isn't intended to be used directly, instead it serves as a base class for other
 * objects in the game world.
 */
class PhysicsObject
{
public:
    /**
     * @brief   Empty (zero) contructor.
     *
     * @details
     *
     * Initializes the position, velocity and mass to zero.
     *
     * Generally used when creating particles.
     *
     * @see    Particle::Particle()
     */
    PhysicsObject(void);

    /**
     * @brief   Position-only constructor.
     *
     * @details
     *
     * Initializes the position to the parameter and the velocity and mass to zero.
     *
     * Generally used when creating emitters.
     *
     * @see     Emitter::Emitter()
     *
     * @param   position    Initial position.
     */
    PhysicsObject(essentials::Vector2D position);

    /**
     * @brief   Contructor.
     *
     * @details
     *
     * Initializes the position and velocity to the parameters and the mass to zero.
     *
     * Generally used when creating gravity sources.
     *
     * @see     GravitySource::GravitySource()
     *
     * @param   position    Initial position.
     * @param   mass        Initial mass.
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
