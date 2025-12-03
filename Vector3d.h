#pragma once 

typedef struct {
    double x; 
    double y; 
    double z; 
}Vector3d;


typedef struct {
    double x; 
    double y; 
}Vector2d;


float rand_float(float a){
    float x = ((float)rand()/(float)(RAND_MAX)) * a;
    return x;
}