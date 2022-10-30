// control circle
void controlCircle(double xbar, double reset)
{

    static double oldD;
    static double integral;
    static double integralPlot;
    static double t;
    static double ki;
    static double kp;
    static double kd;
    static double deriv;
    static double thetaS;

    t = 0;
    if (reset == 1)
    {
        integral = 0;
    }

    static double x = xbar[1];
    static double y = xbar[2];
    static double thetaC = xbar[3];

    double lambda = controlArray[controlIndex][5];
    double Rcirc = controlArray[controlIndex][4];
    double C[2] = {controlArray[controlIndex][2], controlArray[controlIndex][3]};
    double Rcar = norm(C[1] - x, C[2] - y);
    double error = Rcar - Rcirc;

    if (controlIndex == 14)
    {
        ki = .0004;
    }
    else if (controlIndex == 7)
    {
        ki = .0002;
    }
    else
    {
        ki = .00035;
    }

    if (lambda == 0)
    {
        kp = -0.4;
        kd = -.5;
        ki = -ki;
    }
    else
    {
        kp = 0.4;
        kd = .5;
    }

    if (reset == 1)
    {
        deriv = 0;
    }
    else
    {
        deriv = (error - oldD) / dt;
    }

    thetaS = (error * kp) + (integral * ki) + (kd * deriv);
    U(1) = v;
    U(2) = thetaS;
    oldD = error;
    integral = integral + (error * dt);
}