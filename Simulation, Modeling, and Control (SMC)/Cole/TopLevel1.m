Initialize();
dt = 0.1;
Scale = 4;
XBar = SensorModel(X, U);
global A;
A = 1;

for t = 0:dt:12
    clf
    U = Control(XBar);
    X = Dynamics(U, X);
    XBar = SensorModel(X);
    %Plotting(X,XBar,U,t);
    pause(dt);
    A = A+1
end

