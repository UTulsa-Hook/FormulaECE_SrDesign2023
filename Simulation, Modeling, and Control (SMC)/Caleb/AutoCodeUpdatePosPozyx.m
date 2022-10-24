function X = AutoCodeUpdatePosPozyx(X, positionQueue, pozyxInput)
%UNTITLED5 Summary of this function goes here
%   Detailed explanation goes here
muPosTime = 0.7; %global...maybe?
dt = 0.1; %global
updatePos = [0 0 0];

if(positionQueue.size() > 1.9/dt)
    queue = elements(positionQueue);
    timeWeThink = muPosTime;
    IndexUs = int8(timeWeThink/dt);
    IndexUsBackwards = positionQueue.size() - IndexUs;
    X_old_predicted = queue{IndexUsBackwards}(2:3);
    X_old_predicted = [0 0]; %change later
    updatePos(1) = pozyxInput(1) - X_old_predicted(1);
    updatePos(2) = pozyxInput(2) - X_old_predicted(2);
    X = X + (updatePos/10)';
end
end