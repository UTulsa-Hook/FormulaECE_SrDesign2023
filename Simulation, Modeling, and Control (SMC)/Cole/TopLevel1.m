Initialize();
dt = 0.01;
Scale = 5;
XBar = SensorModel(X, U);

for t = 0:dt:12
    clf
    U = Control(XBar);
    X = Dynamics(U, X);
    XBar = SensorModel(X);
    %Plotting(X,XBar,U,t);
    pause(dt);
end
