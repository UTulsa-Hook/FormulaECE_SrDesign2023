function oldDrawCar(carLocation, thetaC, thetaS, scale)
%drawCar, draw the whole car.
forwardCar = scale*.28;
rearCar = scale*.03;
carWidth = scale*.125;
rlTireOffset = [.085, .225, 0]';
rrTireOffset = [.085, -.225, 0]';
flTireOffset = [.8, .225]';
frTireOffset = [.8, -.225]';


oldDrawChassis(carLocation, forwardCar, rearCar, carWidth, thetaC,scale);
oldDrawTire(carLocation,rlTireOffset, .03, .05, thetaC, 0,scale);
oldDrawTire(carLocation,rrTireOffset, .03, .05, thetaC, 0,scale);
oldDrawTire(carLocation,flTireOffset, .023, .028, thetaC, thetaS,scale);
oldDrawTire(carLocation,frTireOffset, .023, .028, thetaC, thetaS,scale);

end

% forwardCar = scale* .28;
% rearCar =  scale* .03;
% width = scale * .125;
% rlTireOffset = [.085, .125/2, 0]';
% rrTireOffset = [.085, -.125/2, 0]';
% flTireOffset = [-.125, .125/2]';
% frTireOffset = [-.125, -.125/2]';
% 
% %drawing functions
% newCarLocation = drawChassis(carLocation, forwardCar, rearCar, width, thetaC, scale);
% drawTire(carLocation, rlTireOffset, .03, .05, thetaC, 0, scale);
% drawTire(carLocation, rrTireOffset, .03, .05, thetaC, 0, scale);
% drawTire(carLocation, flTireOffset, .023, .028, thetaC, thetaS, scale);
% drawTire(carLocation, frTireOffset, .023, .028, thetaC, thetaS, scale);