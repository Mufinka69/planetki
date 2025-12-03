#pragma once

#include "main.h"

class Simulation{
public:
    std::vector<CelestialBody> bodies;
public:
    Simulation(std::vector<CelestialBody> bodies){
        this->bodies = bodies;
    }

    void rk4(){

    }


    void update(double dt){
        for(size_t i = 0; i < bodies.size(); i++){            
            double ax = 0, ay = 0, az = 0;
            for(size_t j = 0; j < bodies.size(); j++){
                if(i != j){
                    double rx = bodies[j].pos.x - bodies[i].pos.x;
                    double ry = bodies[j].pos.y - bodies[i].pos.y;
                    double rz = bodies[j].pos.z - bodies[i].pos.z;
                    double dst = rx*rx + ry*ry + rz*rz;
                    double dst_sqrt = sqrt(dst);
                    double m2 = bodies[j].mass;
                    double F = G * (m2/(std::max(dst_sqrt, MIN) * dst));
                    ax += F * rx;
                    ay += F * ry;
                    az += F * rz;                
                    bodies[i].acceleration.x += ax;
                    bodies[i].acceleration.y += ay;
                    bodies[i].acceleration.z += az;
                }
            }
        }      
        for(size_t i = 0; i < bodies.size(); i++){
            bodies[i].pos.x += bodies[i].velocity.x * dt;
            bodies[i].pos.y += bodies[i].velocity.y * dt;
            bodies[i].pos.z += bodies[i].velocity.z * dt;

            bodies[i].velocity.x += bodies[i].acceleration.x * dt;
            bodies[i].velocity.y += bodies[i].acceleration.y * dt;
            bodies[i].velocity.z += bodies[i].acceleration.z * dt;
            bodies[i].acceleration = Vector3d{0, 0, 0};
        }
    }
};