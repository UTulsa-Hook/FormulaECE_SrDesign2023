function [newCarLocation] = drawCar(carLocation, thetaC, thetaS, scale)
%drawCar, draw the whole car.
%parameters
forwardCar = scale* .28;
rearCar =  scale* .03;
width = scale * .125;
rlTireOffset = [.085, .125/2, 0]';
rrTireOffset = [.085, -.125/2, 0]';
flTireOffset = [-.225, .125/2]';
frTireOffset = [-.225, -.125/2]';

%drawing functions
drawTire(carLocation, rlTireOffset, .03, .05, thetaC, 0, scale);
drawTire(carLocation, rrTireOffset, .03, .05, thetaC, 0, scale);
drawTire(carLocation, flTireOffset, .023, .028, thetaC, thetaS, scale);
drawTire(carLocation, frTireOffset, .023, .028, thetaC, thetaS, scale);
newCarLocation = drawChassis(carLocation, width, thetaC, scale);
end