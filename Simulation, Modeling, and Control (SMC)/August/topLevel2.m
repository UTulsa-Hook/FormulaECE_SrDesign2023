Initialize();
global dt;

xbar = SensorModel(X,U);
while 1
    clf;
    U = Control(xbar);
    X = Dynamics(U, X);
    xbar = SensorModel(X, U);
    %Plotting(X, xbar, U, t);
    pause(dt/100);
end

%fix stuff tomorrow am tired