function drawTire(carLoc, tireOffset, width, radius, thetaC, thetaDot, Scale)
%drawTires
%patch(X, Y, C)

%perform the rotation about the car's reference frame at the origin
X_o = Scale * [-radius, -radius, radius, radius];
Y_o = Scale * [-width, width, width, -width];
theta = thetaDot; % The rotation angle
cth = cos(theta);
sth = sin(theta);
Xrot =  -X_o*cth - Y_o*sth;
Yrot = -X_o*sth + Y_o*cth;

%translate relative to car
translateX = ones(1,size(X_o, 2)) * tireOffset(1);
translateY = ones(1,size(X_o, 2)) * tireOffset(2);

X_o = Xrot + translateX;
Y_o = Yrot + translateY;

%rotate relative to world
theta = thetaC; % The rotation angle
cth = cos(theta);
sth = sin(theta);
Xrot =  -X_o*cth - Y_o*sth;
Yrot = -X_o*sth + Y_o*cth;

%translate relative to world
translateX = ones(1,size(X_o, 2)) * carLoc(1);
translateY = ones(1,size(X_o, 2)) * carLoc(2);

X_o = Xrot + translateX;
Y_o = Yrot + translateY;

%draw tire
patch(X_o, Y_o, [0.8353, 0.3843, 0.4784]); %RGB
end