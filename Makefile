# This Source Code form is subject to the terms of the Mozilla Public
# License, v. 2.0. If a copy of the MPL was not distributed with this
# file, You can obtain one at http://mozilla.org/MPL/2.0/.

default:
	c++ -std=c++11 main.cpp

render:
	./a.out > render.ppm

clean:
	rm a.out render.ppm
