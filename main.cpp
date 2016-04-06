/* This Source Code form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at http://mozilla.org/MPL/2.0/. */

#include <iostream>

#include "Vector3f.hpp"
#include "Ray.hpp"

using namespace std;

constexpr int image_width {960};
constexpr int image_height {540};
constexpr float dx {1.0f / image_width};
constexpr float dy {1.0f / image_height};
const auto origin = Vector3f(0.0f, 0.0f, 0.0f);
const auto virtual_plane_corner = Vector3f(-1.0f, -1.0f, -1.0f);
const auto virtual_plane_horizontal = Vector3f(2.0f, 0.0f, 0.0f);
const auto virtual_plane_vertical = Vector3f(0.0f, 2.0f, 0.0f);
const Vector3f x_offset = dx * virtual_plane_horizontal;
const Vector3f y_offset = dy * virtual_plane_vertical;

inline void print_ppm_header()
{
	cout << "P3\n" << image_width << " " << image_height << "\n" << "255\n";
}

int main()
{
	print_ppm_header();
	auto ray = Ray(origin, virtual_plane_corner);
	for (int row {image_height}; row != 0; --row) {
		ray.direction += y_offset;
		for (int col {0}; col != image_width; ++col) {
			ray.direction += x_offset;
			cout << (get_normalized(ray.direction) + 1.0f) * 0.5f;
		}
		ray.direction -= virtual_plane_horizontal;
	}
	return 0;
}
