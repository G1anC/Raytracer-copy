/*
** EPITECH PROJECT, 2023
** RayTracer
** File description:
** Vector.cpp
*/

#include "Vector.hpp"

namespace Math {

    Vector::Vector(double x, double y, double z) : x(x), y(y), z(z) {}
    double Vector::length() const {
        return (sqrt((x * x) + (y * y) + (z * z)));
    }

    double Vector::dot(const Vector &other) const {
        return ((x * other.x) + (y * other.y) + (z * other.z));
    }

    Vector &Vector::operator=(const Vector &other) = default;

    Vector &Vector::operator=(Vector &&other) noexcept
    {
        x = other.x;
        y = other.y;
        z = other.z;
        return (*this);
    }

    Vector& Vector::operator+=(const Vector &other)
    {
        x += other.x;
        y += other.y;
        z += other.z;
        return (*this);
    }

    Vector& Vector::operator-=(const Vector &other)
    {
        x -= other.x;
        y -= other.y;
        z -= other.z;
        return (*this);
    }

    Vector& Vector::operator*=(const Vector &other)
    {
        x *= other.x;
        y *= other.y;
        z *= other.z;
        return (*this);
    }

    Vector& Vector::operator/=(const Vector &other)
    {
        x /= other.x;
        y /= other.y;
        z /= other.z;
        return (*this);
    }

    Vector &Vector::operator+=(double scalar)
    {
        x *= scalar;
        y *= scalar;
        z *= scalar;
        return (*this);
    }

    Vector &Vector::operator-=(double scalar)
    {
        x /= scalar;
        y /= scalar;
        z /= scalar;
        return (*this);
    }

    Vector &Vector::operator*=(double scalar)
    {
        x *= scalar;
        y *= scalar;
        z *= scalar;
        return (*this);
    }

    Vector &Vector::operator/=(double scalar)
    {
        x /= scalar;
        y /= scalar;
        z /= scalar;
        return (*this);
    }

    // Vector& Vector::operator+(const Vector &other) {
    //     return (Vector(x + other.x, y + other.y, z + other.z));
    // }

    // Vector& Vector::operator-(const Vector &other) {
    //     return (Vector(x - other.x, y - other.y, z - other.z));
    // }

    Math::Vector Vector::operator*(double scalar) const
    {
        return {x * scalar, y * scalar, z * scalar};
    }

    Math::Vector Math::Vector::operator/(double scalar)
    {
        return {x / scalar, y / scalar, z / scalar};
    }

    Vector Vector::operator+(const Vector &other) const
    {
        return (Vector(x + other.x, y + other.y, z + other.z));
    }

    double Vector::operator*(const Vector &other) const
    {
        return ((x * other.x) + (y * other.y) + (z * other.z));
    }

    void Math::Vector::rotateX(double angle)
    {
        double cosAngle = cos(angle);
        double sinAngle = sin(angle);
        double newY = y * cosAngle - z * sinAngle;
        double newZ = y * sinAngle + z * cosAngle;
        y = newY;
        z = newZ;
    }

    void Math::Vector::rotateY(double angle)
    {
        double cosAngle = cos(angle);
        double sinAngle = sin(angle);
        double newX = x * cosAngle + z * sinAngle;
        double newZ = -x * sinAngle + z * cosAngle;
        x = newX;
        z = newZ;
    }

    void Vector::normalize()
    {
        double length = sqrt(x * x + y * y + z * z);
        if (length != 0) {
            x /= length;
            y /= length;
            z /= length;
        }
    }

    Vector Vector::toNormalized() const {
        double length = sqrt(x * x + y * y + z * z);
        if (length != 0) {
            return {x / length, y / length, z / length};
        }
        return {0, 0, 0};
    }

}