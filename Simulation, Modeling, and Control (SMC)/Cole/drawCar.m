function [newCarLocation] = drawCar(carLocation, thetaC, thetaDot, Scale)
%drawCar, draw the whole car.
forwardCar = Scale * 0.28;
rearCar = Scale * .03;
carWidth = Scale *.125;

%Tire offsets
rlTireOffset = Scale * [.085, .125/2, 0]';
rrTireOffset = Scale * [.085, -.125/2, 0]';
flTireOffset = Scale * [-0.125, .125/2]';
frTireOffset = Scale * [-0.125, -.125/2]';

%Draw all tires, then Chassis
drawTire(carLocation, rlTireOffset, .03, .05, thetaC, 0, Scale);
drawTire(carLocation, rrTireOffset, .03, .05, thetaC, 0, Scale);
drawTire(carLocation, flTireOffset, .023, 0.03, thetaC, thetaDot, Scale);
drawTire(carLocation, frTireOffset, .023, 0.03, thetaC, thetaDot, Scale);
newCarLocation = drawChassis(carLocation, forwardCar, rearCar, carWidth, thetaC, Scale);
end

