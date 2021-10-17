/**
 * @file    math_vector.hpp
 * @author  Martin Cagas
 * @date    2021-10-03
 *
 * @brief   An mathematical 2D vector.
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

class Vector2D
{
public:
    /**
     * @brief   Constant representing the number of axes of this vector.
     */
    static constexpr std::size_t AXIS_COUNT = 2;

    /**
     * @brief   Enumeration type for clearly distinguishing the individual axes.
     */
    enum class AXES
    {
        AXIS_X = 0,
        AXIS_Y
    };

    /**
     * @brief   A set of anonymous unions and structures that hold the value data.
     */
    union
    {
        struct
        {
            union
            {
                double x;
                double width;
            };
            union
            {
                double y;
                double height;
            };
        };
        double coord[2] = {0};
    };

    /**
     * @brief   Empty contructor.
     */
    Vector2D();

    /**
     * @brief   Identical components contructor.
     *
     * @param   new_x_y     Value to which to initialise both axes.
     */
    Vector2D(double new_x_y);

    /**
     * @brief   Arbitrary components constructor.
     *
     * @param   new_x       Value to which to initialise the X axis.
     * @param   new_y       Value to which to initialise the Y axis.
     */
    Vector2D(double new_x, double new_y);

    /**
     * @brief   Default deconstructor.
     */
    ~Vector2D();

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
    inline Vector2D operator-() const;

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
    inline int min_axis() const;

    /**
     * @brief   Returns the axis with the greater value.
     *
     * @return  The axis with the greater value.
     */
    inline int max_axis() const;

    /**
     * @brief   Normalises the vector in-place.
     */
    void normalize();

    /**
     * @brief   Returns a new vector that has values of the normalised original vector.
     *
     * @return  New instance of the vector with normalised axes.
     */
    Vector2D normalized() const;
};

/**
 * @brief   Alternate name for the Vector2D class.
 */
typedef Vector2D Size2D;

/**
 * @brief   Alternate name for the Vector2D class.
 */
typedef Vector2D Point2D;
