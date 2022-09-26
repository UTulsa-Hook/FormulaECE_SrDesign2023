% function drawTire(carLoc, tireOffset, width, radius, thetaC, thetaS, scale)
% %drawTires... it draws tires.
% %patch(X, Y, C)
% 
% %perform the rotation about the car's reference frame at the origin
% X_o = scale * [-radius, -radius, radius, radius];
% Y_o = scale * [-width, width, width, -width];
% theta = thetaS; % The rotation angle
% cth = cos(theta);
% sth = sin(theta);
% Xrot =  -X_o*cth - Y_o*sth;
% Yrot = -X_o*sth + Y_o*cth;
% 
% %translate in the car's reference frame
% translateX = ones(1,size(X_o, 2)) * tireOffset(1);
% translateY = ones(1,size(X_o, 2)) * tireOffset(2);
% 
% X_o = Xrot + translateX;
% Y_o = Yrot + translateY;
% 
% %rotate in the world's reference frame
% theta = thetaC; % The rotation angle
% cth = cos(theta);
% sth = sin(theta);
% Xrot =  -X_o*cth - Y_o*sth;
% Yrot = -X_o*sth + Y_o*cth;
% 
% %translate the points in the world's reference frame
% translateX = ones(1,size(X_o, 2)) * carLoc(1);
% translateY = ones(1,size(X_o, 2)) * carLoc(2);
% 
% X_o = Xrot + translateX;
% Y_o = Yrot + translateY;
% 
% %draw the tire
% patch(X_o, Y_o, [0.8353, 0.3843, 0.4784]); %RGB values for pink tires
% end

function drawTire(carLoc, tireLoc, width, radius, thetaC, thetaS, scale)
%drawTires... it draws tires.
%patch(X, Y, C)
X = scale * [-radius, -radius, radius, radius];
Y = scale * [-width, width, width, -width];

%Rotate the points
rotationMatrix = [cos(thetaS), -sin(thetaS), 0;
                  sin(thetaS), cos(thetaS), 0;
                  0, 0, 1];
pts = [X; Y; zeros(size(X))];

newPts = rotationMatrix * pts;

%translate the points in the car body frame
translateX = ones(1,size(X, 2)) * tireLoc(1);
translateY = ones(1,size(X, 2)) * tireLoc(2);

X = newPts(1,:) + translateX;
Y = newPts(2,:) + translateY;

%Rotate the points
rotationMatrix = [cos(thetaC), -sin(thetaC), 0;
                  sin(thetaC), cos(thetaC), 0;
                  0, 0, 1];
pts = [X; Y; zeros(size(X))];

newPts = rotationMatrix * pts;

%translate the points in the car body frame
translateX = ones(1,size(X, 2)) * carLoc(1);
translateY = ones(1,size(X, 2)) * carLoc(2);

X = newPts(1,:) + translateX;
Y = newPts(2,:) + translateY;

patch(X, Y, 'k')

end