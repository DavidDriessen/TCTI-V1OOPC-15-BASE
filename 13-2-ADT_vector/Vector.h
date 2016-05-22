//
// Created by david on 5/20/2016.
//

#ifndef INC_13_2_ADT_VECTOR_VECTOR_H
#define INC_13_2_ADT_VECTOR_VECTOR_H


#include <ostream>

class Vector {
    int x;
    int y;

public:
    Vector(int x, int y) : x(x), y(y) { }

    Vector operator+(const Vector &rhs);

    Vector &operator+=(const Vector &rhs);

    Vector operator-(const Vector &rhs);

    Vector &operator-=(const Vector &rhs);

    Vector operator*(const Vector &rhs);

    Vector operator*(const int &rhs);

    Vector &operator*=(const Vector &rhs);

    Vector &operator*=(const int &rhs);

    Vector operator/(const Vector &rhs);

    Vector operator/(const int &rhs);

    Vector &operator/=(const Vector &rhs);

    Vector &operator/=(const int &rhs);

    friend std::ostream &operator<<(std::ostream &lhs, const Vector &rhs);

    bool operator==(const Vector &rhs);

};


#endif //INC_13_2_ADT_VECTOR_VECTOR_H
