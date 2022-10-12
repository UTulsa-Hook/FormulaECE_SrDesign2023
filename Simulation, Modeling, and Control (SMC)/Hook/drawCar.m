function [newCarLocation] = drawCar(carLocation, thetaC, thetaS, scale)
%drawCar, draw the whole car.
forwardCar = scale * 0.28;
rearCar = scale * .03;
carWidth = scale *.125;

%tire offsets, scaled
rlTireOffset = scale * [.085, .125/2, 0]';
rrTireOffset = scale * [.085, -.125/2, 0]';
flTireOffset = scale * [-0.125, .125/2]';
frTireOffset = scale * [-0.125, -.125/2]';

%draw all four tires, then chassis to simulate top-down view
drawTire(carLocation, rlTireOffset, .03, .05, thetaC, 0, scale);
drawTire(carLocation, rrTireOffset, .03, .05, thetaC, 0, scale);
drawTire(carLocation, flTireOffset, .023, 0.03, thetaC, -thetaS, scale);
drawTire(carLocation, frTireOffset, .023, 0.03, thetaC, -thetaS, scale);
newCarLocation = drawChassis(carLocation, forwardCar, rearCar, carWidth, thetaC, scale);
end