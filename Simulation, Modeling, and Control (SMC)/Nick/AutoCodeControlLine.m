    function U = AutoCodeControlLine(X)
%control the car around the line
U = [0 0];
D = [0 0 0]';
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
dt = .01;
v = 1;
oldD = 0;
    if(isempty(oldD))
        oldD = 0;
    end    
    W1 = [controlArray(controlIndex,2), controlArray(controlIndex,3)]';
    W2 = [controlArray(controlIndex,4), controlArray(controlIndex,5)]';


    xdiff = W2(1) - W1(1);
    ydiff = W2(2) - W1(2);
    angle = atan2d(ydiff, xdiff);
    R = [cosd(angle) -sind(angle) W1(1);
        sind(angle) cosd(angle) W1(2);
        0, 0, 1];
    %D = inv(R) *[X(1:2);1];
    
    kp = -.4;
    kd = -.5;
    deriv = (D(2)-oldD)/dt;
    thetaS = D(2)*kp + kd*deriv;
    U(1) = v;
    U(2) = thetaS; %velocity
    oldD = D(2);
end