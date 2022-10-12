function drawTire(carLoc, tireOffset, width, radius, thetaC, thetaS, scale)
%drawTires... it draws tires.
%patch(X, Y, C)

%perform the rotation about the car's reference frame at the origin
X_o = scale * [-radius, -radius, radius, radius];
Y_o = scale * [-width, width, width, -width];
theta = thetaS; % The rotation angle
cth = cos(theta);
sth = sin(theta);
Xrot =  -X_o*cth - Y_o*sth;
Yrot = -X_o*sth + Y_o*cth;

%translate in the car's reference frame
translateX = ones(1,size(X_o, 2)) * tireOffset(1);
translateY = ones(1,size(X_o, 2)) * tireOffset(2);

X_o = Xrot + translateX;
Y_o = Yrot + translateY;

%rotate in the world's reference frame
theta = thetaC; % The rotation angle
cth = cos(theta);
sth = sin(theta);
Xrot =  -X_o*cth - Y_o*sth;
Yrot = -X_o*sth + Y_o*cth;

%translate the points in the world's reference frame
translateX = ones(1,size(X_o, 2)) * carLoc(1);
translateY = ones(1,size(X_o, 2)) * carLoc(2);

X_o = Xrot + translateX;
Y_o = Yrot + translateY;

%draw the tire
patch(X_o, Y_o, [0.8353, 0.3843, 0.4784]); %RGB values for pink tires
end