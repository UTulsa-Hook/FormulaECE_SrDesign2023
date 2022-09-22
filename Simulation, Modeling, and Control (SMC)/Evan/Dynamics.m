function X = Dynamics(U, X)
%DYNAMICS Summary of this function goes here
%   Detailed explanation goes here
dt = .1;
v = U(1);
thetaS = U(2);
x = X(1);
y = X(2);
theta = X(3);
X_dot = [v * cos(theta);
         v * sin(theta);
         v * tan(thetaS)/.27];

X(1) = X_dot(1) * dt + X(1);
X(2) = X_dot(2) * dt + X(2);
X(3) = X_dot(3) * dt + X(3);
drawPool();
drawCar([X(1), X(2)], X(3), U(2));

end

