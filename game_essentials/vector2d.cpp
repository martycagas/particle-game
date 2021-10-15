/**
 * @file    math_vector.cpp
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

#include "vector2d.hpp"

/*
 * Empty contructor.
 */
Vector2D::Vector2D() : x(0), y(0) {}

/*
 * Identical components contructor.
 */
Vector2D::Vector2D(double new_x_y) : x(new_x_y), y(new_x_y) {}

/*
 * Parametrised constructor.
 */
Vector2D::Vector2D(double new_x, double new_y) : x(new_x), y(new_y) {}

/*
 * Default deconstructor.
 */
Vector2D::~Vector2D() = default;

/*
 * The subscript operator.
 */
inline double &Vector2D::operator[](int index) { return (index == 0) ? x : y; }

/*
 * The constant subscript operator.
 */
inline const double &Vector2D::operator[](int index) const { return (index == 0) ? x : y; }

/*
 * The addition operator.
 */
inline Vector2D Vector2D::operator+(const Vector2D &rvalue) const
{
    return Vector2D(x + rvalue.x, y + rvalue.y);
}

/*
 * The addition assignment operator.
 */
inline void Vector2D::operator+=(const Vector2D &rvalue)
{
    x += rvalue.x;
    y += rvalue.y;
}

/*
 * The subtraction operator.
 */
inline Vector2D Vector2D::operator-(const Vector2D &rvalue) const
{
    return Vector2D(x - rvalue.x, y - rvalue.y);
}

/*
 * The subtraction assignment operator.
 */
inline void Vector2D::operator-=(const Vector2D &rvalue)
{
    x -= rvalue.x;
    y -= rvalue.y;
}

/*
 * The vector multiplication operator.
 */
inline Vector2D Vector2D::operator*(const Vector2D &rvalue) const
{
    return Vector2D(x * rvalue.x, y * rvalue.y);
}

/*
 * The scalar multiplication operator.
 */
inline Vector2D Vector2D::operator*(const double &rvalue) const
{
    return Vector2D(x * rvalue, y * rvalue);
}

/*
 * The vector multiplication assignment operator.
 */
inline void Vector2D::operator*=(const Vector2D &rvalue)
{
    x *= rvalue.x;
    y *= rvalue.y;
}

/*
 * The scalar multiplication assignment operator.
 */
inline void Vector2D::operator*=(const double &rvalue)
{
    x *= rvalue;
    y *= rvalue;
}

/*
 * The vector division operator.
 */
inline Vector2D Vector2D::operator/(const Vector2D &rvalue) const
{
    return Vector2D(x / rvalue.x, y / rvalue.y);
}

/*
 * The scalar division operator.
 */
inline Vector2D Vector2D::operator/(const double &rvalue) const
{
    return Vector2D(x / rvalue, y / rvalue);
}

/*
 * The vector division assignment operator.
 */
inline void Vector2D::operator/=(const Vector2D &rvalue)
{
    x *= rvalue.x;
    y *= rvalue.y;
}

/*
 * The scalar division assignment operator.
 */
inline void Vector2D::operator/=(const double &rvalue)
{
    x *= rvalue;
    y *= rvalue;
}

/*
 * The unary negation operator.
 */
inline Vector2D Vector2D::operator-() const { return Vector2D(-x, -y); }

/*
 * The "equal to" operator.
 */
inline bool Vector2D::operator==(const Vector2D &rvalue) const
{
    return (x == rvalue.x && y == rvalue.y);
}

/*
 * The "not equal to" operator.
 */
inline bool Vector2D::operator!=(const Vector2D &rvalue) const
{
    return (x != rvalue.x || y != rvalue.y);
}

/*
 * The "less than" operator.
 */
inline bool Vector2D::operator<(const Vector2D &rvalue) const
{
    return x == rvalue.x ? (y < rvalue.y) : (x < rvalue.x);
}

/*
 * The "greater than" operator.
 */
inline bool Vector2D::operator>(const Vector2D &rvalue) const
{
    return x == rvalue.x ? (y > rvalue.y) : (x > rvalue.x);
}

/*
 * The "less or equal than" operator.
 */
inline bool Vector2D::operator<=(const Vector2D &rvalue) const
{
    return x == rvalue.x ? (y <= rvalue.y) : (x < rvalue.x);
}

/*
 * The "greater or equal than" operator.
 */
inline bool Vector2D::operator>=(const Vector2D &rvalue) const
{
    return x == rvalue.x ? (y >= rvalue.y) : (x > rvalue.x);
}

/*
 * Returns the axis with the lower value.
 */
inline int Vector2D::min_axis() const { return x < y ? 0 : 1; }

/*
 * Returns the axis with the greater value.
 */
inline int Vector2D::max_axis() const { return x < y ? 1 : 0; }

/*
 * Normalises the vector in-place.
 */
void Vector2D::normalize()
{
    double l = x * x + y * y;
    if (l != 0) {
        l = std::sqrt(l);
        x /= l;
        y /= l;
    }
}

/*
 * Returns a new vector that has values of the normalised original vector.
 */
Vector2D Vector2D::normalized() const
{
    Vector2D v = *this;
    v.normalize();
    return v;
}
