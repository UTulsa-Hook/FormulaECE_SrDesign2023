function U = Control(XBar)
dt = 0.1;
persistent oldD;
if(isempty(oldD))
    oldD = 0;
end
global A;

if A < 40
    Line = [1 11; 10 2];
    xDiff = Line(1,2) - Line(1,1);
    yDiff = Line(2,2) - Line(2,1);
    angle = atan2d(yDiff, xDiff);
    R = [cosd(angle) -sind(angle) Line(1,1); sind(angle) cosd(angle)...
        Line(2,1); 0, 0, 1];
    D = inv(R) *[XBar(1:2);1];
    
    v = 1;
    kp = -.4;
    kd = -.3;
    deriv = (D(2)-oldD)/dt;
    
    thetaDot = D(2)*kp + kd*deriv;
    acc = 0.2; %m/s^2
    U(1) = v;
    U(2) = thetaDot; %velocity
    oldD = D(2);
    
elseif (39<A) && (A<82)
    Line = [6 12; 6 6];
    xDiff = Line(1,2) - Line(1,1);
    yDiff = Line(2,2) - Line(2,1);
    angle = atan2d(yDiff, xDiff);
    R = [cosd(angle) -sind(angle) Line(1,1); sind(angle) cosd(angle)...
        Line(2,1); 0, 0, 1];
    D = inv(R) *[XBar(1:2);1];
    
    v = 1;
    kp = -.4;
    kd = -.22;
    deriv = (D(2)-oldD)/dt;
    
    thetaDot = D(2)*kp + kd*deriv;
    acc = 0.2; %m/s^2
    U(1) = v;
    U(2) = thetaDot; %velocity
    oldD = D(2);

elseif A>81
    C = 1
    Line = [11 12; 6 0];
    xDiff = Line(1,2) - Line(1,1);
    yDiff = Line(2,2) - Line(2,1);
    angle = atan2d(yDiff, xDiff);
    R = [cosd(angle) -sind(angle) Line(1,1); sind(angle) cosd(angle)...
        Line(2,1); 0, 0, 1];
    D = inv(R) *[XBar(1:2);1];
    
    v = 1;
    kp = -.4;
    kd = -.5;
    deriv = (D(2)-oldD)/dt;
    
    thetaDot = D(2)*kp + kd*deriv;
    acc = 0.2; %m/s^2
    U(1) = v;
    U(2) = thetaDot; %velocity
    oldD = D(2);

end

end