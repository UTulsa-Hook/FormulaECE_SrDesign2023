Initialize();
global dt;
global Scale
Scale = 2.5;
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

