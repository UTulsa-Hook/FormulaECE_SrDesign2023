function U = Control(X_bar)
%UNTITLED2 Summary of this function goes here
%   Detailed explanation goes here
persistent oldD;
if(isempty(oldD))
    oldD = 0;
end
dt = 0.01;
lineToFollow = [1 8; 0 7];
xdiff = lineToFollow(1,2) - lineToFollow(1,1);
ydiff = lineToFollow(2,2) - lineToFollow(2,1);
angle = atan2d(ydiff, xdiff);
R = [cosd(angle) -sind(angle) lineToFollow(1,1); sind(angle) cosd(angle) lineToFollow(2,1); 0, 0, 1];
D = inv(R) *[X_bar(1:2);1];
v = 1;
kp = -0.4;
kd = -.5;
deriv = (D(2)-oldD)/dt;

thetaS = D(2)*kp + kd*deriv;
Acc = 0.2; %m/s/s
U(1) = v; %velocity
U(2) = thetaS; 
oldD = D(2);
end