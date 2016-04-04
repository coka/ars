/* This Source Code form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at http://mozilla.org/MPL/2.0/. */

class Vector3f {
	float e[3];
public:
	Vector3f(float e0, float e1, float e2) : e {e0, e1, e2} {}

	float r() const { return e[0]; }
	float g() const { return e[1]; }
	float b() const { return e[2]; }
	float& r() { return e[0]; }
	float& g() { return e[1]; }
	float& b() { return e[2]; }
};

inline std::ostream& operator<<(std::ostream& os, const Vector3f& v)
{
	os
		<< static_cast<int>(v.r() * 255.0f) << " "
		<< static_cast<int>(v.g() * 255.0f) << " "
		<< static_cast<int>(v.b() * 255.0f) << "\n";
	return os;
}
