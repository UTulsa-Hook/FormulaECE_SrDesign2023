function X = Dynamics(U, X)
global dt
global Scale

velocity = U(1);
thetaDot = U(2);
theta = X(3);
X_dot = [velocity * cos(theta); velocity * sin(theta); (velocity * tan(thetaDot)/0.27)];

%X = X_dot * dt + X
X(1) = X_dot(1) * dt + X(1); 
X(2) = X_dot(2) * dt + X(2); 
X(3) = X_dot(3) * dt + X(3);

drawPoolEnviroment()
drawCar([X(1), X(2)], X(3), U(2), Scale);
end