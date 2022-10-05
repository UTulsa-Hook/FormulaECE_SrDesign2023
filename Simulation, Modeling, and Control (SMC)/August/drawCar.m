
function drawCar(carLocation, thetaC, thetaS, scale)
%drawCar, draw the whole car.
forwardCar = scale*.08;
rearCar = scale*.01;
carWidth = scale*.05;
rlTireOffset = [.085, .5, 0]';
rrTireOffset = [.085, -.5, 0]';
flTireOffset = [1.7, .5]';
frTireOffset = [1.7, -.5]';


drawChassis(carLocation, forwardCar, rearCar, carWidth, thetaC,scale);
drawTire(carLocation,rlTireOffset, .03, .05, thetaC, 0,scale);
drawTire(carLocation,rrTireOffset, .03, .05, thetaC, 0,scale);
drawTire(carLocation,flTireOffset, .023, .028, thetaC, thetaS,scale);
drawTire(carLocation,frTireOffset, .023, .028, thetaC, thetaS,scale);

end
