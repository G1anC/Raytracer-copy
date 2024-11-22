/*
** EPITECH PROJECT, 2024
** RayTracer
** File description:
** Matrix.hpp
*/

#ifndef RAYTRACER_Matrix_HPP
#define RAYTRACER_Matrix_HPP
#include "Vector.hpp"
#include "Point.hpp"

namespace Math {
    class Matrix {
        public:
            double _matrix[2][2];

            Matrix();
            ~Matrix() = default;
            Matrix rotation(double angle);
            Matrix transpose() const;
            Vector operator*(const Vector& vector) const;
            // Matrix
    };
}

#endif //RAYTRACER_Matrix_HPP