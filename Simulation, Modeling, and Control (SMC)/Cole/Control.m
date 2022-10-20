function U = Control(XBar)

    global Array;
    global Index;

    if(checkHalfPlane(XBar) > 0)
        if(Index == size(Array, 1))
            Index = 1;
        else
            Index = Index + 1;
        end
        resetIntegral = 1;
    else
        resetIntegral = 0;
    end
    
    if(Array(Index, 1) == 0)
        U = Circle(XBar, resetIntegral);
    else
        U = Line(XBar);
    end
end

