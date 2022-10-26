function X = AutoCodeEstimatePos(X, U)
%UNTITLED3 Summary of this function goes here
%   Detailed explanation goes here
dt = .1;
v = U(1);
thetaS = U(2);
theta = X(3);
X_dot = [v * cos(theta);
         v * sin(theta);
         v * tan(thetaS)/.27];

%X = X_dot * dt + X
X(1) = X_dot(1) * dt + X(1); %velocity * dt + current x_location
X(2) = X_dot(2) * dt + X(2); %velocity * dt + current y_location
X(3) = X_dot(3) * dt + X(3);



end