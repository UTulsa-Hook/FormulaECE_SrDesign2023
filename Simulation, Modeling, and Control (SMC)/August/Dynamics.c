// dynamics
double Dynamics(double U, double X) // this function assigns values to velocity and draws the car according to // these values // math done in control and other functions global dt;
    double v = U(1);
double thetaS = U(2);
// x = X(1);
// y = X(2);
double theta = X(3);
double xdot = [v * cos(theta);
               v * sin(theta);
               v * tan(thetaS) / .27];

X(1) = xdot(1) * dt + X(1);
// velocity *dt + current x_location
X(2) = xdot(2) * dt + X(2);
// velocity *dt + current y_location
X(3) = xdot(3) * dt + X(3);

return X;