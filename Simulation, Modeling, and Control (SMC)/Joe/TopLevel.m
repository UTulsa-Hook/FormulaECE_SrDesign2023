% SMC Car Simulation
% Joseph Broyles
% S-Shaped Program

clf;
clear;
poolXLims = [0 10]';
poolYLims = [0 8]';
rampXLims =[0 4]';
rampYLims =[6 8];
carLocation = [5 1]';  %Car location in the pool frame

thetaC = 0;
thetaS = 0;
move = [.1, 0]';
v = 1;
dt = .1; %time step
ld = .27;

%Program: S-Shape
for t = 0:.1:5

    %draw pool and ramp limits

    clf;
    plot([poolXLims(1), poolXLims(1), poolXLims(2), poolXLims(2), poolXLims(1)], [poolYLims(1), poolYLims(2), poolYLims(2), poolYLims(1), poolYLims(1)], 'b' , 'LineWidth', 3)
    hold on;
    plot([rampXLims(1), rampXLims(1), rampXLims(2), rampXLims(2), rampXLims(1)], [rampYLims(1), rampYLims(2), rampYLims(2), rampYLims(1), rampYLims(1)], 'r' , 'LineWidth', 3)
    hold off;

    %kinematics
    move = [v*cos(thetaC), v*sin(thetaC)]';%circle

    %Sensors93578593

    %Draw the car
    drawCar(carLocation, thetaC, thetaS);
    carLocation = carLocation + move*dt;
    thetaC = thetaC + 2*pi/100;
    thetaS = -atan(2*pi*ld/5)
    pause(.1)
    
end
for t = 5.1:.1:10

    %draw pool and ramp limits
    clf;
    plot([poolXLims(1), poolXLims(1), poolXLims(2), poolXLims(2), poolXLims(1)], [poolYLims(1), poolYLims(2), poolYLims(2), poolYLims(1), poolYLims(1)], 'b' , 'LineWidth', 3)
    hold on;
    plot([rampXLims(1), rampXLims(1), rampXLims(2), rampXLims(2), rampXLims(1)], [rampYLims(1), rampYLims(2), rampYLims(2), rampYLims(1), rampYLims(1)], 'r' , 'LineWidth', 3)
    hold off;

    %kinematics
    move = [v*cos(thetaC), v*sin(thetaC)]';%circle

    %Draw the car
    drawCar(carLocation, thetaC, thetaS);
    carLocation = carLocation + move*dt;
    thetaC = thetaC - 2*pi/100;
    thetaS = atan(2*pi*ld/5);
    pause(.1)
    
end
for t = 10.1:.1:12.1
    
    %draw pool and ramp limits
    clf;
    plot([poolXLims(1), poolXLims(1), poolXLims(2), poolXLims(2), poolXLims(1)], [poolYLims(1), poolYLims(2), poolYLims(2), poolYLims(1), poolYLims(1)], 'b' , 'LineWidth', 3)
    hold on;
    plot([rampXLims(1), rampXLims(1), rampXLims(2), rampXLims(2), rampXLims(1)], [rampYLims(1), rampYLims(2), rampYLims(2), rampYLims(1), rampYLims(1)], 'r' , 'LineWidth', 3)
    hold off;

    %kinematics
    move = [v*cos(thetaC), v*sin(thetaC)]';%circle

    %Draw the car
    drawCar(carLocation, thetaC, thetaS);
    carLocation = carLocation + move*dt;
    thetaC = thetaC - pi/40;
    thetaS = atan(4*pi*ld/5);
    pause(.1)
    
end
for t = 12.2:.1:14

    %draw pool and ramp limits
    clf;
    plot([poolXLims(1), poolXLims(1), poolXLims(2), poolXLims(2), poolXLims(1)], [poolYLims(1), poolYLims(2), poolYLims(2), poolYLims(1), poolYLims(1)], 'b' , 'LineWidth', 3)
    hold on;
    plot([rampXLims(1), rampXLims(1), rampXLims(2), rampXLims(2), rampXLims(1)], [rampYLims(1), rampYLims(2), rampYLims(2), rampYLims(1), rampYLims(1)], 'r' , 'LineWidth', 3)
    hold off;
    
    %kinematics
    thetaS = thetaC;
    move = [v*cos(thetaC), v*sin(thetaC)]';%circle

    %Draw the car
    drawCar(carLocation, thetaC, thetaS);
    carLocation = carLocation + move*dt;

    pause(.1)
    
end
for t = 14.1:.1:16
    
    %draw pool and ramp limits
    clf;
    plot([poolXLims(1), poolXLims(1), poolXLims(2), poolXLims(2), poolXLims(1)], [poolYLims(1), poolYLims(2), poolYLims(2), poolYLims(1), poolYLims(1)], 'b' , 'LineWidth', 3)
    hold on;
    plot([rampXLims(1), rampXLims(1), rampXLims(2), rampXLims(2), rampXLims(1)], [rampYLims(1), rampYLims(2), rampYLims(2), rampYLims(1), rampYLims(1)], 'r' , 'LineWidth', 3)
    hold off;

    %kinematics
    move = [v*cos(thetaC), v*sin(thetaC)]';%circle

    %Draw the car
    drawCar(carLocation, thetaC, thetaS);
    carLocation = carLocation + move*dt;
    thetaC = thetaC - pi/40;
    thetaS = atan(4*pi*ld/5);
    pause(.1)
    
end
