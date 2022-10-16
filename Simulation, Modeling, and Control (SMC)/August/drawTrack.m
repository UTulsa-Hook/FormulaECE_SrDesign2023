function drawTrack()
%new function in place of C lines from previous control function, this
%function draws the track and keeps track of various paths that the car is
%maneuvering through

controlLine1 = [.9 9.1; 7 2]; %y
    controlLine2 = [7.8 1.6; 9 3]; %y
     controlLine3 = [9 4.6; 7 6]; %y
     controlLine4 = [7 8; 8 6.5]; %y
     controlLine5 = [9 7.5; 3 10]; 
%     controlLine6 = [2 1; 1 8];
%     controlLine7 = [9 8; 5 3];
%     controlLine8 = [8 10; 6 2];
%     controlLine9 = [2 4; 6 9];
    
    plot(controlLine1(:,1), controlLine1(:,2), 'R');
    plot(controlLine2(:,1), controlLine2(:,2), 'R');
    plot(controlLine3(:,1), controlLine3(:,2), 'R');
    plot(controlLine4(:,1), controlLine4(:,2), 'R');
     plot(controlLine5(:,1), controlLine5(:,2), 'R');
%     plot(controlLine6(:,1), controlLine6(:,2), 'R');
%     plot(controlLine7(:,1), controlLine7(:,2), 'R');
%     plot(controlLine8(:,1), controlLine8(:,2), 'R');
%     plot(controlLine9(:,1), controlLine9(:,2), 'R');

    %code to draw arcs (not full circles)
    circr = @(radius,rad_ang)  [radius*cos(rad_ang);  radius*sin(rad_ang)];         % Circle Function For Angles In Radians
    circd = @(radius,deg_ang)  [radius*cosd(deg_ang);  radius*sind(deg_ang)];       % Circle Function For Angles In Degrees
    N = 25;                                                         % Number Of Points In Complete Circle

    r_angl = linspace(7*pi/6, 3*pi/2, N);                             % Angle Defining Arc Segment (radians)
    radius = 1;                                                   % Arc Radius
    center = [7.8, 2.6];
    xy_r = circr(radius,r_angl);                                    % Matrix (2xN) Of (x,y) Coordinates
    plot(xy_r(1,:) + center(1), xy_r(2,:) + center(2), 'R')                                
    
    r_angl = linspace(23*pi/12, 25*pi/12, N); 
    radius = 3;                                                   % Arc Radius
    center = [6.1, 3.8];
    xy_r = circr(radius,r_angl);                                    % Matrix (2xN) Of (x,y) Coordinates
    plot(xy_r(1,:) + center(1), xy_r(2,:) + center(2), 'R')                               

    r_angl = linspace(pi/2, 3*pi/2, N); 
    radius = 1;                                                   % Arc Radius
    center = [7, 7];
    xy_r = circr(radius,r_angl);                                    % Matrix (2xN) Of (x,y) Coordinates
    plot(xy_r(1,:) + center(1), xy_r(2,:) + center(2), 'R')

    r_angl = linspace(3*pi/2, 2*pi, N); 
    radius = 1;                                                   % Arc Radius
    center = [8, 7.5];
    xy_r = circr(radius,r_angl);                                    % Matrix (2xN) Of (x,y) Coordinates
    plot(xy_r(1,:) + center(1), xy_r(2,:) + center(2), 'R')

    r_angl = linspace(pi/2, 9*pi/12, N); 
    radius = 3;                                                   % Arc Radius
    center = [3, 7];
    xy_r = circr(radius,r_angl);                                    % Matrix (2xN) Of (x,y) Coordinates
    plot(xy_r(1,:) + center(1), xy_r(2,:) + center(2), 'R')

%     r_angl = linspace(pi/2, pi, N); 
%     radius = 5;                                                   % Arc Radius
%     center = [7, 2];
%     xy_r = circr(radius,r_angl);                                    % Matrix (2xN) Of (x,y) Coordinates
%     plot(xy_r(1,:) + center(1), xy_r(2,:) + center(2), 'R')
% 
%     r_angl = linspace(pi/2, -pi/2, N); 
%     radius = 3;                                                   % Arc Radius
%     center = [2, 6];
%     xy_r = circr(radius,r_angl);                                    % Matrix (2xN) Of (x,y) Coordinates
%     plot(xy_r(1,:) + center(1), xy_r(2,:) + center(2), 'R')
% 
%     r_angl = linspace(pi/2, pi, N); 
%     radius = 7;                                                   % Arc Radius
%     center = [2, 4];
%     xy_r = circr(radius,r_angl);                                    % Matrix (2xN) Of (x,y) Coordinates
%     plot(xy_r(1,:) + center(1), xy_r(2,:) + center(2), 'R')
end