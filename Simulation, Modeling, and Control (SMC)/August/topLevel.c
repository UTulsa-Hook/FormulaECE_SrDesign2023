// this is top level
// all of control
// none of sensor models
// initialize
// half posit uncert
// most motor models
// all dynamics
// no plotting
// queue

X, U = Initialize;
while (1)
{
    X = estimatePos(X, U);
    X = updatePosPozyx;
    U = Control(X, pozyxInput);
    PWM = sendMotorPWM;
}