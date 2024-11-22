/*
** EPITECH PROJECT, 2023
** RayTracer
** File description:
** Point.cpp
*/

#include "Point.hpp"

namespace Math {

    Point::Point(double x, double y, double z) : x(x), y(y), z(z) {}

    Point &Point::operator=(const Point &other) = default;

    Point &Point::operator=(Point &&other) noexcept
    {
        x = other.x;
        y = other.y;
        z = other.z;
        return (*this);
    }

    Point &Point::operator+(const Vector &other)
    {
        x += other.x;
        y += other.y;
        z += other.z;
        return (*this);
    }

    Point Point::operator-(const Vector &other)
    {
        return Point(x - other.x, y - other.y, z - other.z);
    }


    std::ostream &Point::operator<<(std::ostream &os) const
    {
        os << "Point(" << x << ", " << y << ", " << z << ")";
        return os;
    }

    Vector Point::operator-(const Point &other)
    {
        Vector v(x - other.x, y - other.y, z - other.z);
        return v;
    }

    double Point::distance(const Math::Point &other) const
    {
        return std::sqrt(std::pow(other.x - x, 2) + std::pow(other.y - y, 2) + std::pow(other.z - z, 2));
    }
}