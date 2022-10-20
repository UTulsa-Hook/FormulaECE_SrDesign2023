function U = Control(X_bar)
%UNTITLED2 Summary of this function goes here
%   Detailed explanation goes here
    global controlArray;
    global controlIndex;

    if(checkHalfPlane(X_bar) > 0)
        if(controlIndex == size(controlArray, 1))
            controlIndex = 1; %set to break for demo
        else
            controlIndex = controlIndex + 1;
        end
        resetIntegral = 1;
    else
        resetIntegral = 0;
    end
    
    if(controlArray(controlIndex,1) == 0)
        U = controlCircle(X_bar, resetIntegral);
    else
        U = controlLine(X_bar);
    end
end