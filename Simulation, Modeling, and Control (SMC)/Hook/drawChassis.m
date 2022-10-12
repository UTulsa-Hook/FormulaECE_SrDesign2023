function [car] = drawChassis(originPt, forwardDist, backDist, width, thetaC, scale)
%drawChassis draws the chassis
%current location of the chassis
Xc = originPt(1);
Yc = originPt(2);

%perform the rotation at the origin, using the true center point
X_o = scale * [-0.155, -0.155, 0.155, 0.155];
Y_o = [-width/2, width/2, width/2, -width/2];
theta = thetaC; % The rotation angle
cth = cos(theta);
sth = sin(theta);
Xrot =  -X_o*cth - Y_o*sth;
Yrot = -X_o*sth + Y_o*cth;

%draw the car
car = patch(Xrot + Xc, Yrot + Yc, [0 0.56470 1]); %RGB values for alpine blue

end

