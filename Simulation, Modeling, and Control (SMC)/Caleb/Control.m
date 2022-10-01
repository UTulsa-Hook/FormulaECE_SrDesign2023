function U = Control(X_bar)
%UNTITLED2 Summary of this function goes here
%   Detailed explanation goes here
    global controlArray;
    global controlIndex;
    
    if(controlArray(controlIndex,1) == 0)
        U = controlCircle(X_bar, 0);
    else
        U = controlLine(X_bar);
    end
    if(checkHalfPlane(X_bar) > 0)
        controlIndex = controlIndex + 1;
    end
end