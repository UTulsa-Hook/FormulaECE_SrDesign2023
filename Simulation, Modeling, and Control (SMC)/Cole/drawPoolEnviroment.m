function drawPoolEnviroment()
    poolXLims = [0 12]';
    poolYLims = [0 13]';
    rampXLims = [0 4]';
    rampYLims = [11 13]';
    controlLine1 = [4 8; 7 5];
    controlLine2 = [7 5; 11 6];
    controlLine3 = [11 6; 12 0];
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
    plot(controlLine1(:,1), controlLine1(:,2), 'k');
    plot(controlLine2(:,1), controlLine2(:,2), 'k');
    plot(controlLine3(:,1), controlLine3(:,2), 'k');
    hold off
end