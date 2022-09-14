function X = Dynamics(U, X)
%UNTITLED3 Summary of this function goes here
%   Detailed explanation goes here
dt = .1;

X_dot = [X(2) U]';
X = X_dot * dt + X
end

