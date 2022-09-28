function U = Control(X_bar)
%UNTITLED2 Summary of this function goes here
%   Detailed explanation goes here
persistent oldD;
if(isempty(oldD))
    oldD = 0;
end
dt = 0.01;

lines = [1 0 7 4;7 4 2 8];
lineToFollow = lines(1,:);

%car is in region where normal vector is pointing when positive
if(dot(([X_bar(1) X_bar(2)] - [lineToFollow(3) lineToFollow(4)]),[.707 .707]) > 0)
    lineToFollow = lines(2,:);
end
lineToFollow
xdiff = lineToFollow(3) - lineToFollow(1);
ydiff = lineToFollow(4) - lineToFollow(2);
angle = atan2d(ydiff, xdiff);
R = [cosd(angle) -sind(angle) lineToFollow(1,1); sind(angle) cosd(angle) lineToFollow(1,2); 0, 0, 1];
D = inv(R) *[X_bar(1:2);1];
v = 1;
kp = -.4;
kd = -.4;
deriv = (D(2)-oldD)/dt;

thetaS = D(2)*kp + kd*deriv;
Acc = 0.2; %m/s/s
U(1) = v;
U(2) = thetaS; %velocity
oldD = D(2);
end