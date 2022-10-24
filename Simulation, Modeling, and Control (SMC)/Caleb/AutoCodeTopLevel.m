function AutoCodeTopLevel()
    % This script will load a car accelerating from 0 over the course of 10
    % seconds
    [X, U] = AutoCodeInitialize();
    dt = 0.1; %global
%     oldPos = PriorityQueue(1);
    counter = 0;
    for t = 0:dt:20
    %while 1
        X = AutoCodeEstimatePos(X, U);
        %X = AutoCodeUpdatePosPozyx(X, oldPos, pozyxInput);
        U = AutoCodeControl(X);
        PWM = AutoCodeSetMotorPWM(U);
%         if(counter > 2/dt)
%             oldPos.remove(oldPos.peek());
%         end
%         oldPos.insert([counter, X(1), X(2)]);
        counter = counter + 1;
        pause(dt);
    end
end