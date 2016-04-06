/* This Source Code form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at http://mozilla.org/MPL/2.0/. */

#include <cmath>

class Vector3f {
	float e[3];
public:
	Vector3f(float e0, float e1, float e2) : e {e0, e1, e2} {}

	float operator[](const int& i) const { return e[i]; }
	float& operator[](const int& i) { return e[i]; }

	float r() const { return e[0]; }
	float g() const { return e[1]; }
	float b() const { return e[2]; }
	float& r() { return e[0]; }
	float& g() { return e[1]; }
	float& b() { return e[2]; }

	inline Vector3f& operator+=(const Vector3f& v);
	inline Vector3f& operator-=(const Vector3f& v);
	inline Vector3f& operator*=(const Vector3f& v);
	inline Vector3f& operator/=(const Vector3f& v);

	inline float dot(const Vector3f& v) const;
	float length() const { return sqrt(this->dot(*this)); }
};

/******************************************************************************/

inline Vector3f& Vector3f::operator+=(const Vector3f& v)
{
	e[0] += v[0]; e[1] += v[1]; e[2] += v[2];
	return *this;
}

inline Vector3f& Vector3f::operator-=(const Vector3f& v)
{
	e[0] -= v[0]; e[1] -= v[1]; e[2] -= v[2];
	return *this;
}

inline Vector3f& Vector3f::operator*=(const Vector3f& v)
{
	e[0] *= v[0]; e[1] *= v[1]; e[2] *= v[2];
	return *this;
}

inline Vector3f& Vector3f::operator/=(const Vector3f& v)
{
	e[0] /= v[0]; e[1] /= v[1]; e[2] /= v[2];
	return *this;
}

inline float Vector3f::dot(const Vector3f& v) const
{
	return e[0] * v[0] + e[1] * v[1] + e[2] * v[2];
}

/******************************************************************************/

inline Vector3f operator+(const Vector3f& v1, const Vector3f& v2)
{
	return Vector3f(v1[0] + v2[0], v1[1] + v2[1], v1[2] + v2[2]);
}

inline Vector3f operator-(const Vector3f& v1, const Vector3f& v2)
{
	return Vector3f(v1[0] - v2[0], v1[1] - v2[1], v1[2] - v2[2]);
}

inline Vector3f operator*(const Vector3f& v1, const Vector3f& v2)
{
	return Vector3f(v1[0] * v2[0], v1[1] * v2[1], v1[2] * v2[2]);
}

inline Vector3f operator/(const Vector3f& v1, const Vector3f& v2)
{
	return Vector3f(v1[0] / v2[0], v1[1] / v2[1], v1[2] / v2[2]);
}

inline Vector3f operator+(const Vector3f& v, const float& s)
{
	return Vector3f(v[0] + s, v[1] + s, v[2] + s);
}

inline Vector3f operator+(const float& s, const Vector3f& v)
{
	return v + s;
}

inline Vector3f operator*(const Vector3f& v, const float& s)
{
	return Vector3f(v[0] * s, v[1] * s, v[2] * s);
}

inline Vector3f operator*(const float& s, const Vector3f& v)
{
	return v * s;
}

inline Vector3f operator-(const Vector3f& v, const float& s)
{
	return Vector3f(v[0] - s, v[1] - s, v[2] - s);
}

inline Vector3f operator-(const float& s, const Vector3f& v)
{
	return Vector3f(s - v[0], s - v[1], s - v[2]);
}

inline Vector3f operator/(const Vector3f& v, const float& s)
{
	return Vector3f(v[0] / s, v[1] / s, v[2] / s);
}

inline Vector3f operator/(const float& s, const Vector3f& v)
{
	return Vector3f(s / v[0], s / v[1], s / v[2]);
}

inline std::ostream& operator<<(std::ostream& os, const Vector3f& v)
{
	os
		<< static_cast<int>(v.r() * 255.0f) << " "
		<< static_cast<int>(v.g() * 255.0f) << " "
		<< static_cast<int>(v.b() * 255.0f) << "\n";
	return os;
}

inline Vector3f get_normalized(const Vector3f& v)
{
	return v / v.length();
}
