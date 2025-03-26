#ifndef VECTOR2D_H
#define VECTOR2D_H

#include <cmath>
#include <godot_cpp/variant/vector2.hpp>
#include <godot_cpp/variant/dictionary.hpp>

struct Vector2D {
    double x;
    double y;

    Vector2D();
    Vector2D(double x, double y);
    Vector2D(const Vector2D& other);
    Vector2D(godot::Dictionary dict);

    static const Vector2D ZERO;

    // State interaction
    godot::Dictionary to_dict() const;

    double length() const;
    Vector2D normalized() const;
    double angle() const;
    Vector2D rotated(double angle) const;

    // Public interface
    godot::Vector2 at_scale(double scale) const;
    godot::Vector2 relative_at_scale(double base_x, double base_y, double scale) const;

    Vector2D operator+(const Vector2D& other) const;
    Vector2D operator-(const Vector2D& other) const;
    Vector2D operator*(double scalar) const;
    Vector2D operator/(double scalar) const;
};

#endif  // VECTOR2D_H
