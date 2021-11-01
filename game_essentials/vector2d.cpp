/**
 * @file    vector2d.cpp
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

Vector2D::Vector2D(void) : x(0), y(0) {}

Vector2D::Vector2D(double new_x, double new_y) : x(new_x), y(new_y) {}

inline double &Vector2D::operator[](int index) { return (index == 0) ? x : y; }

inline const double &Vector2D::operator[](int index) const { return (index == 0) ? x : y; }

inline Vector2D Vector2D::operator+(const Vector2D &rvalue) const
{
    return Vector2D(x + rvalue.x, y + rvalue.y);
}

inline void Vector2D::operator+=(const Vector2D &rvalue)
{
    x += rvalue.x;
    y += rvalue.y;
}

inline Vector2D Vector2D::operator-(const Vector2D &rvalue) const
{
    return Vector2D(x - rvalue.x, y - rvalue.y);
}

inline void Vector2D::operator-=(const Vector2D &rvalue)
{
    x -= rvalue.x;
    y -= rvalue.y;
}

inline Vector2D Vector2D::operator*(const Vector2D &rvalue) const
{
    return Vector2D(x * rvalue.x, y * rvalue.y);
}

inline Vector2D Vector2D::operator*(const double &rvalue) const
{
    return Vector2D(x * rvalue, y * rvalue);
}

inline void Vector2D::operator*=(const Vector2D &rvalue)
{
    x *= rvalue.x;
    y *= rvalue.y;
}

inline void Vector2D::operator*=(const double &rvalue)
{
    x *= rvalue;
    y *= rvalue;
}

inline Vector2D Vector2D::operator/(const Vector2D &rvalue) const
{
    return Vector2D(x / rvalue.x, y / rvalue.y);
}

inline Vector2D Vector2D::operator/(const double &rvalue) const
{
    return Vector2D(x / rvalue, y / rvalue);
}

inline void Vector2D::operator/=(const Vector2D &rvalue)
{
    x *= rvalue.x;
    y *= rvalue.y;
}

inline void Vector2D::operator/=(const double &rvalue)
{
    x *= rvalue;
    y *= rvalue;
}

inline Vector2D Vector2D::operator-(void) const { return Vector2D(-x, -y); }

inline bool Vector2D::operator==(const Vector2D &rvalue) const
{
    return (x == rvalue.x && y == rvalue.y);
}

inline bool Vector2D::operator!=(const Vector2D &rvalue) const
{
    return (x != rvalue.x || y != rvalue.y);
}

inline bool Vector2D::operator<(const Vector2D &rvalue) const
{
    return x == rvalue.x ? (y < rvalue.y) : (x < rvalue.x);
}

inline bool Vector2D::operator>(const Vector2D &rvalue) const
{
    return x == rvalue.x ? (y > rvalue.y) : (x > rvalue.x);
}

inline bool Vector2D::operator<=(const Vector2D &rvalue) const
{
    return x == rvalue.x ? (y <= rvalue.y) : (x < rvalue.x);
}

inline bool Vector2D::operator>=(const Vector2D &rvalue) const
{
    return x == rvalue.x ? (y >= rvalue.y) : (x > rvalue.x);
}

inline int Vector2D::min_axis(void) const { return x < y ? 0 : 1; }

inline int Vector2D::max_axis(void) const { return x < y ? 1 : 0; }

double Vector2D::length(void) const { return std::sqrt(x * x + y * y); }

double Vector2D::length_squared(void) const { return (x * x + y * y); }

double Vector2D::angle(void) const { return std::atan2(y, x); }

void Vector2D::normalize(void)
{
    double l = x * x + y * y;
    if (l != 0) {
        l = std::sqrt(l);
        x /= l;
        y /= l;
    }
}

Vector2D Vector2D::normalized(void) const
{
    Vector2D v = *this;
    v.normalize();
    return v;
}

double Vector2D::dot(const Vector2D &other_vector) const
{
    return x * other_vector.x + y * other_vector.y;
}

double Vector2D::cross(const Vector2D &other_vector) const
{
    return x * other_vector.y - y * other_vector.x;
}

double Vector2D::angle_formed_by(const Vector2D &other_vector) const
{
    return std::atan2(cross(other_vector), dot(other_vector));
}

double Vector2D::angle_to_point(const Point2D &other_point) const
{
    return (*this - other_point).angle();
}

double Vector2D::distance_to(const Point2D &other_point) const
{
    Vector2D ret(other_point.x - x, other_point.y - y);
    return ret.length();
}

Vector2D Vector2D::direction_to(const Point2D &other_point) const
{
    Vector2D ret(other_point.x - x, other_point.y - y);
    ret.normalize();
    return ret;
}
