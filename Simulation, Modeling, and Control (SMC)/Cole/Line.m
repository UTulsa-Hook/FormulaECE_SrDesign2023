function U = Line(XBar)
    global Array;
    global Index;
    global dt;
    global v;

    persistent oldD;

    if(isempty(oldD))
        oldD = 0;
    end
    
    A = [Array(Index, 2), Array(Index, 3)]';
    B = [Array(Index, 4), Array(Index, 5)]';
    
    deltaX = B(1) - A(1);
    deltaY = B(2) - A(2);
    
    angle = atan2d(deltaY, deltaX)
    R = [cosd(angle) -sind(angle) A(1);...
        sind(angle) cosd(angle) B(2);...
        0, 0, 1];
    D = inv(R) *[XBar(1:2); 1]
    v = 2;
    kp = -0.4;
    kd = -0.5;
    deriv = (D(2)-oldD)/dt
    thetaDot = (D(2) * kp) + (kd * deriv)
    U(1) = v
    U(2) = thetaDot
    oldD = D(2);
end