#pragma once

#include "main.h"

typedef struct {
    double mass;           // Masa ciała [kg]
    Vector3d pos;          // Aktualna pozycja ciała w przestrzeni [m]
    Vector3d velocity;     // Aktualna prędkość ciała [m/s]
    Vector3d acceleration; // Aktualne przyspieszenie ciała [m/s2]
} CelestialBody;


typedef struct {
    double mass;           // Masa ciała [kg]
    Vector2d pos;          // Aktualna pozycja ciała w przestrzeni [m]
    Vector2d velocity;     // Aktualna prędkość ciała [m/s]
    Vector2d acceleration; // Aktualne przyspieszenie ciała [m/s2]
} CelestialBody2d;