function drawChassis(originPt, forwardDist, backDist, width, thetaC)
%drawChassis draws the chassis
X = [-backDist, -backDist, forwardDist, forwardDist];
Y = [-.5*width, .5*width, .5*width, -.5*width];

rotationMatrix = [cos(thetaC), -sin(thetaC), 0;
                  sin(thetaC), cos(thetaC), 0;
                  0, 0, 1];
pts = [X; Y; zeros(size(X))];

newPts = rotationMatrix * pts;

%translate the points
translateX = ones(1, size(X, 2)) * originPt(1);
translateY = ones(1, size(X, 2)) * originPt(2);

newX = newPts(1,:) + translateX;
newY = newPts(2,:) + translateY;

%plot
patch(newX, newY, 'red')
end