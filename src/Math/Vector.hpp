/*
** EPITECH PROJECT, 2023
** RayTracer
** File description:
** Vector.hpp
*/

#ifndef RAYTRACER_Vector_HPP
#define RAYTRACER_Vector_HPP

#include <cmath>
#include <iostream>
#include <utility>


namespace Math {
    class Vector {
        public :
            double x, y, z;
            [[nodiscard]] double length() const;
            [[nodiscard]] double dot(const Vector &other) const;

            Vector() = default;
            Vector(double x, double y, double z);
            Vector(const Vector &other) = default;
            Vector(Vector&& other) noexcept = default;
            void rotateX(double angle);
            void rotateY(double angle);
            Vector& operator=(const Vector &other);
            Vector& operator=(Vector&& other) noexcept;
            Vector& operator+=(const Vector &other);
            Vector& operator-=(const Vector &other);
            Vector& operator*=(const Vector &other);
            Vector& operator/=(const Vector &other);
            Vector& operator+=(double scalar);
            Vector& operator-=(double scalar);
            Vector& operator*=(double scalar);
            Vector& operator/=(double scalar);
            Vector operator+(const Vector &other) const;
            // Vector& operator+(const Vector &other);
            // Vector& operator-(const Vector &other);
            Vector operator*(double scalar) const;
            Vector operator/(double scalar);
            double operator*(const Vector &other) const;

            // to make int * Vector work
            friend Vector operator*(double scalar, const Vector &vector) {
                return {vector.x * scalar, vector.y * scalar, vector.z * scalar};
            }

            friend Vector operator*(int scalar, const Vector &vector) {
                return {vector.x * scalar, vector.y * scalar, vector.z * scalar};
            }
            friend Vector operator-(int scalar, const Vector &vector) {
                return {vector.x - scalar, vector.y - scalar, vector.z - scalar};
            }
            void normalize();
            [[nodiscard]] Vector toNormalized() const;
    };
}

#endif //RAYTRACER_Vector_HPP