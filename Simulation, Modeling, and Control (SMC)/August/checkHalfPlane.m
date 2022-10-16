function H = checkHalfPlane(xbar)
%this function checks to see if the car should transfer from one control
%line to another

global controlArray
global controlIndex
x = [xbar(1), xbar(2)];
P = [controlArray(controlIndex, 8), controlArray(controlIndex, 9)];
N = [controlArray(controlIndex, 6), controlArray(controlIndex, 7)];

H=sign(dot((x-P)', N));
end