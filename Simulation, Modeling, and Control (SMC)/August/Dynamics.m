function X = Dynamics(U, X)
%this function assigns values to velocity and draws the car according to
%these values
%math done in control and other functions
global dt;
v = U(1);
thetaS = U(2);
% x = X(1);
% y = X(2);
theta = X(3);
xdot = [v * cos(theta);
         v * sin(theta);
         v * tan(thetaS)/.27];

X(1) = xdot(1) * dt + X(1); %velocity * dt + current x_location
X(2) = xdot(2) * dt + X(2); %velocity * dt + current y_location
X(3) = xdot(3) * dt + X(3);

drawPoolEnvironment();
drawCar([X(1), X(2)], X(3), U(2), 3);

end

