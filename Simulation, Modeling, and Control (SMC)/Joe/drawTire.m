function drawTire(carLoc, tireOffset, width, radius, thetaC, thetaS,scale)
%drawTires draws tires
%patch(X, Y, C)

%tire rotation
X_o = scale * [-radius, -radius, radius, radius];
Y_o = scale * [-width, width, width, -width];
theta = thetaS; % The rotation angle
cth = cos(theta);
sth = sin(theta);
Xrot =  -X_o*cth - Y_o*sth;
Yrot = -X_o*sth + Y_o*cth;

%translate 
translateX = ones(1,size(X_o, 2)) * tireOffset(1);
translateY = ones(1,size(X_o, 2)) * tireOffset(2);

X_o = Xrot + translateX;
Y_o = Yrot + translateY;

%rotate wrt world
theta = thetaC; 
cth = cos(theta);
sth = sin(theta);
Xrot =  -X_o*cth - Y_o*sth;
Yrot = -X_o*sth + Y_o*cth;

%translate wrt world
translateX = ones(1,size(X_o, 2)) * carLoc(1);
translateY = ones(1,size(X_o, 2)) * carLoc(2);

X_o = Xrot + translateX;
Y_o = Yrot + translateY;

%draw the tire
patch(X_o, Y_o, 'k'); 
end