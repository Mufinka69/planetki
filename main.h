#pragma once

#include "raylib.h"

#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <fstream>


#define WINDOW_WIDTH 900
#define WINDOW_HEIGHT 900

#define MIN 1e-8
#define MIN2 0.05

// int number_of_planets = 0;
#define G 6.67428e-11
#define AU  149.6e6 * 1000
#define scale (200.0 / AU)


#include "Vector3d.h"
#include "celestialBody.h"
#include "simulatoin.h"
#include "simulation2d.h"

