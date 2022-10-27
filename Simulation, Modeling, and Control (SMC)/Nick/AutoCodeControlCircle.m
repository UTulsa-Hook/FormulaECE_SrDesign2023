        function U = AutoCodeControlCircle(X_bar, resetIntegral)
U = [0 0]
%controlCircle - controls the car around the circle
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
dt = .1
v= 1;
%     persistent oldD;
oldD = 0;
integral = 0;
%     persistent integral;
    if(isempty(oldD))
        oldD = 0;
        integral = 0;
        %integral = .179525;
    end
    x = X_bar(1);
    y = X_bar(2);
    theta = X_bar(3);
    lambda = controlArray(controlIndex, 5);
    Rcirc = controlArray(controlIndex,4);
    C = [controlArray(controlIndex,2); controlArray(controlIndex,3)];
    Rcar = norm(C - [x;y]);
    error = Rcar - Rcirc;
    
    if (lambda ==0)
        kp = -.4;
        kd = -.5;
        ki = -.005;
    else
        kp = .4;
        kd = .5;
        ki = .005;
    end
    
    if(resetIntegral == 1)
        integral = 0;
        deriv = 0;
    else
        deriv = (error-oldD)/dt;
    end

    
    thetaS = error*kp + integral* ki +kd*deriv;
    U(1) = v;
    U(2) = thetaS; %velocity
    oldD = error;
    integral = integral + error*dt;
end

