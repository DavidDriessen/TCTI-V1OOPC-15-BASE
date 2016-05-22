//
// Created by david on 5/20/2016.
//

#include "Vector.h"

/// add a Vector to another Vector
//
/// This operator+ adds a Vector value a Vector variable.
Vector Vector::operator+(const Vector &rhs) {
    return Vector((x + rhs.x), (y + rhs.y));
}

/// add a Vector to another Vector
//
/// This operator+= adds a Vector value a Vector variable.
Vector &Vector::operator+=(const Vector &rhs) {
    x += rhs.x;
    y += rhs.y;
    return *this;
}

/// subtract a Vector by a Vector
//
/// This operator- multiplies a Vector value by a Vector value.
Vector Vector::operator-(const Vector &rhs) {
    return Vector((x - rhs.x), (y - rhs.y));
}

/// subtract a Vector by a Vector
//
/// This operator-= multiplies a Vector value by a Vector value.
Vector &Vector::operator-=(const Vector &rhs) {
    x -= rhs.x;
    y -= rhs.y;
    return *this;
}

/// multiply a Vector by a Vector
//
/// This operator* multiplies a Vector value by a Vector value.
Vector Vector::operator*(const Vector &rhs) {
    return Vector((x * rhs.x), (y * rhs.y));
}

/// multiply a Vector by a Vector
//
/// This operator*= multiplies a Vector value by a Vector value.
Vector &Vector::operator*=(const Vector &rhs) {
    x *= rhs.x;
    y *= rhs.y;
    return *this;
}

Vector Vector::operator/(const Vector &rhs) {
    return Vector((x / rhs.x), (y / rhs.y));
}

Vector &Vector::operator/=(const Vector &rhs) {
    x /= rhs.x;
    y /= rhs.y;
    return *this;
}

/// output operator for a Vector value
//
/// This operator<< prints a vector in the format
/// (x, y) where both values are printed as
/// decimal values.
std::ostream &operator<<(std::ostream &lhs, const Vector &rhs) {
    return lhs
           << "("
           << rhs.x
           << ", "
           << rhs.y
           << ")";
}

bool Vector::operator==(const Vector &rhs) {
    return ((x == rhs.x) && (y == rhs.y));
}

Vector Vector::operator*(const int &rhs) {
    return Vector((x * rhs), (y * rhs));
}

Vector &Vector::operator*=(const int &rhs) {
    x *= rhs;
    y *= rhs;
    return *this;
}

Vector Vector::operator/(const int &rhs) {
    return Vector((x / rhs), (y / rhs));
}

Vector &Vector::operator/=(const int &rhs) {
    x /= rhs;
    y /= rhs;
    return *this;
}









