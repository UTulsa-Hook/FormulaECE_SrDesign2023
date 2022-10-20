function U = Control(xbar)

global controlIndex;
global controlArray;

if(checkHalfPlane(xbar) > 0)
        if(controlIndex == size(controlArray, 1))
            controlIndex = 100; % 1; set to break for demo
        else
            controlIndex = controlIndex + 1;
        end
        reset = 1;
    else
        reset = 0;
    end
    
    if(controlArray(controlIndex,1) == 0)
        U = controlCircle(xbar, reset);
    else
        U = controlLine(xbar);
    end

end