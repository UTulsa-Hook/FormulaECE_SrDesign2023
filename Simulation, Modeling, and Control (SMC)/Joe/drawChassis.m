function [car] = drawChassis(originPt, forwardDist, backDist, width, thetaC, scale)
%drawChassis draws the chassis
%location of the chassis
Xc = originPt(1);
Yc = originPt(2);

%rotation at the origin
X_o = scale * [-0.155, -0.155, 0.155, 0.155];
Y_o = [-width/2, width/2, width/2, -width/2];
theta = thetaC; 
cth = cos(theta);
sth = sin(theta);
Xrot =  -X_o*cth - Y_o*sth;
Yrot = -X_o*sth + Y_o*cth;

%draw the car
car = patch(Xrot + Xc, Yrot + Yc, 'r'); 

end