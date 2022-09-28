function drawCar(carLocation, thetaC, thetaS, scale)
%drawCar, draw the whole car.
forwardCar = scale * 0.28;
rearCar = scale * .03;
carWidth = scale * .125;
rlTireOffset = scale * [0, .125/2, 0]';
rrTireOffset = scale * [0, -.125/2, 0]';
flTireOffset = scale * [0.225, .125/2]';
frTireOffset = scale * [0.225, -.125/2]';

drawChassis(carLocation, forwardCar, rearCar, carWidth, thetaC, scale);
drawTire(carLocation,rlTireOffset, .05, .03, thetaC, 0, scale);
drawTire(carLocation,rrTireOffset, .05, .03, thetaC, 0,scale);
drawTire(carLocation,flTireOffset, .028, 0.023,thetaC, thetaS, scale);
drawTire(carLocation,frTireOffset, .028, 0.023,thetaC,  thetaS, scale);
end


