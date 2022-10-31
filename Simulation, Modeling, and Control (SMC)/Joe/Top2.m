%Car accelerating over 10 seconds
Initialize();
global scale;
global dt;

counter = 0;
scale = 1;
X_bar = SensorModel(X, U);
oldPos = PriorityQueue(1);
for t = 0:dt:20
%while 1
    %clf; 
    X_bar = doPositionUncert(X_bar, oldPos);
    U_bar = Control(X_bar);
    U = MotorModels(U_bar);
    X = Dynamics(U, X);
    X_bar = SensorModel(X, U);
   % Plotting(X, X_bar, U, t);
    if(counter > 2/dt)
        oldPos.remove(oldPos.peek());
    end
    oldPos.insert([counter,X_bar(1), X_bar(2)]);
    counter = counter + 1;
    pause(dt);
end