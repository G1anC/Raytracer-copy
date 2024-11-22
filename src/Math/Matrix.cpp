/*
** EPITECH PROJECT, 2024
** RayTracer
** File description:
** Matrix.cpp
*/

#include "Matrix.hpp"
#include <cmath>
namespace Math {

    Matrix::Matrix()
    {
        for (int i = 0; i < 2; i++)
            for (int j = 0; j < 2; j++)
                _matrix[i][j] = 0.0;
    }

    Matrix Matrix::rotation(double angle)
    {
        double cosA = std::cos(angle);
        double sinA = std::sin(angle);
        _matrix[0][0] = cosA;
        _matrix[0][1] = -sinA;
        _matrix[1][0] = sinA;
        _matrix[1][1] = cosA;
        return *this;
    }

    Matrix Matrix::transpose() const
    {
        Matrix transposedMatrix = Matrix();
        for (int i = 0; i < 2; i++)
            for (int j = 0; j < 2; j++)
                transposedMatrix._matrix[j][i] = _matrix[i][j];
        return transposedMatrix;
    }

    Vector Matrix::operator*(const Vector& vector) const
    {
        double resultX = _matrix[0][0] * vector.x + _matrix[0][1] * vector.y;
        double resultY = _matrix[1][0] * vector.x + _matrix[1][1] * vector.y;
        return Vector(resultX, resultY, vector.z);
    }
}
