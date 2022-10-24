function U = AutoCodeControlLine(X_bar)
    controlArray = [1, 1, 9, 1, 2, 0, -1, 1, 2; 
                            0, 2.1, 2.1, 1, 1, 1, 0, 2, 1
                            1, 2, 1, 6, 2, 1, 0, 6, 2
                            1, 6, 2, 10, 1.5, 1, 0, 9.8, 1.5
                            0, 9.9, 2.6, 1, 1, 0, 1, 10.8, 2.5
                            1, 11, 2.5, 11, 5, 0, 1, 11, 5
                            0, 10, 4.9, 1, 1, 0, -1, 9, 5
                            0, 7.9, 5.1, 1, 0, -1, 0, 8, 4
                            1, 8, 4, 4, 4.5, -1, 0, 4.2, 4.5
                            0, 4.1, 5.6, 1, 0, 0, 1, 3, 5.3
                            1, 3, 5.5, 3, 8, 0, 1, 3, 7.6
                            0, 4.1, 7.9, 1, 0, 1, 0, 3.8, 9
                            1, 4, 9, 10, 9, 1, 0, 10.1, 9
                            0, 10, 10.5, 1.5, 1, -1, 0, 10, 12
                            1, 10, 12, 6, 10, -1, 0, 6, 10
                            1, 6, 10, 2, 10, -1, 0, 2, 10
                            0, 2, 9, 1, 1, 0, -1, 1, 9];
    controlIndex = 1;
    U = [0 0];

    velocity = 1;
    dt = 0.1;
    oldD = 0; % persistent

    if(isempty(oldD))
        oldD = 0;
    end

    xdiff = controlArray(controlIndex, 4) - controlArray(controlIndex, 2);
    ydiff = controlArray(controlIndex, 5) - controlArray(controlIndex, 3);
    angle = atan2d(ydiff, xdiff);
    %create the transformation matrix world to line
    R = [cosd(angle) -sind(angle) controlArray(controlIndex, 2); 
        sind(angle) cosd(angle) controlArray(controlIndex, 3); 
        0, 0, 1];
    D = inv(R) *[X_bar(1); X_bar(2);1];
    v = velocity;
    kp = -0.4; %-0.4
    kd = -.5; % -0.5
    deriv = (D(2)-oldD)/dt;
    
    %set the steering angle with PD controller to steer towards line
    thetaS = D(2)*kp + kd*deriv;
    U(1) = v; %velocity
    U(2) = thetaS; 
    oldD = D(2); %persistent
end