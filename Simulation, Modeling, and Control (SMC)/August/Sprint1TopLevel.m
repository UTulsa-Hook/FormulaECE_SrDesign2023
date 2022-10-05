clf;
clear;
%poolXLims = scale*[-2-scale/2 10-scale/2]';
%poolYLims = scale*[0-scale/2 9-scale/2]';
scale=2;
velocity=.4*scale;
carLocation = [4 6]';  %Car location in the pool frame

thetaC = pi/4; %carangle
thetaS = 0; %steering angle
%move = [.1, .1]';
%plot([poolXLims(1), poolXLims(1), poolXLims(2), poolXLims(2), poolXLims(1)], [poolYLims(1), poolYLims(2), poolYLims(2), poolYLims(1), poolYLims(1)], 'b' , 'LineWidth', 3)
oldDrawCar(carLocation, thetaC, thetaS,scale);

%goal is thetaS=0
for t = 0:1:24
    %Draw the pool area
    clf;
    drawPoolEnvironment();
    %plot([poolXLims(1), poolXLims(1), poolXLims(2), poolXLims(2), poolXLims(1)], [poolYLims(1), poolYLims(2), poolYLims(2), poolYLims(1), poolYLims(1)], 'b' , 'LineWidth', 3)
    %Draw the car
    if t>15
        thetaS=thetaS-(pi/36);
    else
        thetaS=thetaS;
    end
   changeFunct = [velocity * cos(thetaC), velocity * sin(thetaC)]';
    carLocation = carLocation + changeFunct*.1;
    oldDrawCar(carLocation, thetaC, thetaS, scale);
    pause(.1)
end

%set the steering angle
thetaS = -pi/4;
%goal is going down with steering angle 0
for t = 0:1:17
    %Draw the pool area
    clf;
    drawPoolEnvironment();
    if t > 14 %reduce steering angle when nearing end of turn
        thetaS = thetaS + (pi/12);
    else
        %else keep it the same
    end
    %increment the car angle
    thetaC = thetaC - pi/24;
    changeFunct = [velocity * cos(thetaC), velocity * sin(thetaC)]';
    carLocation = carLocation + changeFunct * 0.1;
    %Draw the car
    oldDrawCar(carLocation, thetaC, thetaS, scale);
    pause(0.1)
end

%set the steering angle
thetaS = 0;
%goal is going down with steering angle -pi/4 again probably
for t = 0:1:24
    %Draw the pool area
    clf;
    drawPoolEnvironment();
    if t > 15 %reduce steering angle when nearing end of turn
        thetaS = thetaS - pi/36;
    else
        %else keep it the same
    end
    %increment the car angle
    changeFunct = [velocity * cos(thetaC), velocity * sin(thetaC)]';
    carLocation = carLocation + changeFunct * 0.1;
    %Draw the car
    oldDrawCar(carLocation, thetaC, thetaS, scale);
    pause(0.1)
end

%set the steering angle
%thetaS = -pi/4;
%goal is turning to go left and up
for t = 0:1:17
    %Draw the pool area
    clf;
    drawPoolEnvironment();
    if t > 14 %reduce steering angle when nearing end of turn
        thetaS = thetaS + pi/12;
    else
        %else keep it the same
    end
    %increment the car angle
    thetaC = thetaC - pi/24;
    changeFunct = [velocity * cos(thetaC), velocity * sin(thetaC)]';
    carLocation = carLocation + changeFunct * 0.1;
    %Draw the car
    oldDrawCar(carLocation, thetaC, thetaS, scale);
    pause(0.1)
end

%set the steering angle
thetaS = 0;
%goal is to turn the car next all the way right
for t = 0:1:24
    %Draw the pool area
    clf;
    drawPoolEnvironment();
    if t > 15 %reduce steering angle when nearing end of turn
        thetaS = thetaS - pi/36;
    else
        %else keep it the same
    end
    %increment the car angle
    changeFunct = [velocity * cos(thetaC), velocity * sin(thetaC)]';
    carLocation = carLocation + changeFunct * 0.1;
    %Draw the car
    oldDrawCar(carLocation, thetaC, thetaS, scale);
    pause(0.1)
end

%set the steering angle
%thetaS = -pi/4;
%goal is turning to go left and up
for t = 0:1:17
    %Draw the pool area
    clf;
    drawPoolEnvironment();
    if t > 14 %reduce steering angle when nearing end of turn
        thetaS = thetaS + pi/12;
    else
        %else keep it the same
    end
    %increment the car angle
    thetaC = thetaC - pi/24;
    changeFunct = [velocity * cos(thetaC), velocity * sin(thetaC)]';
    carLocation = carLocation + changeFunct * 0.1;
    %Draw the car
    oldDrawCar(carLocation, thetaC, thetaS, scale);
    pause(0.1)
end

%set the steering angle
thetaS = 0;
%goal is to turn the car next all the way right
for t = 0:1:24
    %Draw the pool area
    clf;
    drawPoolEnvironment();
%     if t > 15 %reduce steering angle when nearing end of turn
%         thetaS = thetaS - pi/36;
%     else
%         %else keep it the same
%     end
    %increment the car angle
    changeFunct = [velocity * cos(thetaC), velocity * sin(thetaC)]';
    carLocation = carLocation + changeFunct * 0.1;
    %Draw the car
    oldDrawCar(carLocation, thetaC, thetaS, scale);
    pause(0.1)
end
