function AutoCodeTopLevel()
% This function is to make a function for autocode in MATLAB
[X, U] = AutoCodeInitialize();
globalcontrolArray = [1, 1, 9, 1, 2, 0, -1, 1, 2; 
                    0, 2.1, 2.1, 1, 1, 1, 0, 2, 1
                    1, 2, 1, 6, 2, 1, 0, 6, 2
                    1, 6, 2, 10, 1.5, 1, 0, 9.8, 1.5
                    0, 9.9, 2.6, 1, 1, 0, 1, 10.8, 2.5
                    1, 11, 2.5, 11, 5, 0, 1, 11, 5
                    0, 10, 4.9, 1, 1, 0, -1, 9, 5
                    0, 7.9, 5.1, 1, 0, -1, 0, 8, 4
                    1, 8, 4, 4, 4.5, -1, 0, 4.2, 4.5
                    0, 4.1, 5.6, 1, 0, 0, 1, 3, 5.3
                    1, 3, 5.5, 3, 8, 0, 1, 3, 7.6
                    0, 4.1, 7.9, 1, 0, 1, 0, 3.8, 9
                    1, 4, 9, 10, 9, 1, 0, 10.1, 9
                    0, 10, 10.5, 1.5, 1, -1, 0, 10, 12
                    1, 10, 12, 6, 10, -1, 0, 6, 10
                    1, 6, 10, 2, 10, -1, 0, 2, 10
                    0, 2, 9, 1, 1, 0, -1, 1, 9];
controlIndex = 1;

dt = .1;
globalv = 1;

globaldriveTable = [78 .92; 80 1.56; 82 2.19; 84 2.61;]; % Eriks PWM values, speed;
globalsteerTable = [60, 45; 62, 45; 64, 55; 66, 60;...
                68, 70; 70 75; 72 80; 74 90;...
                76 95; 78 105; 80 110; 82 115;...
                84 120; 86 125; 88 130;]; % Eriks PWM values, angle,
                                          % 90 is straight

%oldPos = PriorityQueue(1);
PozyxInput = 0;
counter = 0;
while (counter < 20)
    X = AutoCodeEstimatePos(X,U);
    %X = AutoCodeUpdatePosPozyx(X, PozyxInput, oldPos);
    U = AutoCodeControl(X);
    PWM = AutoCodeSetMotorPWM(U);
%     if(counter> 2 /dt)
%         oldPos.remove(oldPos.peek());
%     end
%     oldPos.insert([counter, X(1), X(2)]);
    pause(dt);
    counter = counter + 1;
end