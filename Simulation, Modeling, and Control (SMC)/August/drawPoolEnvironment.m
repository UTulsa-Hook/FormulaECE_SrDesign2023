function drawPoolEnvironment()
    poolXLims = [0 12]';
    poolYLims = [0 13]';
    rampXLims = [0 4]';
    rampYLims = [11 13]';

    cLine = [1 0; 8 7];
    cline2 = [4 12; 8 7];
    %Draw the pool area
    hold on
    plot([poolXLims(1), poolXLims(1), poolXLims(2), poolXLims(2), poolXLims(1)], ...
        [poolYLims(1), poolYLims(2), poolYLims(2), poolYLims(1), poolYLims(1)], 'b' , 'LineWidth', 3)
    %Draw the ramp
    fill([rampXLims(1), rampXLims(1), rampXLims(2), rampXLims(2), rampXLims(1)], ...
        [rampYLims(1), rampYLims(2), rampYLims(2), rampYLims(1), rampYLims(1)], 'r' , 'LineWidth', 1)
    xlabel('x')
    ylabel('y')
    plot(cLine(:,1), cLine(:,2), 'R');
    plot(cline2(:,1), cline2(:,2), 'R');
    hold off
end