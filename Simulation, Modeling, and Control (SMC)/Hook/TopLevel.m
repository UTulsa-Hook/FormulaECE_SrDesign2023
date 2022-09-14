
clf;
clear;
poolXLims = [-2 10]';
poolYLims = [0 9]';
carLocation = [4 4]';  %Car location in the pool frame

thetaC = pi/4;
thetaS = pi/4;
move = [.1, 0]';
plot([poolXLims(1), poolXLims(1), poolXLims(2), poolXLims(2), poolXLims(1)], [poolYLims(1), poolYLims(2), poolYLims(2), poolYLims(1), poolYLims(1)], 'b' , 'LineWidth', 3)
drawCar(carLocation, thetaC, thetaS);
theta_dot = pi/12;
v = .5;
for t = 0:12
    clf;
    plot([poolXLims(1), poolXLims(1), poolXLims(2), poolXLims(2), poolXLims(1)], [poolYLims(1), poolYLims(2), poolYLims(2), poolYLims(1), poolYLims(1)], 'b' , 'LineWidth', 3)
    %Draw the car
    thetaS = pi/4;
    thetaC = thetaC + theta_dot;
    carLocation = carLocation + [cos(thetaC)*v, sin(thetaC)*v]';
    drawCar(carLocation, thetaC, thetaS);
    carLocation = carLocation + move;
    pause(.1)
end

% for t = 0:12
%     %Draw the pool area
%     clf;
%     plot([poolXLims(1), poolXLims(1), poolXLims(2), poolXLims(2), poolXLims(1)], [poolYLims(1), poolYLims(2), poolYLims(2), poolYLims(1), poolYLims(1)], 'b' , 'LineWidth', 3)
%     %Draw the car
%     drawCar(carLocation, thetaC, 0);
%     carLocation = carLocation + move;
%     pause(.1)
% end
% move = [0, .1]';
% for t = 0:12
%     %Draw the pool area
%     clf;
%     plot([poolXLims(1), poolXLims(1), poolXLims(2), poolXLims(2), poolXLims(1)], [poolYLims(1), poolYLims(2), poolYLims(2), poolYLims(1), poolYLims(1)], 'b' , 'LineWidth', 3)
%     %Draw the car
%     drawCar(carLocation, thetaC, 0);
%     carLocation = carLocation + move;
%     pause(.1)
% end