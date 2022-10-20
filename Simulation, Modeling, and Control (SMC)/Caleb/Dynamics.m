function X = Dynamics(U, X) %#codegen
%UNTITLED3 Summary of this function goes here
%   Detailed explanation goes here
global dt;
dt = 0.01;
v = U(1);
thetaS = U(2);

theta = X(3);
X_dot = [v * cos(theta);
         v * sin(theta);
         v * tan(thetaS)/.27];

%X = X_dot * dt + X
X(1) = X_dot(1) * dt + X(1); %x velocity * dt + current x_location
X(2) = X_dot(2) * dt + X(2); %y velocity * dt + current y_location
X(3) = X_dot(3) * dt + X(3); %d_thetaC * dt + current thetaC
drawPoolEnvironment();
drawCar([X(1), X(2)], X(3), U(2), 3);


end