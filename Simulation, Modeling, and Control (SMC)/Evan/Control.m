function U = Control(X_bar)
%CONTROL Summary of this function goes here
%   Detailed explanation goes here
persistent oldD;
if(isempty(oldD))
    oldD = 0;
end

dt = 0.1;
lineToFollow = [ 1 8; 0 7];
xdiff = lineToFollow(1,2) - lineToFollow(1,1);
ydiff = lineToFollow(2,2) - lineToFollow(2,1);
angle = atan2d(ydiff, xdiff);
R = [cosd(angle) -sind(angle) lineToFollow(1,1); sind(angle) cosd(angle) lineToFollow(2,1); 0, 0, 1];
D = inv(R) *[X_bar(1:2);1];
v = 1;
kp = -0.4;
kd = -.3;
deriv = (D(2)-oldD)/dt;

thetaS = D(2) * kp + kd * deriv;
Acc = 0.2;
U(1) = v;
U(2) = thetaS;
oldD = D(2);

end

