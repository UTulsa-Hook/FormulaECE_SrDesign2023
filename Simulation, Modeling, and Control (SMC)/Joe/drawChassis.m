function [car] = drawChassis(originPt, forwardDist, backDist, width, thetaC,scale)
%drawChassis draws the chassis

%current location 
Xc = originPt(1);
Yc = originPt(2);

%rotation at origin
X_o = scale * [-0.155, -0.155, 0.155, 0.155];
Y_o = scale *[-width/2, width/2, width/2, -width/2];
theta = thetaC;
cth = cos(theta);
sth = sin(theta);
Xrot =  -X_o*cth - Y_o*sth;
Yrot = -X_o*sth + Y_o*cth;

car = patch(Xrot + Xc, Yrot + Yc, 'r'); 

end