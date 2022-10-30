// control
// fix this
void Control(double xbar)

    // controlIndex;
    // controlArray;

    if (checkHalfPlane(xbar) > 0)
{
    if (controlIndex == size(controlArray, 1))
    {
        controlIndex = 1;
    }
    else
    {
        controlIndex = controlIndex + 1;

        reset = 1;
    }
}
else
{
    reset = 0;
}
if (controlArray(controlIndex, 1) == 0)
{
    U = controlCircle(xbar, reset);
}
else
{
    U = controlLine(xbar);
}