#pragma once
#include <math.h>

struct Vector2 {
	float x, y;
	Vector2() : x{ 0.0f }, y{ 0.0f } {}
	Vector2(float x1, float y1) : x{ x1 }, y{ y1 } {}

	float magnitude() const {
		return sqrtf(x * x + y * y);
	}

	Vector2 operator+=(const Vector2& v) {
		x += v.x;
		y += v.y;
		return *this;
	}

	Vector2 operator-=(const Vector2& v) {
		x -= v.x;
		y -= v.y;
		return *this;
	}
};

inline Vector2 operator*(const float s, const Vector2& v) {
	return Vector2{ v.x * s, v.y * s };
}

inline Vector2 operator*(const Vector2& v, const float s) {
	return Vector2{ v.x * s, v.y * s };
}

inline Vector2 operator/(const Vector2& v, const float s) {
	return Vector2{ v.x / s, v.y / s };
}