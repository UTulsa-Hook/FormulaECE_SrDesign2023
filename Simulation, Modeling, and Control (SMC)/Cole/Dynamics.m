function X = Dynamics(U, X)
dt = 0.1;
v = U(1);
thetaDot = U(2);
x = X(1);
y = X(2);
theta = X(3);
X_dot = [v * cos(theta); v * sin(theta); (v * tan(thetaDot)/0.27)];

%X = X_dot * dt + X
X(1) = X_dot(1) * dt + X(1); 
X(2) = X_dot(2) * dt + X(2); 
X(3) = X_dot(3) * dt + X(3);

drawPoolEnviroment()
drawCar([X(1), X(2)], X(3), U(2), 5);
end