/*
** EPITECH PROJECT, 2023
** RayTracer
** File description:
** Vector.hpp
*/

#ifndef RAYTRACER_Point_HPP
#define RAYTRACER_Point_HPP

#include "Vector.hpp"
#include "Matrix.hpp"

namespace Math {
    class Point {
        public:
            double x, y, z;

            Point() = default;
            Point(double x, double y, double z);
            Point(const Point &other) = default;
            Point(Point&& other) noexcept = default;

            [[nodiscard]] double distance(const Math::Point &other) const;

            Point& operator=(const Point &other);
            Point& operator=(Point&& other) noexcept;
        
            Point& operator+(const Math::Vector &other);
            Point operator-(const Math::Vector &other);
            Vector operator-(const Math::Point &other);
            friend int operator*(const Math::Point &point, const Math::Vector &vector) {
                return (int)(point.x * vector.x + point.y * vector.y + point.z * vector.z);
            }
            friend int operator*(const Math::Vector &vector, const Math::Point &point) {
                return (int)(point.x * vector.x + point.y * vector.y + point.z * vector.z);
            }
            friend Point operator+(const Math::Point &point, const Math::Vector &vector) {
                return {point.x + vector.x, point.y + vector.y, point.z + vector.z};
            }
            std::ostream& operator<<(std::ostream &os) const;
    };
}

#endif //RAYTRACER_Point_HPP