function U = controlLine(X_bar)
%control the car around the line
    global controlIndex;
    global controlArray;
    global dt;
    global v;
    persistent oldD;
    if(isempty(oldD))
        oldD = 0;
    end    
    W1 = [controlArray(controlIndex,2), controlArray(controlIndex,3)]';
    W2 = [controlArray(controlIndex,4), controlArray(controlIndex,5)]';

%     lines = [1 0 7 4;7 4 2 8];
%     lineToFollow = lines(1,:);
    %car is in region where normal vector is pointing when positive
%     if(dot(([X_bar(1) X_bar(2)] - [lineToFollow(3) lineToFollow(4)]),[0 1]) > 0)
%         lineToFollow = lines(2,:);
%     end
    %lineToFollow;
    xdiff = W2(1) - W1(1);
    ydiff = W2(2) - W1(2);
    angle = atan2d(ydiff, xdiff);
    R = [cosd(angle) -sind(angle) W1(1);
        sind(angle) cosd(angle) W1(2);
        0, 0, 1];
    D = inv(R) *[X_bar(1:2);1];
    
    kp = -.4;
    kd = -.5;
    deriv = (D(2)-oldD)/dt;
    
    thetaS = D(2)*kp + kd*deriv;
    U(1) = v;
    U(2) = thetaS; %velocity
    oldD = D(2);
end