function drawPoolEnvironment()
    global controlArray;
    global controlIndex;
    poolXLims = [0 12]';
    poolYLims = [0 13]';
    rampXLims = [0 4]';
    rampYLims = [11 13]';
    controlLine1 = [1 9; 1 2];
    controlLine2 = [9 2; 1 2]; 
    controlLine3 = [9 5; 9 2]; 
    controlLine4 = [9 5; 5 5]; 
    controlLine5 = [5 9; 5 5]; 
    controlLine6 = [5 9; 1 9]; 
    %Draw the pool area
    hold on
    plot([poolXLims(1), poolXLims(1), poolXLims(2), poolXLims(2), poolXLims(1)], ...
        [poolYLims(1), poolYLims(2), poolYLims(2), poolYLims(1), poolYLims(1)], 'b' , 'LineWidth', 3)
    %Draw the ramp
    fill([rampXLims(1), rampXLims(1), rampXLims(2), rampXLims(2), rampXLims(1)], ...
        [rampYLims(1), rampYLims(2), rampYLims(2), rampYLims(1), rampYLims(1)], 'r' , 'LineWidth', 1)
    xlabel('x')
    ylabel('y')
    
    if(controlArray(controlIndex,1) == 0)
        drawCircle([controlArray(controlIndex,2), controlArray(controlIndex,3)], controlArray(controlIndex,4))
    else
        plot([controlArray(controlIndex,2), controlArray(controlIndex,4)], [controlArray(controlIndex,3), controlArray(controlIndex,5)], 'k');
    end

    %code to draw arcs (not full circles)
    circr = @(radius,rad_ang)  [radius*cos(rad_ang);  radius*sin(rad_ang)];         % Circle Function For Angles In Radians
    circd = @(radius,deg_ang)  [radius*cosd(deg_ang);  radius*sind(deg_ang)];       % Circle Function For Angles In Degrees
    N = 25;                                                         % Number Of Points In Complete Circle
    r_angl = linspace(pi/4, 3*pi/4, N);                             % Angle Defining Arc Segment (radians)
    radius = 1;                                                   % Arc Radius
    xy_r = circr(radius,r_angl);                                    % Matrix (2xN) Of (x,y) Coordinates
    %figure(1)
    %plot(xy_r(1,:) +4, xy_r(2,:), 'R')                                % Draw An Arc Of Blue Stars
    %axis([-1.25*radius  1.25*radius    0  1.25*radius])             % Set Axis Limits
    %axis equal                                                      % No Distortion With %axis equal’
    hold off
end