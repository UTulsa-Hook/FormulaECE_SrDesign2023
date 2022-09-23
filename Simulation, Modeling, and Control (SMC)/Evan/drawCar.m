function drawCar(carLocation, thetaC, thetaS)
%drawCar, draw the whole car.
forwardCar = .28;
rearCar = .03;
carWidth = .125;

rlTireOffset = [0, .125/2]';
rrTireOffset = [0, -.125/2]';
flTireOffset = [.225, .125/2]';
frTireOffset = [.225, -.125/2]';

drawTire(carLocation, rlTireOffset, .05, .03, thetaC, 0);
drawTire(carLocation, rrTireOffset, .05, .03, thetaC, 0);
drawTire(carLocation, flTireOffset, .05, .03, thetaC, thetaS);
drawTire(carLocation, frTireOffset, .05, .03, thetaC, thetaS);

drawChassis(carLocation, forwardCar, rearCar, carWidth, thetaC);

end