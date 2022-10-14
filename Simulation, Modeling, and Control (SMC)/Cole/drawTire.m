function drawTire(carLoc, tireOffset, width, radius, thetaC, thetaDot, Scale)

    %perform the rotation about the car's reference frame at the origin
    X_o = Scale * [-radius, -radius, radius, radius];
    Y_o = Scale * [-width, width, width, -width];
    
    theta = thetaDot;
    cosTheta = cos(theta);
    sinTheta = sin(theta);
    
    Xrot = -X_o*cosTheta - Y_o*sinTheta;
    Yrot = Y_o*cosTheta - X_o*sinTheta;
    
    %Car reference frame translation
    translateX = ones(1, size(X_o, 2)) * tireOffset(1);
    translateY = ones(1,size(X_o, 2)) * tireOffset(2);
    X_o = Xrot + translateX;
    Y_o = Yrot + translateY;
    
    %World Reference Frame Rotation
    theta = thetaC;
    cosTheta = cos(theta);
    sinTheta = sin(theta);
    Xrot = -X_o*cosTheta - Y_o*sinTheta;
    Yrot = -X_o*sinTheta + Y_o*cosTheta;
    
    %Translate to world RF
    translateX = ones(1,size(X_o, 2)) * carLoc(1);
    translateY = ones(1,size(X_o, 2)) * carLoc(2);
    X_o = Xrot + translateX;
    Y_o = Yrot + translateY;
    
    patch(X_o, Y_o, [0.8353, 0.3843, 0.4784]); %RGB
end