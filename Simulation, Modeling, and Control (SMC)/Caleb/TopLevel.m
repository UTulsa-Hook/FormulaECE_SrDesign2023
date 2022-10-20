clf;
clear;
carLocation = [2 2]';  %Car location in the pool frame
scale = 5; %scale up car to see kinematics in motion
velocity = 0.4 * scale; %set and scale velocity
driveLength = .27;
thetaC = pi/2; %set the initial angle of the car
thetaS = 0; %set the initial steering angle of the car
%move = [.05, -.1]';
pause(3)
for t = 0:0.1:0.6
    clf;
    drawPoolEnvironment();
    %Draw the car
    if t > 0.4
        thetaS = thetaS + pi/36;
    else
        thetaS = thetaS;%atan(2*pi/10*driveLength);
    end
    changeFunct = [velocity * cos(thetaC), velocity * sin(thetaC)]';
    carLocation = carLocation + changeFunct * 0.1;
    drawCar(carLocation, thetaC, thetaS, scale);
    pause(0.05)
end

%set the steering angle
thetaS = pi/12;
for t = 0:0.1:2.2
    %Draw the pool area
    clf;
    drawPoolEnvironment();
    if t > 1.8 %reduce steering angle when nearing end of turn
        thetaS = thetaS - pi/36;
    else
        %else keep it the same
    end
    %increment the car angle
    thetaC = thetaC - pi/50;
    %perform the kinematics to set the new x, y values
    changeFunct = [velocity * cos(thetaC), velocity * sin(thetaC)]';
    % set the new x, y values
    carLocation = carLocation + changeFunct * 0.1;
    %Draw the car
    drawCar(carLocation, thetaC, thetaS, scale);
    pause(0.05)
end

thetaS = -pi/12;
for t = 0:0.1:2.2
    %Draw the pool area
    clf;
    drawPoolEnvironment();
    %Draw the car
    if t > 1.8
        thetaS = thetaS + pi/36;
    else
        thetaS = thetaS;%atan(2*pi/10*driveLength);
    end
    thetaC = thetaC + pi/50;
    changeFunct = [velocity * cos(thetaC), velocity * sin(thetaC)]';
    carLocation = carLocation + changeFunct * 0.1;
    drawCar(carLocation, thetaC, thetaS, scale);
    pause(0.05)
end

thetaS = pi/4;
for t = 0:0.1:1.9
    %Draw the pool area
    clf;
    drawPoolEnvironment();
    %Draw the car
    if t > 1.5
        thetaS = thetaS - pi/12;
    else
        thetaS = thetaS;%atan(2*pi/10*driveLength);
    end
    thetaC = thetaC - pi/12;
    changeFunct = [velocity * cos(thetaC), velocity * sin(thetaC)]';
    carLocation = carLocation + changeFunct * 0.1;
    drawCar(carLocation, thetaC, thetaS, scale);
    pause(0.05)
end

thetaS = -pi/12;
for t = 0:0.1:2.2
    %Draw the pool area
    clf;
    drawPoolEnvironment();
    %Draw the car
    if t > 1.8
        thetaS = thetaS + pi/36;
    else
        thetaS = thetaS;%atan(2*pi/10*driveLength);
    end
    thetaC = thetaC + pi/40;
    changeFunct = [velocity * cos(thetaC), velocity * sin(thetaC)]';
    carLocation = carLocation + changeFunct * 0.1;
    drawCar(carLocation, thetaC, thetaS, scale);
    pause(0.05)
end

thetaS = pi/12;
for t = 0:0.1:2
    %Draw the pool area
    clf;
    drawPoolEnvironment();
    %Draw the car
    if t > 1.6 && t < 2
        thetaS = thetaS - pi/36;
    elseif t >1.9
        thetaC = pi;
        thetaS = 0;
    else
        thetaC = thetaC - pi/50;
        thetaS = thetaS;
    end
    changeFunct = [velocity * cos(thetaC), velocity * sin(thetaC)]';
    carLocation = carLocation + changeFunct * 0.1;
    drawCar(carLocation, thetaC, thetaS, scale);
    pause(0.05)
end
