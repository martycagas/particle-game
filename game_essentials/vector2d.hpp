/**
 * @file    vector2d.hpp
 * @author  Martin Cagas
 * @date    2021-10-03

 * An mathematical 2D vector.
 *
 * @section DESCRIPTION
 *
 * A class representing a two-dimensional, mathematical vector with all the features that are
 * required for a game, such as adding, multiplyingand normalising vectors.
 *
 * @section ATTRIBUTION
 *
 * This library contains pieces of code and ideas taken from the Godot Engine's implementation of
 * the Vector2 class, licensed under the following license:
 *
 * Copyright (c) 2007-2021 Juan Linietsky, Ariel Manzur.
 * Copyright (c) 2014-2021 Godot Engine contributors.
 *
 * Permission is hereby granted, free of charge, to any person obtaining
 * a copy of this software and associated documentation files (the
 * "Software"), to deal in the Software without restriction, including
 * without limitation the rights to use, copy, modify, merge, publish,
 * distribute, sublicense, and/or sell copies of the Software, and to
 * permit persons to whom the Software is furnished to do so, subject to
 * the following conditions:
 *
 * The above copyright notice and this permission notice shall be
 * included in all copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND,
 * EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF
 * MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT
 * IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY
 * CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT,
 * TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION WITH THE
 * SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.
 */

#pragma once

#include <cmath>
#include <cstdlib>

struct Vector2D
{
    /**
     * @brief   A set of anonymous unions and structures that hold the vector data.
     *
     * Initialised to [0; 0].
     */
    union
    {
        struct
        {
            union
            {
                double x;      ///< The X component. Alternate name for width.
                double width;  ///< The width component. Alternate name for X.
            };
            union
            {
                double y;       ///< The Y component. Alternate name for height.
                double height;  ///< The height component. Alternate name for Y.
            };
        };
        double coord[2] = {0};  ///< Both components as an array.
    };

    /**
     * @brief   Empty contructor. Creates a [0; 0] vector.
     */
    Vector2D(void);

    /**
     * @brief   Arbitrary components constructor.
     *
     * @param   new_x       Value to which to initialise the X axis.
     * @param   new_y       Value to which to initialise the Y axis.
     */
    Vector2D(double new_x, double new_y);

    /**
     * @brief   The subscript operator.
     */
    inline double &operator[](int index);

    /**
     * @brief   The constant subscript operator.
     */
    inline const double &operator[](int index) const;

    /**
     * @brief   The addition operator.
     */
    inline Vector2D operator+(const Vector2D &rvalue) const;

    /**
     * @brief   The addition assignment operator.
     */
    inline void operator+=(const Vector2D &rvalue);

    /**
     * @brief   The subtraction operator.
     */
    inline Vector2D operator-(const Vector2D &rvalue) const;

    /**
     * @brief   The subtraction assignment operator.
     */
    inline void operator-=(const Vector2D &rvalue);

    /**
     * @brief   The vector multiplication operator.
     */
    inline Vector2D operator*(const Vector2D &rvalue) const;

    /**
     * @brief   The scalar multiplication operator.
     */
    inline Vector2D operator*(const double &rvalue) const;

    /**
     * @brief   The vector multiplication assignment operator.
     */
    inline void operator*=(const Vector2D &rvalue);

    /**
     * @brief   The scalar multiplication assignment operator.
     */
    inline void operator*=(const double &rvalue);

    /**
     * @brief   The vector division operator.
     */
    inline Vector2D operator/(const Vector2D &rvalue) const;

    /**
     * @brief   The scalar division operator.
     */
    inline Vector2D operator/(const double &rvalue) const;

    /**
     * @brief   The vector division assignment operator.
     */
    inline void operator/=(const Vector2D &rvalue);

    /**
     * @brief   The scalar division assignment operator.
     */
    inline void operator/=(const double &rvalue);

    /**
     * @brief   The unary negation operator.
     */
    inline Vector2D operator-(void) const;

    /**
     * @brief   The "equal to" operator.
     */
    inline bool operator==(const Vector2D &rvalue) const;

    /**
     * @brief   The "not equal to" operator.
     */
    inline bool operator!=(const Vector2D &rvalue) const;

    /**
     * @brief   The "less than" operator.
     */
    inline bool operator<(const Vector2D &rvalue) const;

    /**
     * @brief   The "greater than" operator.
     */
    inline bool operator>(const Vector2D &rvalue) const;

    /**
     * @brief   The "less or equal than" operator.
     */
    inline bool operator<=(const Vector2D &rvalue) const;

    /**
     * @brief   The "greater or equal than" operator.
     */
    inline bool operator>=(const Vector2D &rvalue) const;

    /**
     * @brief   Returns the axis with the lower value.
     *
     * @return  The axis with the lower value.
     */
    inline int min_axis(void) const;

    /**
     * @brief   Returns the axis with the greater value.
     *
     * @return  The axis with the greater value.
     */
    inline int max_axis(void) const;

    /**
     * @brief   Returns the length of this vector.
     *
     * @return  The length.
     */
    double length(void) const;

    /**
     * @brief   Returns the length of this vector, squared.
     *
     * @return  The length.
     */
    double length_squared(void) const;

    /**
     * @brief   Returns the dot product between this vector and other_vector.
     *
     * @param   other_vector    The second vector used to calculate the dot product.
     *
     * @return  Dot product.
     */
    double dot(const Vector2D &other_vector) const;

    /**
     * @brief   Returns the cross product between this vector and other_vector.
     *
     * @param   other_vector    The second vector used to calculate the cross product.
     *
     * @return  Cross product.
     */
    double cross(const Vector2D &other_vector) const;

    /**
     * @brief   Returns this vector's angle with respect to the positive X axis, or [1; 0] vector,
     * in radians.
     *
     * @return  Angle in radians.
     */
    double angle(void) const;

    /**
     * @brief   Returns the angle in radians formed by two rays defined by this vector and the
     * other_vector.
     *
     * @param   other_vector    Vector used to construct the second ray.
     *
     * @return  Angle in radians.
     */
    double angle_formed_by(const Vector2D &other_vector) const;

    /**
     * @brief   Returns the angle in radians between the line connecting the two points and the X
     * axis.
     *
     * @param   other_point     The second point used to construct the line.
     *
     * @return  Angle in radians.
     */
    double angle_to_point(const Point2D &other_point) const;

    /**
     * @brief   Returns the distance to another point.
     *
     * @param   other_point     The second point used to calculate distance.
     *
     * @return  Returns the distance.
     */
    double distance_to(const Point2D &other_point) const;

    /**
     * @brief   Returns the normalised vector pointing from this point (a) to the other point (b).
     * This is equivalent to using (b - a).normalized().
     *
     * @param   other_point     The second point used in determining the direction.
     *
     * @return  Returns the normalised vector that is the direction to the other_point.
     */
    Vector2D direction_to(const Point2D &other_point) const;

    /**
     * @brief   Normalises the vector in-place.
     */
    void normalize(void);

    /**
     * @brief   Returns a new vector that has values of the normalised original vector.
     *
     * @return  New instance of the vector with normalised axes.
     */
    Vector2D normalized(void) const;
};

/**
 * @brief   Alternate name for the Vector2D class.
 */
typedef Vector2D Size2D;

/**
 * @brief   Alternate name for the Vector2D class.
 */
typedef Vector2D Point2D;
