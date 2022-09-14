function drawTire(carLoc, tireLoc, width, radius, thetaC, thetaS)
%drawTires... it draws tires.
%patch(X, Y, C)
X = [-radius, -radius, radius, radius];
Y = [-width, width, width, -width];

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