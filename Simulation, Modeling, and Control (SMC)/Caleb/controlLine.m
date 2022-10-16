function U = controlLine(X_bar)
    global dt;
    global controlArray;
    global controlIndex;
    global velocity;
    persistent oldD;
    persistent lineToFollow;
    if(isempty(oldD))
        oldD = 0;
    end

%     lineToFollow1 = [1 1; 9 2]; %controlLine1 = [1 9; 1 2];
%     lineToFollow2 = [1 9; 2 2]; %controlLine2 = [9 2; 1 2]; 
%     lineToFollow3 = [9 9; 2 5]; %controlLine3 = [9 5; 9 2]; 
%     lineToFollow4 = [9 5; 5 5]; %controlLine4 = [9 5; 5 5]; 
%     lineToFollow5 = [5 5; 5 9]; %controlLine5 = [5 9; 5 5]; 
%     lineToFollow6 = [5 1; 9 9]; %controlLine6 = [5 9; 1 9]; 
    
    %lineToFollow = lineToFollow1;
    
%     halfPlane1 = dot([X_bar(1);X_bar(2)]-[lineToFollow1(1,2);lineToFollow1(2,2)],[0 -1]);
%     halfPlane2 = dot([X_bar(1);X_bar(2)]-[lineToFollow2(1,2);lineToFollow2(2,2)],[1 0]);
%     halfPlane3 = dot([X_bar(1);X_bar(2)]-[lineToFollow3(1,2);lineToFollow3(2,2)],[0 1]);
%     halfPlane4 = dot([X_bar(1);X_bar(2)]-[lineToFollow4(1,2);lineToFollow4(2,2)],[-1 0]);
%     halfPlane5 = dot([X_bar(1);X_bar(2)]-[lineToFollow5(1,2);lineToFollow5(2,2)],[0 1]);
%     halfPlane6 = dot([X_bar(1);X_bar(2)]-[lineToFollow6(1,2);lineToFollow6(2,2)],[-1 0]);
%     if halfPlane1 > 0 && halfPlane2 < 0
%         lineToFollow = lineToFollow2;
%         halfPlane2 = dot([X_bar(1);X_bar(2)]-[lineToFollow2(1,2);lineToFollow2(2,2)],[1 0]);
%     elseif halfPlane2 > 0 && halfPlane3 < 0
%         lineToFollow = lineToFollow3;
%     elseif halfPlane3 > 0 && halfPlane4 < 0
%         lineToFollow = lineToFollow4;
%     elseif halfPlane4 > 0 && halfPlane5 < 0 && halfPlane6 < 0
%         lineToFollow = lineToFollow5;
%     elseif halfPlane5 > 0 && halfPlane6 < 0
%         lineToFollow = lineToFollow6;
%     elseif halfPlane1 < 0 && halfPlane6 > 0
%         lineToFollow = lineToFollow1;
%     end

    xdiff = controlArray(controlIndex, 4) - controlArray(controlIndex, 2);
    ydiff = controlArray(controlIndex, 5) - controlArray(controlIndex, 3);
    angle = atan2d(ydiff, xdiff);
    %create the transformation matrix world to line
    R = [cosd(angle) -sind(angle) controlArray(controlIndex, 2); 
        sind(angle) cosd(angle) controlArray(controlIndex, 3); 
        0, 0, 1];
    D = inv(R) *[X_bar(1:2);1];
    v = velocity;
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