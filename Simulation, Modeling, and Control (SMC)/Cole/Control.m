function U = Control(XBar)
dt = 0.01;

persistent oldD;
if(isempty(oldD))
    oldD = 0;
end

Line = [1 8; 0 7];
xDiff = Line(1,2) - Line(1,1);
yDiff = Line(2,2) - Line(2,1);
angle = atan2d(yDiff, xDiff);
R = [cosd(angle) -sind(angle) Line(1,1); sind(angle) cosd(angle)...
    Line(2,1); 0, 0, 1];
D = inv(R) *[XBar(1:2);1];

v = 1;
kp = -0.4;
kd = -.3;
deriv = (D(2)-oldD)/dt;

thetaDot = D(2)*kp + kd*deriv;
acc = 0.2; %m/s^2
U(1) = v;
U(2) = thetaDot; %velocity
oldD = D(2);
end
