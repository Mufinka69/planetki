#include "main.h"

double step_size(double day, double hour ,double minute, double second){
    double x = day * 86400 + hour * 3600 + minute * 60 + second;
    return x;
}

void to_file3d(std::vector<CelestialBody> celestialBody){
    int n = celestialBody.size();

    for(size_t i = 0; i < celestialBody.size(); i++){
        celestialBody[i].pos.x *= 1E+3;
        celestialBody[i].pos.y *= 1E+3;
        celestialBody[i].pos.z *= 1E+3;

        celestialBody[i].velocity.x *= 1E+3;
        celestialBody[i].velocity.y *= 1E+3;
        celestialBody[i].velocity.z *= 1E+3;
    }

    double h = step_size(0, 0, 15, 0);
    double t = 0;

    std::ofstream file("dane.csv");
    file << "t";
    for(int i=0; i < n; i++) {
        file << ",x" << i << ",y" << i << ",z" << i << ",vx" << i << ",vy" << i << ",vz" << i;
    }
    file << "\n";

    Simulation simulation(celestialBody);

    for (int i = 0; i < 330 * 24 * 4; i++) {
        simulation.update(h, G);
        t += h; 

        file << t;
        for (int j = 0; j < n; j++) {
            file << "," << simulation.bodies[j].pos.x
                 << "," << simulation.bodies[j].pos.y
                 << "," << simulation.bodies[j].pos.z 
                 << "," << simulation.bodies[j].velocity.x 
                 << "," << simulation.bodies[j].velocity.y 
                 << "," << simulation.bodies[j].velocity.z;
        }
        file << "\n";
    }
    std::cout<<"Koniec\n";
}

int main(void){
    
    CelestialBody sun;
    sun.mass = 1.9885e30;
    sun.pos = {-6.552145465986094E+05, -8.074055996381721E+05, 2.337746298157959E+04};
    sun.velocity = {1.267319667192835E-02, -2.984869662410812E-03, -2.299632480900651E-04};

    CelestialBody mercury;
    mercury.mass = 3.302e23;
    mercury.pos = {-4.116167590340819E+07, -5.580676436663349E+07, -7.560019671675563E+05};
    mercury.velocity = {2.937720497049099E+01, -2.660858173233393E+01, -4.867828608265956E+00};

    CelestialBody venus;
    venus.mass = 48.685e23;
    venus.pos = {1.060717877461424E+08, -2.086620529770336E+07, -6.410373987240490E+06};
    venus.velocity = {6.309702047408003E+00, 3.425720416686187E+01, 1.071065316458508E-01};

    CelestialBody earth;
    earth.mass = 5.972e24;
    earth.pos = {3.575124446079806E+07, -1.484718342189244E+08, 3.232936042737961E+04};
    earth.velocity = {2.844354764888314E+01 , 7.023146353458946E+00, -2.657267608467961E-04};

    CelestialBody moon;
    moon.mass = 7.342e22;
    moon.pos = {3.548482926892371E+07, -1.487742551194148E+08, 2.078677739128470E+03};
    moon.velocity = {2.918060928198355E+01, 6.393868921176985E+00, -4.448762218120805E-02};  

    CelestialBody mars;
    mars.mass = 6.4171e23;
    mars.pos = {-2.402228987667708E+08, -4.981198303970903E+07, 4.871200149929363E+06};
    mars.velocity = {5.772981950305239E+00, -2.166971047494309E+01, -5.955446163898426E-01}; 

    CelestialBody jupiter;
    jupiter.mass = 18.9819e26;
    jupiter.pos = {-5.409750748515757E+07, 7.672932397348353E+08, -1.971597677609086E+06};
    jupiter.velocity = {-1.318640433792831E+01, -2.972203575176110E-01, 2.962620083072900E-01}; 

    CelestialBody saturn;
    saturn.mass = 5.6834e26;
    saturn.pos = {1.426234956771061E+09, -1.112238999085577E+08, -5.485220202857335E+07};
    saturn.velocity = {2.147716478372867E-01, 9.610083493508270E+00, -1.757342106382591E-01}; 

    CelestialBody uranus;
    uranus.mass = 86.813e24;
    uranus.pos = {1.568208674065240E+09, 2.462336406070664E+09, -1.117140586686182E+07};
    uranus.velocity = {-5.794247731273689E+00, 3.340784598668210E+00, 8.721656807843736E-02}; 

    CelestialBody neptune;
    neptune.mass = 102.409e24;
    neptune.pos = {4.469549911041720E+09, -7.750027055081327E+06, -1.028456860103240E+08};
    neptune.velocity = {-2.596519389842161E-02, 5.468240145007050E+00, -1.116787845765217E-01}; 

    CelestialBody halley;
    halley.mass = 1.4e14;
    halley.pos = {-2.931178841361410E+09, 4.097298235970351E+09, -1.481973820405183E+09};
    halley.velocity = {8.541057534147880E-01, 3.590946814369584E-01, 1.745002450210156E-01}; 

    std::vector<CelestialBody> celestialBody = {sun, mercury, venus, earth, mars};

    // Simulation simulation(celestialBody);
    to_file3d(celestialBody);




    // InitWindow(WINDOW_WIDTH, WINDOW_HEIGHT, "dd!");
    // SetTargetFPS(120);

    // while (!WindowShouldClose()){
    //      BeginDrawing();
    //         simulation.update(0.1, G);
    //         ClearBackground(BLACK);
    //         auto bodies = simulation.get_bodies();
    //         for(int i = 0; i < celestialBody.size(); i++){
    //             DrawPixel(bodies[i].pos.x, bodies[i].pos.y, RAYWHITE);
    //         }
    //         std::cout<<bodies[1].pos.x << "\n";
    //     EndDrawing();
    // }
}


