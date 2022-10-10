
function drawCar(carLocation, thetaC, thetaS, scale)
%drawCar, draw the whole car.
forwardCar = scale*.08;
rearCar = scale*.01;
carWidth = scale*.05;
% rlTireOffset = scale * [.085, .5, 0]';
% rrTireOffset = scale * [.085, -.5, 0]';
% flTireOffset = scale * [1.7, .5]';
% frTireOffset = scale * [1.7, -.5]';
flTireOffset = scale * [.185, .125/2, 0]';
frTireOffset = scale * [.185, -.125/2, 0]';
rlTireOffset = scale * [.01, .125/2]';
rrTireOffset = scale * [.01, -.125/2]';


drawChassis(carLocation, forwardCar, rearCar, carWidth, thetaC,scale);
drawTire(carLocation,rlTireOffset, .03, .05, thetaC, 0,scale);
drawTire(carLocation,rrTireOffset, .03, .05, thetaC, 0,scale);
drawTire(carLocation,flTireOffset, .023, .028, thetaC, thetaS,scale);
drawTire(carLocation,frTireOffset, .023, .028, thetaC, thetaS,scale);

end