function drawChassis(originPt, forwardDist, backDist, width, thetaC, scale)
%drawChassis draws the chassis
X = [-backDist, -backDist, forwardDist, forwardDist];
Y = [-.5*width, .5*width, .5*width, -.5*width];
% X = [originPt(1)-backDist, originPt(1)-backDist, originPt(1)+forwardDist, originPt(1)+forwardDist];
% Y = [originPt(2)-.5*width, originPt(2)+.5*width, originPt(2)+.5*width, originPt(2)-.5*width];

%rotate car
rotationMatrix = [cos(thetaC), -sin(thetaC), 0 ;
                  sin(thetaC), cos(thetaC), 0;
                  0, 0, 1];

pts = [X; Y; zeros(size(X))];
newPts = rotationMatrix * pts;

%translational motion
translateX = ones(1, size(X, 2)) * originPt(1);
translateY = ones(1, size(X, 2)) * originPt(2);

newX = newPts(1, :) + translateX;
newY = newPts(2, :) + translateY;

patch(newX, newY, 'g')
end