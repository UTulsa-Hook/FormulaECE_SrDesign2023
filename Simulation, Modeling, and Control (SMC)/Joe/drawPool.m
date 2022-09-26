function drawPool()


poolXLims = [0 12]';
poolYLims = [0 13]';
rampXLims =[0 4]';
rampYLims =[11 13];
controlLine = [1 1; 8 8];

%Plot Ramp and Pool

hold on;
    plot([poolXLims(1), poolXLims(1), poolXLims(2), poolXLims(2), poolXLims(1)], ...
        [poolYLims(1), poolYLims(2), poolYLims(2), poolYLims(1), poolYLims(1)], 'b' , 'LineWidth', 3);
  
    fill([rampXLims(1), rampXLims(1), rampXLims(2), rampXLims(2), rampXLims(1)], ...
        [rampYLims(1), rampYLims(2), rampYLims(2), rampYLims(1), rampYLims(1)], 'r' , 'LineWidth', 1);
    xlabel('x_w')
    ylabel('y_w')

% PID Control Line
    plot(controlLine(:,1), controlLine(:,2), 'R');
    hold off

end

