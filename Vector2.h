#pragma once

class Vector2
{
	public:
		float x, y;
		Vector2(float valueX = 0.0f , float valueY = 0.0f);

		Vector2 operator-(const Vector2& other);
		Vector2 operator+(const Vector2& other);
		Vector2& operator=(const Vector2& other);
		Vector2 operator*(float scalar) const;

		static const Vector2 VectorZero();
		static const Vector2 VectorDown();
		static const Vector2 VectorUp();

};

