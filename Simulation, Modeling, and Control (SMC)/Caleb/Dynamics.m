function X = Dynamics(U, X)
%UNTITLED3 Summary of this function goes here
%   Detailed explanation goes here
dt = .1;

X_dot = [X(5) U]';
%X = X_dot * dt + X
X(1) = U(5) * dt + X(1); %velocity * dt + current x_location
X(2) = U(5) * dt + X(2); %velocity * dt + current y_location
drawPoolEnvironment();
drawCar([X(1), X(2)], U(1), U(4), 5);


end