// checkHalfPlane

double checkHalfPlan(double xbar)
{
    static double result double x[2] = {xbar[1], xbar[2]};
    double P[] = {controlArray[controlIndex][7], controlArray[controlIndex][8]};
    double N[] = {controlArray[controlIndex][5], controlArray[controlIndex][6]};

    double vec1[2] = {x[0] - P[0], x[1] - P[1]};

    for (int i = 0; i < 2; i++)
        result += vec1[i] * N[i];
    return result;
    // H=sign(dot((x-P)', N));
}