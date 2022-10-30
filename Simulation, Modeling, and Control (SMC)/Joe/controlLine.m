function U = controlLine(X_bar)
    global dt;
    global controlArray;
    global controlIndex;
    persistent oldD;
    persistent lineToFollow;
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
    
    D = inv(R) * [X_bar(1:2);1];
    v = 2;
    kp = -0.4;
    kd = -.5;
    deriv = (D(2)-oldD)/dt;
    
    %set the steering angle with PD controller to steer towards line
    thetaS = D(2)*kp + kd*deriv;
    Acc = 0.2; %m/s/s
    U(1) = v; %velocity
    U(2) = thetaS; 
    oldD = D(2);
end
