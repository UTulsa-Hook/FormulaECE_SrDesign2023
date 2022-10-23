function drawPoolEnviroment()
    global Array;
    global Index;
    poolXLims = [0 12]';
    poolYLims = [0 13]';
    rampXLims = [0 4]';
    rampYLims = [11 13]';

    %Draw the pool area
    hold on
    plot([poolXLims(1), poolXLims(1), poolXLims(2), poolXLims(2), poolXLims(1)], ...
        [poolYLims(1), poolYLims(2), poolYLims(2), poolYLims(1), poolYLims(1)],...
        'b' , 'LineWidth', 3)
    %Draw the ramp
    fill([rampXLims(1), rampXLims(1), rampXLims(2), rampXLims(2), rampXLims(1)], ...
        [rampYLims(1), rampYLims(2), rampYLims(2), rampYLims(1), rampYLims(1)],...
        'r' , 'LineWidth', 1)
    xlabel('x')
    ylabel('y')

    x = [8.894, 5.665, 2.656, 1.480, 1.675, 3.769, 5.471, 9.284, 9.980,...
        9.183, 3.595, 2.358, 2.511, 4.542, 6.451, 8.331, 8.862, 9.599,...
        10.284, 10.141];
    y = [1.732, 2.363, 1.961, 3.135, 8.425, 9.916, 9.591, 10.713, 9.900,...
        9.314, 8.988, 7.741, 3.485, 3.186, 2.840, 3.011, 4.809, 5.117,...
        4.714, 2.669];
    plot(x, y)

    x2 = [9.036, 5.695, 2.732, 0.021, 0.028, 1.409, 5.306, 9.387, 11.685,...
        9.294, 4.346, 3.906, 3.860, 4.630, 6.667, 7.216, 8.143, 10.728,...
        11.644, 11.580, 9.036];
    y2 = [0.381, 0.748, 0.445, 3.080, 9.958, 11.204, 11.229, 13.158,...
        10.265, 7.798, 7.534, 7.023, 5.483, 4.725, 4.366, 4.935, 6.928,...
        6.970, 5.581, 2.275, 0.381];
    plot(x2, y2);
    
    incrementalDrawing = true;

    if(incrementalDrawing == true)
        if(Array(Index, 1) == 0)
            drawCircle([Array(Index,2), Array(Index,3)],...
                Array(Index,4))
        else
            plot([Array(Index,2), Array(Index,4)], [Array(Index,3),...
                Array(Index,5)], 'k');
        end
    else
        drawTrack();
    end
    hold off
end