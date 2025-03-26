#include "Vector2D.h"
#include <godot_cpp/variant/utility_functions.hpp>

const Vector2D Vector2D::ZERO(0.0, 0.0);

Vector2D::Vector2D() : x(0), y(0) {}
Vector2D::Vector2D(double x, double y) : x(x), y(y) {}
Vector2D::Vector2D(const Vector2D& other) : x(other.x), y(other.y) {}
Vector2D::Vector2D(godot::Dictionary dict) {
    x = 0.0;
    y = 0.0;
    if (dict.has("x")) {
        godot::Variant vx = dict["x"]; 
        if (vx.get_type() == godot::Variant::Type::FLOAT) {
            x = vx.operator double();
        }
    }
    if(dict.has("y")) {
        godot::Variant vy = dict["y"];
        if (vy.get_type() == godot::Variant::Type::FLOAT) {
            y = vy.operator double();
        }
    }
}

godot::Dictionary Vector2D::to_dict() const {
    godot::Dictionary dict;
    dict["x"] = x;
    dict["y"] = y;
    return dict;
}

double Vector2D::length() const {
    return std::sqrt(x * x + y * y);
}

Vector2D Vector2D::normalized() const {
    double len = length();
    return Vector2D(x / len, y / len);
}

double Vector2D::angle() const {
    return std::atan2(y, x);
}

Vector2D Vector2D::rotated(double angle) const {
    double cos_angle = std::cos(angle);
    double sin_angle = std::sin(angle);
    return Vector2D(x * cos_angle - y * sin_angle, x * sin_angle + y * cos_angle);
}

godot::Vector2 Vector2D::at_scale(double scale) const {
    return godot::Vector2((float)(x / scale), (float)(y / scale));
}

godot::Vector2 Vector2D::relative_at_scale(double base_x, double base_y, double scale) const {

    return godot::Vector2((float)((x - base_x) / scale), (float)((y - base_y) / scale));
}

Vector2D Vector2D::operator+(const Vector2D& other) const {
    return Vector2D(x + other.x, y + other.y);
}

Vector2D Vector2D::operator-(const Vector2D& other) const {
    return Vector2D(x - other.x, y - other.y);
}

Vector2D Vector2D::operator*(double scalar) const {
    return Vector2D(x * scalar, y * scalar);
}

Vector2D Vector2D::operator/(double scalar) const {
    return Vector2D(x / scalar, y / scalar);
}