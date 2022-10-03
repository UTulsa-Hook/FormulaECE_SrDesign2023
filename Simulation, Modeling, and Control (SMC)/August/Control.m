function U =control(xbar)
%this function automates the motion of the car and corrects the movement
%so that the course is adjusted to match expectations
%U represents the changed state of the car as apposed to xbar which is the
%sensed state

persistent oldD;

if(isempty(oldD))
    oldD=0;
end

dt=.01;
%   cLine = [0 1; 7 8];
%     cline2 = [7 8; 12 4];
lineToFollow = [1 8; 0 7];
halfPlane1 = dot([xbar(1);xbar(2)]-[lineToFollow(1,2);lineToFollow(2,2)],[0 1]);

if (halfPlane1>0)
    lineToFollow = [8 4; 7 12];
end

xd=lineToFollow(1,2)-lineToFollow(1,1);
yd=lineToFollow(2,2)-lineToFollow(2,1);
alpha=atan2d(yd, xd);

%rotation matrix
R = [cosd(alpha) -sind(alpha) lineToFollow(1,1); 
    sind(alpha) cosd(alpha) lineToFollow(2,1); 
    0, 0, 1];
D=inv(R)*[xbar(1:2);1];

v=1;
kp=-.04;
kd=-.45;

deriv=(D(2)-oldD)/dt;
thetaS=D(2)*kp+kd*deriv;
accel=.2;
U(1)=v;
U(2)=thetaS;
oldD=D(2);
