function drawTrack()
%UNTITLED Summary of this function goes here
%   Detailed explanation goes here
    controlLine1 = [1 9; 1 2];
    controlLine2 = [11 2.5; 11 5]; 
    controlLine3 = [2 1; 6 2]; 
    controlLine4 = [6 2; 10 1.5]; 
    controlLine5 = [8 4; 4 4.5]; 
    controlLine6 = [3 5.5; 3 8];
    controlLine7 = [4 9; 10 9];
    controlLine8 = [10 12; 6 10];
    controlLine9 = [6 10; 2 10];
    
    plot(controlLine1(:,1), controlLine1(:,2), 'R');
    plot(controlLine2(:,1), controlLine2(:,2), 'R');
    plot(controlLine3(:,1), controlLine3(:,2), 'R');
    plot(controlLine4(:,1), controlLine4(:,2), 'R');
    plot(controlLine5(:,1), controlLine5(:,2), 'R');
    plot(controlLine6(:,1), controlLine6(:,2), 'R');
    plot(controlLine7(:,1), controlLine7(:,2), 'R');
    plot(controlLine8(:,1), controlLine8(:,2), 'R');
    plot(controlLine9(:,1), controlLine9(:,2), 'R');

    %code to draw arcs (not full circles)
    circr = @(radius,rad_ang)  [radius*cos(rad_ang);  radius*sin(rad_ang)];         % Circle Function For Angles In Radians
    circd = @(radius,deg_ang)  [radius*cosd(deg_ang);  radius*sind(deg_ang)];       % Circle Function For Angles In Degrees
    N = 25;                                                         % Number Of Points In Complete Circle
    r_angl = linspace(pi, 3*pi/2, N);                             % Angle Defining Arc Segment (radians)
    radius = 1;                                                   % Arc Radius
    center = [2, 2];
    xy_r = circr(radius,r_angl);                                    % Matrix (2xN) Of (x,y) Coordinates
    plot(xy_r(1,:) + center(1), xy_r(2,:) + center(2), 'R')                                % Draw An Arc Of Blue Stars
    
    r_angl = linspace(3*pi/2, 2*pi, N); 
    radius = 1;                                                   % Arc Radius
    center = [10, 2.5];
    xy_r = circr(radius,r_angl);                                    % Matrix (2xN) Of (x,y) Coordinates
    plot(xy_r(1,:) + center(1), xy_r(2,:) + center(2), 'R')                                % Draw An Arc Of Blue Stars

    r_angl = linspace(0, pi, N); 
    radius = 1;                                                   % Arc Radius
    center = [10, 5];
    xy_r = circr(radius,r_angl);                                    % Matrix (2xN) Of (x,y) Coordinates
    plot(xy_r(1,:) + center(1), xy_r(2,:) + center(2), 'R')

    r_angl = linspace(3*pi/2, 2*pi, N); 
    radius = 1;                                                   % Arc Radius
    center = [8, 5];
    xy_r = circr(radius,r_angl);                                    % Matrix (2xN) Of (x,y) Coordinates
    plot(xy_r(1,:) + center(1), xy_r(2,:) + center(2), 'R')

    r_angl = linspace(pi, 3*pi/2, N); 
    radius = 1;                                                   % Arc Radius
    center = [4, 5.5];
    xy_r = circr(radius,r_angl);                                    % Matrix (2xN) Of (x,y) Coordinates
    plot(xy_r(1,:) + center(1), xy_r(2,:) + center(2), 'R')

    r_angl = linspace(pi/2, pi, N); 
    radius = 1;                                                   % Arc Radius
    center = [4, 8];
    xy_r = circr(radius,r_angl);                                    % Matrix (2xN) Of (x,y) Coordinates
    plot(xy_r(1,:) + center(1), xy_r(2,:) + center(2), 'R')

    r_angl = linspace(pi/2, -pi/2, N); 
    radius = 1.5;                                                   % Arc Radius
    center = [10, 10.5];
    xy_r = circr(radius,r_angl);                                    % Matrix (2xN) Of (x,y) Coordinates
    plot(xy_r(1,:) + center(1), xy_r(2,:) + center(2), 'R')

    r_angl = linspace(pi/2, pi, N); 
    radius = 1;                                                   % Arc Radius
    center = [2, 9];
    xy_r = circr(radius,r_angl);                                    % Matrix (2xN) Of (x,y) Coordinates
    plot(xy_r(1,:) + center(1), xy_r(2,:) + center(2), 'R')
end
