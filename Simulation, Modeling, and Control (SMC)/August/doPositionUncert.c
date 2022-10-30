// doPositionUncert
double doPositionUncert(double xbar, double pozyxInput)
{

    // need these values so fix these
    //      global sigmaPos;
    //  global sigmaPosTime;
    //  global muPosTime;
    //  global dt;

    double updatePos[] = {0, 0, 0};

    // huh??
    if (pozyxInput.size() > 1.9 / dt)
    {
        timeFromNow = normrnd(muPosTime, sigmaPosTime);
        queue = elements(pozyxInput);
        index = int8(timeFromNow / dt);
        indexBackwards = pozyxInput.size() - index;
        X_old_pozyx = queue{indexBackwards}(2 : 3);
        X_old_pozyx = X_old_pozyx + [ normrnd(0, sigmaPos), normrnd(0, sigmaPos) ];

        timeWeThink = muPosTime;
        IndexUs = int8(timeWeThink / dt);
        indexUsBackwards = pozyxInput.size() - IndexUs;
        X_old_predicted = queue{indexUsBackwards}(2 : 3);
        updatePos(1) = X_old_pozyx(1) - X_old_predicted(1);
        updatePos(2) = X_old_pozyx(2) - X_old_predicted(2)
                                            xbar = xbar + (updatePos / 100);
    }
    return xbar;
}