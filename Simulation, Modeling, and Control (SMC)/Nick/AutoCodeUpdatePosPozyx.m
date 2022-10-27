function X = AutoCodeUpdatePosPozyx(X, pozyxInput, oldPos)
%doPositionUncert find uncertainty in the position measurements

dt = .01;
muPosTime = .7;

updatePos = [0 0 0];

if(oldPos.size() > 1.9/dt)
%    timeFromNow = normrnd(muPosTime, sigmaPosTime);
%    queue = elements(pozyxInput);
%    index = int8(timeFromNow/dt);
%    indexBackwards = pozyxInput.size() - index;
%    X_old_pozyx = queue{indexBackwards}(2:3);
%    X_old_pozyx = X_old_pozyx + [normrnd(0,sigmaPos), normrnd(0,sigmaPos)];
   %queue = elements(pozyxInput);
   timeWeThink = muPosTime;
   indexUs = int8(timeWeThink/dt);
   indexUsBackwards = oldPos.size() - indexUs;
   %X_old_predicted = queue{indexUsBackwards}(2:3);
   X_old_predicted = [1 2];
   updatePos(1) = pozyxInput(1) - X_old_predicted(1);
   updatePos(2) = PozyxInput(2) - X_old_predicted(2);
   X = X + (updatePos/100)';
end
end