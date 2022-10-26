Initialize();
global dt;
global Scale;

XBar = SensorModel(X, U);

while 1
    clf;
    UBar = Control(XBar);
    U = MotorModel(UBar);
    X = Dynamics(U, X);
    XBar = SensorModel(X, U);
    %Plotting(X,XBar,U,t);
    pause(dt);
end