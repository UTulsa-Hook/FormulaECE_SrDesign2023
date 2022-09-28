function drawTire(carLoc, tireLoc, width, radius, thetaC, thetaS, scale)
%drawTires... it draws tires.
%patch(X, Y, C)
%X = [tireLoc(1)-radius, tireLoc(1)-radius, tireLoc(1)+radius, tireLoc(1)+radius];
%Y = [tireLoc(2)-width/2, tireLoc(2)+width/2, tireLoc(2)+width/2, tireLoc(2)-width/2];

X = scale * [-radius, -radius, radius, radius];
Y = scale * [-width, width, width, -width];
%rotate the points
rotationMatrix = [cos(thetaS), -sin(thetaS), 0 ;
                  sin(thetaS), cos(thetaS), 0;
                  0, 0, 1];

pts = [X; Y; zeros(size(X))];
newPts = rotationMatrix * pts;

%translate points in car body frame
translateX = ones(1, size(X, 2)) * tireLoc(1);
translateY = ones(1, size(X, 2)) * tireLoc(2);

X = newPts(1, :) + translateX;
Y = newPts(2, :) + translateY;

%rotate the points
rotationMatrix = [cos(thetaC), -sin(thetaC), 0 ;
                  sin(thetaC), cos(thetaC), 0;
                  0, 0, 1];

pts = [X; Y; zeros(size(X))];

newPts = rotationMatrix * pts;

%translate the points in car body frame
translateX = ones(1,size(X, 2)) * carLoc(1);
translateY = ones(1,size(X, 2)) * carLoc(2);

X = newPts(1, :) + translateX;
Y = newPts(2, :) + translateY;

patch(X, Y, 'c')

end