% This script will load a car accelerating from 0 over the course of 10
% seconds
Initialize();
%scale = 5; %scale up car to see kinematics in motion
oldPos = PriorityQueue(1);
X_bar = SensorModel(X, U);
counter = 0;
t = 0;
while true
    clf;
    X_bar = doPositionUncert(X_bar, oldPos);
    U_bar = Control(X_bar);
    %U = Control(X_bar); used for testing/plotting
    [U, PWMToSend] = MotorModels(U_bar);
    X = Dynamics(U, X); % used for testing/plotting
    X_bar = SensorModel(X,U);
    %Plotting(X, X_bar, U, t);
    if(counter> 2 /dt);
        oldPos.remove(oldPos.peek());
    end
    oldPos.insert([counter, X_bar(1), X_bar(2)]);
    counter = counter +1;
    pause(dt);
    t = t + dt;
    out = sprintf("X: %f, Y: %f, Heading: %f, Velocity: %f, Steering Angle: %f", X(1), X(2), X(3), U(1), U(2));
    disp(out)
end