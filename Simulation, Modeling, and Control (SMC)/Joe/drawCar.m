function [newCarLocation] = drawCar(carLocation, thetaC, thetaS,scale)
%drawCar, draw the whole car.
% forwardCar = 2.4;
% rearCar = .6;
% carWidth = 1.0;

forwardCar = .28;
rearCar = .03;
carWidth = .125;

rearWidth = .05;
rearRadius = .03;
frontWidth = .028;
frontRadius = .023;


% rlTireOffset = scale*[0, .6]';
% rrTireOffset = scale*[0, -.6]';
% flTireOffset = scale*[1.8, .6]';
% frTireOffset = scale*[1.8, -.6]';

rlTireOffset = scale*[.085, .125/2,0]';
rrTireOffset = scale*[.085, -.125/2,0]';
flTireOffset = scale*[-.125,.125/2]';
frTireOffset = scale*[-.125, -.125/2]';

drawTire(carLocation,rlTireOffset, rearWidth, rearRadius, thetaC, 0, scale);
drawTire(carLocation,rrTireOffset, rearWidth, rearRadius, thetaC, 0, scale);
drawTire(carLocation,flTireOffset, frontWidth, frontRadius, thetaC, thetaS, scale);
drawTire(carLocation,frTireOffset, frontWidth, frontRadius, thetaC, thetaS, scale);

newCarLocation = drawChassis(carLocation, forwardCar, rearCar, carWidth, thetaC, scale);


% s = drawChassis(carLocation, forwardCar*scale, rearCar*scale, carWidth*scale, thetaC);
% s = union(s, drawTire(carLocation,rlTireOffset, rearWidth*scale, rearRadius*scale, thetaC, 0));
% s = union(s,drawTire(carLocation,rrTireOffset, rearWidth*scale, rearRadius*scale, thetaC, 0));
% s = union(s, drawTire(carLocation,flTireOffset, frontWidth*scale, frontRadius*scale, thetaC, thetaS));
% s = union(s, drawTire(carLocation,frTireOffset, frontWidth*scale, frontRadius*scale, thetaC, thetaS));

end