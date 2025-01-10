#include "Vector2.h"

Vector2::Vector2(float valueX, float valueY) {
	x = valueX;
	y = valueY;
}

#pragma region Math

Vector2 Vector2::operator-(const Vector2& vector2) {
	return Vector2(x - vector2.x, y - vector2.y);
}

Vector2 Vector2::operator+(const Vector2& vector2) {
	return Vector2(x + vector2.x, y + vector2.y);
}
#pragma endregion

Vector2& Vector2::operator=(const Vector2& newVector) {
	x = newVector.x;
	y = newVector.y;
	return *this;
}

Vector2 Vector2::operator*(float scalar) const {
	return Vector2(x * scalar, y * scalar);
}

Vector2 const Vector2::VectorZero() {
    return Vector2(0.0f, 0.0f);
}

Vector2 const Vector2::VectorDown() {
	return Vector2(0.0f, -1.0f);
}

Vector2 const Vector2::VectorUp() {
	return Vector2(0.0f, 1.0f);
}
