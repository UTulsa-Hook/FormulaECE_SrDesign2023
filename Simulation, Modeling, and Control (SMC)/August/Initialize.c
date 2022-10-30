// initialize

// i will fix this later

s1.dt = .1;
s1
    // global double v = 1;

    // hardware data
    double driveTable[] = {78, 4.6, 80, 7.8, 82, 11.0, 84, 13.1};
// sample data pwm, speed;
double PI = 3.14159265;
double steerTable[] = {60, 45,
                       62, 45,
                       64, 55,
                       66, 60,
                       68, 70,
                       70, 75,
                       72, 80,
                       74, 90,
                       76, 95,
                       78, 105,
                       80, 110,
                       82, 115,
                       84, 120,
                       86, 125,
                       88, 130};
// sample data pwm, angle

//                        global includeUncertainty;
// global sigmaSteering;
// global sigmaDrive;
// global sigmaPos;
// global sigmaPosTime;
// global muPosTime;

int includeUncertainty = 1;
// above was a boolean
double degs = 5;
double sigmaSteering = deg2rad(degs);
// deg 2 rad not defined in this function
double sigmaDrive = .7;
double sigmaPos = .1;
double sigmaPosTime = .1;
double muPosTime = .7;

// change this to be more accurate to track
double carLocation[] = {1, 9};
// Car location in the pool frame
thetaC = 3 * PI / 2;
// set the initial angle of the car
// thetaS = -pi / 8;
// set the initial steering angle of the car
double X[] = {carLocation[1], carLocation[2], thetaC}; // x, y, thetaC
double U[] = {v, 0};
// vel, thetaS seed = rng('shuffle');

// circ / line(0 / 1), C_x / W1_x, C_y / W1_y, R / W2_x, CW / CCW(0, 1) / W2_y,
// Nx(halfplane), Ny(Halfplane), Px(halfplane), Py(Halfplane) // WRITE THIS LATER

double controlArray[] = {1, 1, 9, 1, 2, 0, -1, 1, 2,
                         0, 2, 2, 1, 1, 1, 0, 2, 1,
                         1, 2, 1, 6, 2, 1, 0, 6, 2,
                         1, 6, 2, 10, 1.5, 1, 0, 9.8, 1.5,
                         0, 10, 2.5, 1, 1, 0, 1, 10.8, 2.5,
                         1, 11, 2.5, 11, 5, 0, 1, 11, 5,
                         0, 10, 4.9, 1, 1, 0, -1, 9, 5,
                         0, 8, 5, 1, 0, -1, 0, 8, 4,
                         1, 8, 4, 4, 4.5, -1, 0, 4.2, 4.5,
                         0, 4, 5.5, 1, 0, 0, 1, 3, 5.3,
                         1, 3, 5.5, 3, 8, 0, 1, 3, 7.6,
                         0, 4, 8, 1, 0, 1, 0, 3.8, 9,
                         1, 4, 9, 10, 9, 1, 0, 10.1, 9,
                         0, 10, 10.5, 1.5, 1, -1, 0, 10, 12,
                         1, 10, 12, 6, 10, -1, 0, 6, 10,
                         1, 6, 10, 2, 10, -1, 0, 2, 10,
                         0, 2, 9, 1, 1, 0, -1, 1, 9};

int controlIndex = 1;