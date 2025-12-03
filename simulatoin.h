#pragma once

#include "main.h"

class Simulation{
public:
    std::vector<CelestialBody> bodies;
public:
    Simulation(std::vector<CelestialBody> bodies){
        this->bodies = bodies;
    }

    std::vector<CelestialBody>& get_bodies(){
        return bodies;
    }

    void rk4(){

    }

    void euler(double dt){
        for(size_t i = 0; i < bodies.size(); i++){
            bodies[i].pos.x += bodies[i].velocity.x * dt;
            bodies[i].pos.y += bodies[i].velocity.y * dt;
            bodies[i].pos.z += bodies[i].velocity.z * dt;

            bodies[i].velocity.x += bodies[i].acceleration.x * dt;
            bodies[i].velocity.y += bodies[i].acceleration.y * dt;
            bodies[i].velocity.z += bodies[i].acceleration.z * dt;
        }
    }

    void update(double dt, double G_const){
        for (int i = 0; i < bodies.size(); i++){
            bodies[i].acceleration = Vector3d{0, 0, 0};
        }

        for(size_t i = 0; i < bodies.size(); i++){            
            double m1 = bodies[i].mass;
            for(size_t j = i+1; j < bodies.size(); j++){
                double m2 = bodies[j].mass;
                
                double rx = bodies[j].pos.x - bodies[i].pos.x;
                double ry = bodies[j].pos.y - bodies[i].pos.y;
                double rz = bodies[j].pos.z - bodies[i].pos.z;
                
                double eps = 1;
                double r2 = rx*rx + ry*ry + rz*rz + eps * eps;
                double inv_r = 1.0/sqrt(r2);
                double inv_r3 = inv_r * inv_r * inv_r;

                bodies[i].acceleration.x += inv_r3 * rx * m2 * G_const;
                bodies[i].acceleration.y += inv_r3 * ry * m2 * G_const;
                bodies[i].acceleration.z += inv_r3 * rz * m2 * G_const;

                bodies[j].acceleration.x -= inv_r3 * rx * m1 * G_const;
                bodies[j].acceleration.y -= inv_r3 * ry * m1 * G_const;
                bodies[j].acceleration.z -= inv_r3 * rz * m1 * G_const;
            }
        }      
        euler(dt);
    }

    
};