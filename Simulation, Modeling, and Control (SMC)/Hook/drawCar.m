function drawCar(carLocation, thetaC, thetaS)
%drawCar, draw the whole car.
forwardCar = 2.4;
rearCar = .6;
carWidth = 1.0;
rlTireOffset = [0, .6]';
rrTireOffset = [0, -.6]';
flTireOffset = [1.8, .6]';
frTireOffset = [1.8, -.6]';


drawTire(carLocation,rlTireOffset, .2, .5, thetaC, 0);
drawTire(carLocation,rrTireOffset, .2, .5, thetaC, 0);
drawTire(carLocation,flTireOffset, .2, .5, thetaC, thetaS);
drawTire(carLocation,frTireOffset, .2, .5, thetaC, thetaS);
drawChassis(carLocation, forwardCar, rearCar, carWidth, thetaC);
end