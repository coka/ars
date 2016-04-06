/* This Source Code form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at http://mozilla.org/MPL/2.0/. */

struct Ray {
	Vector3f origin;
	Vector3f direction;
	Ray(const Vector3f& origin, const Vector3f& direction) :
		origin {origin}, direction {direction} {}
};
