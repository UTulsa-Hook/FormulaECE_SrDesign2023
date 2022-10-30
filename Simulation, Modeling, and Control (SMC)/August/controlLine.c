// controlLine
void controlLine(double xbar)
{ // this function automates the motion of the car and corrects the movement // so that the course is adjusted to match expectations // U represents the changed state of the car as apposed to xbar which is the // sensed state

    static double oldD;
    // persistent lineToFollow;

    double W1[] = {controlArray[controlIndex][2], controlArray[controlIndex][3]};
    double W2[] = {controlArray[controlIndex][4], controlArray[controlIndex][5]};
    double xdiff = W2[1] - W1[1];
    double ydiff = W2[2] - W1[2];
    double alpha = atan2(ydiff, xdiff);

    // fix stuff after this
    //  rotation matrix
    R = [ cosd(alpha) - sind(alpha) W1(1);
          sind(alpha) cosd(alpha) W1(2);
          0, 0, 1 ];
    D = inv(R) * [xbar(1 : 2); 1];

    v = 2;
    kp = -.04;
    kd = -.5;

    deriv = (D(2) - oldD) / dt;
    thetaS = D(2) * kp + kd * deriv;
    accel = .2;
    U(1) = v;
    U(2) = thetaS;
    oldD = D(2);
}