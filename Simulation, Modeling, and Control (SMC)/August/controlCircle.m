function U = controlCircle(xbar, reset)

global controlArray;
global controlIndex;
global dt;
global v;

persistent oldD;
persistent integral;


if (isempty(oldD))
    oldD = 0;
    integral = 0;
end
if(reset == 1)
    integral = 0;
end

x = xbar(1);
y = xbar(2);
thetaC = xbar(3);

lambda = controlArray(controlIndex, 5);
Rcirc = controlArray(controlIndex, 4);
C = [controlArray(controlIndex, 2); controlArray(controlIndex, 3)];
Rcar = norm(C - [x;y]);
error = Rcar - Rcirc;

if(controlIndex == 14)
    ki=.0004;
elseif(controlIndex == 7)
    ki=.0002;
else
    ki=.00035;
end

if(lambda == 0)
        kp = -0.4;
        kd = -.5;
        ki = -ki;
    else
        kp = 0.4;
        kd = .5;
    end


deriv = (error-oldD)/dt;
%set steering angle

thetaS = (error*kp) + (integral*ki) + (kd*deriv);
U(1) = v;
U(2) = thetaS;
oldD = error;
integral=integral+(error/dt);
end


