function U = Control(X_bar)
%UNTITLED2 Summary of this function goes here
%   Detailed explanation goes here
persistent oldD;
if(isempty(oldD))
    oldD = 0;
end
dt = 0.01;
lineToFollow1 = [1 8; 0 7];

halfPlane1 = dot([X_bar(1);X_bar(2)]-[lineToFollow1(1,2);lineToFollow1(2,2)],[0 1]);
if halfPlane1 > 0
    lineToFollow1 = [8 5; 7 10];
end
xdiff = lineToFollow1(1,2) - lineToFollow1(1,1);
ydiff = lineToFollow1(2,2) - lineToFollow1(2,1);
angle = atan2d(ydiff, xdiff);
%create the transformation matrix world to line
R = [cosd(angle) -sind(angle) lineToFollow1(1,1); 
    sind(angle) cosd(angle) lineToFollow1(2,1); 
    0, 0, 1];
D = inv(R) *[X_bar(1:2);1];
v = 1;
kp = -0.4;
kd = -.5;
deriv = (D(2)-oldD)/dt;

%set the steering angle with PD controller to steer towards line
thetaS = D(2)*kp + kd*deriv;
Acc = 0.2; %m/s/s
U(1) = v; %velocity
U(2) = thetaS; 
oldD = D(2);
end