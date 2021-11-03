/**
 * @file    angle.hpp
 * @author  Martin Cagas
 *
 * An angle with conversion functions.
 *
 * @section DESCRIPTION
 *
 * A class both capable of representing an angle and providing conversion methods between radians
 * and degrees.
 */

#pragma once

#define _USE_MATH_DEFINES
#include <cmath>
#include <cstdlib>

namespace essentials
{
    /**
     * @class   Angle
     *
     * @brief   A class both capable of representing an angle and providing conversion methods
     * between radians and degrees.
     *
     * @details
     *
     * An angle with conversion functions.
     *
     * @section USAGE
     *
     * @code
     *
     * Angle angle(0.0);
     *
     * angle.set_from_radians(M_PI_2);
     *
     * angle.get_as_radians();
     *
     * angle.set_from_degrees(90.0);
     *
     * angle.get_as_degrees();
     *
     * @endcode
     */
    struct Angle
    {
        double radians_;  ///< The angle in radians.

        /**
         * @brief Constructor.
         *
         * @details
         *
         * Initializes the angle to 0.0.
         */
        Angle(void);

        /**
         * @brief   Constructs an angle from degrees.
         *
         * @note    The decision to construct the angle from degrees was made because in games and
         * real life, it is more common to input degrees as angles, as opposed to radians. This
         * makes it easier for the programmer to quickly input a rotation in code.
         *
         * @param   degrees     The angle in degrees.
         */
        Angle(double degrees);

        /**
         * @brief   Sets the angle from radians.
         *
         * @param   radians     The angle in radians.
         */
        void set_from_radians(double radians);

        /**
         * @brief   Returns the angle in radians.
         *
         * @return  The angle in radians.
         */
        double get_as_radians(void);

        /**
         * @brief   Sets the angle from degrees.
         *
         * @param   degrees     The angle in degrees.
         */
        void set_from_degrees(double degrees);

        /**
         * @brief   Returns the angle in degrees.
         *
         * @return  The angle in degrees.
         */
        double get_as_degrees(void);

        /**
         * @brief   Converts angle from radians to degrees.
         *
         * @param   Input angle in radians.
         *
         * @return  Output angle in degrees.
         */
        static inline double rad_to_deg(double radians);

        /**
         * @brief   Converts angle from degrees to radians.
         *
         * @param   Input angle in degrees.
         *
         * @return  Output angle in radians.
         */
        static inline double deg_to_rad(double degrees);
    };
}  // namespace essentials
