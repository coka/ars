/* This Source Code form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at http://mozilla.org/MPL/2.0/. */

#pragma once

struct Sphere {
	Vector3f center;
	float radius;
	Sphere(const Vector3f& center, const float& radius) :
		center {center}, radius {radius} {}

};
