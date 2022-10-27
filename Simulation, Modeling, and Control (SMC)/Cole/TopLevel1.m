Initialize();
global dt;
global Scale;

oldPos = PriorityQueue(1);
counter = 0;
XBar = SensorModel(X, U);

while 1
    clf;
    XBar = doPositionUncert(XBar, oldPos);
    UBar = Control(XBar);
    U = MotorModel(UBar);
    X = Dynamics(U, X);
    XBar = SensorModel(X, U);
    if(counter > 2/(dt))
         oldPos.remove(oldPos.peek());
    end
    
    oldPos.insert([counter, XBar(1), XBar(2)]);
    counter = counter + 1;
    testAngle = rad2deg(U(2));
    pause(dt);
end