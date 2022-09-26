%Car accelerating over 10 seconds
Initialize();
scale = 5;
dt = .01;
X_bar = SensorModel(X,U);

for t=0:dt:6
    clf;
    U = Control(X_bar);
    X = Dynamics(U,X,scale);
    X_bar = SensorModel(X);
    %Plotting(X,X_bar,U,t);
    pause(dt);

end