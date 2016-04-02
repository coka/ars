/* This Source Code form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at http://mozilla.org/MPL/2.0/. */

#include <iostream>

using namespace std;

constexpr int image_width {960};
constexpr int image_height {540};
constexpr float dx {1.0f / image_width};
constexpr float dy {1.0f / image_height};

inline void print_ppm_header()
{
	cout << "P3\n" << image_width << " " << image_height << "\n" << "255\n";
}

int main()
{
	print_ppm_header();
	int r {0};
	int g {0};
	constexpr int b {0};
	for (int row {image_height}; row != 0; --row) {
		for (int col {0}; col != image_width; ++col) {
			r = static_cast<int>(dx * 255.0f * col);
			g = static_cast<int>(dy * 255.0f * row);
			cout << r << " " << g << " " << b << "\n";
		}
	}
	return 0;
}
