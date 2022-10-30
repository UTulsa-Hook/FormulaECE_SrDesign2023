// motormodels
double MotorModels(double ubar)
{ // MotorModels This function takes in duty cycle and outputs v, thetaS

    static double ubar_hold;
    static double uncert[2] = {0, 0};

    double driveCurvePWM;
    double steerCurvePWM;

    double driveCurve = ubar[1];
    double steerCurve = rad2deg(ubar[2]);

    while (steerCurve < -180 || steerCurve > 180)
    {
        if (steerCurve < -180)
        {
            steerCurve = steerCurve + 360;
        }
        else if (steerCurve > 180)
        {
            steerCurve = steerCurve - 360;
        }
    }

    steerCurve = steerCurve + 90;

    for (int i = 1; i < size(driveTable); i++)
    {
        if (driveCurve >= 0.5 * driveTable[i][2] && driveCurve <= 1.5 * driveTable[i][2])
        {
            U(1) = driveTable[i][2];
            // set the velocity in the model to a possible velocity based on the curves
            driveCurvePWM = driveTable[i][1]; // outputting the corresponding PWM happens here
        }
    }

    for (int i = 1; i < 14; i++)
    {
        if (steerCurvePWM == 0 && steerCurve >= 0.9 * steerTable[i][2] && steerCurve <= 1.1 * steerTable[i][2])
        {
            U(2) = deg2rad(steerTable[i][2] - 90);
            // set the velocity in the model to a possible velocity based on the curves
            steerCurvePWM = steerTable[i][1];
            // outputting the corresponding PWM happens here
        }
    }

    if (driveCurvePWM == 0)
    {
        driveCurvePWM = 78;
        U(1) = driveTable[1][2];
    }

    if (steerCurve > 130)
    {
        steerCurvePWM = 88;
        U(2) = deg2rad(130 - 90);
    }
    else if (steerCurve < 45)
    {
        steerCurvePWM = 60;
        U(2) = deg2rad(45 - 90);
    }
    // shift min angle to center around 0 end

    if (((driveCurvePWM >= 78) && (driveCurvePWM <= 84)) && ((steerCurvePWM <= 88) && (steerCurvePWM >= 60)))
    { //
        // check to see if we have a valid PWM
    }
    else
    {
        U = [ 0, 0 ];
    }

    ubar_hold = ubar;
    PWMToSend = [ driveCurvePWM, steerCurvePWM ];
}