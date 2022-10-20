clf;
clear;
drawPool();
carLocation = [1 1]';  %Car location in the pool frame

v = .5;
move = [.1, 0]';
thetaC = 0;

theta_dot = 0;
for t = 0:10
    clf;
    drawPool();
    thetaS = 0;
    thetaC = thetaC + theta_dot;
    carLocation = carLocation + [cos(thetaC)*v, sin(thetaC)*v]'; 
    drawCar(carLocation, thetaC, thetaS);
    carLocation = carLocation + move;
    pause(.1)
end

theta_dot = pi/6;
for t = 10:15
    clf;
    drawPool();
    thetaS = pi/4;
    thetaC = thetaC + theta_dot;
    carLocation = carLocation + [cos(thetaC)*v, sin(thetaC)*v]'; 
    drawCar(carLocation, thetaC, thetaS);
    carLocation = carLocation + move;
    pause(.1)
end

theta_dot = 0;
for t = 15:25
    clf;
    drawPool();
    thetaS = 0;
    thetaC = thetaC + theta_dot;
    carLocation = carLocation + [cos(thetaC)*v, sin(thetaC)*v]'; 
    drawCar(carLocation, thetaC, thetaS);
    carLocation = carLocation + move;
    pause(.1)
end

theta_dot = -pi/12;
for t = 25:30
    clf;
    drawPool();
    thetaS = pi/4;
    thetaC = thetaC + theta_dot;
    carLocation = carLocation + [cos(thetaC)*v, sin(thetaC)*v]'; 
    drawCar(carLocation, thetaC, thetaS);
    carLocation = carLocation + move;
    pause(.1)
end

theta_dot = 0;
for t = 30:35
    clf;
    drawPool();
    thetaS = 0;
    thetaC = thetaC + theta_dot;
    carLocation = carLocation + [cos(thetaC)*v, sin(thetaC)*v]'; 
    drawCar(carLocation, thetaC, thetaS);
    carLocation = carLocation + move;
    pause(.1)
end

theta_dot = pi/4;
for t = 35:40
    clf;
    drawPool();
    thetaS = pi/3;
    thetaC = thetaC + theta_dot;
    carLocation = carLocation + [cos(thetaC)*v, sin(thetaC)*v]'; 
    drawCar(carLocation, thetaC, thetaS);
    carLocation = carLocation + move;
    pause(.1)
end

theta_dot = 0;
for t = 40:45
    clf;
    drawPool();
    thetaS = 0;
    thetaC = thetaC + theta_dot;
    carLocation = carLocation + [cos(thetaC)*v, sin(thetaC)*v]'; 
    drawCar(carLocation, thetaC, thetaS);
    carLocation = carLocation + move;
    pause(.1)
end

theta_dot = pi/16;
for t = 45:60
    clf;
    drawPool();
    thetaS = pi/16;
    thetaC = thetaC + theta_dot;
    carLocation = carLocation + [cos(thetaC)*v, sin(thetaC)*v]'; 
    drawCar(carLocation, thetaC, thetaS);
    carLocation = carLocation + move;
    pause(.1)
end