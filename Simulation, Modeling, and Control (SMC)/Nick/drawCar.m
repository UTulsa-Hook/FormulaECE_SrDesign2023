function drawCar(carLocation, thetaC, thetaS, scale)
%drawCar, draw the whole car.
forwardCar = scale * 0.28;
rearCar = scale * .03;
carWidth = scale * .125;
rlTireOffset = scale * [.04, .125/2, 0]';
rrTireOffset = scale * [.04, -.125/2, 0]';
flTireOffset = scale * [0.125*2, .125/2]';
frTireOffset = scale * [0.125*2, -.125/2]';
% rlTireOffset = scale * [0, .125/2, 0]';
% rrTireOffset = scale * [0, -.125/2, 0]';
% flTireOffset = scale * [0.225, .125/2]';
% frTireOffset = scale * [0.225, -.125/2]';   


drawTire(carLocation,rlTireOffset, .03, .05, thetaC, 0, scale);
drawTire(carLocation,rrTireOffset, .03, .05, thetaC, 0,scale);
drawTire(carLocation,flTireOffset, .023, 0.03,thetaC, thetaS, scale);
drawTire(carLocation,frTireOffset, .023, 0.03,thetaC,  thetaS, scale);
drawChassis(carLocation, forwardCar, rearCar, carWidth, thetaC, scale);
end


