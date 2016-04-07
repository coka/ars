/* This Source Code form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at http://mozilla.org/MPL/2.0/. */

#include "Sphere.hpp"

struct Ray {
	Vector3f origin;
	Vector3f direction;
	Ray(const Vector3f& origin, const Vector3f& direction) :
		origin {origin}, direction {direction} {}

	bool is_intersecting (const Sphere& sphere) const;
};

bool Ray::is_intersecting (const Sphere& sphere) const
{
	const Vector3f v = sphere.center - origin;
	const float v_projection = v.dot(get_normalized(direction));
	if (v_projection < 0) { return false; }
	const float d2 = v.dot(v) - v_projection * v_projection;
	if (d2 > sphere.radius * sphere.radius) { return false; }
	return true;
}
