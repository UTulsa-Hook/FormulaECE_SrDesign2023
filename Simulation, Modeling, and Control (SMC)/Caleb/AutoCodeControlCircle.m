function U = AutoCodeControlCircle(X, resetIntegral)
%UNTITLED7 Summary of this function goes here
%   Detailed explanation goes here
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
    oldD = 0; %persistent
    integralFactor = 0; % persistent
    
    if(isempty(oldD))
        oldD = 0;
        integralFactor = 0;
    end

    if(resetIntegral == 1)
        integralFactor = 0;
    end

    x = X(1);
    y = X(2);
    thetaC = X(3);
    
    lambda = controlArray(controlIndex,5);
    Rcirc = controlArray(controlIndex,4);
    center = [controlArray(controlIndex,2); controlArray(controlIndex,3)];
    Rcar = norm(center - [x;y]);

    error = Rcar - Rcirc;
    
    if(controlIndex == 14)
        ki = 0.0004;
    elseif(controlIndex == 7)
        ki = 0.0002;
    else
        ki = 0.00035;
        %ki = 0.5; % for testing
    end

    if(lambda == 0)
        kp = -0.4;
        kd = -.5;
        ki = -ki;
    else
        kp = 0.4;
        kd = .5;
    end
    
    if(resetIntegral == 1)
        deriv = 0;
    else
        deriv = (error-oldD)/dt;
    end
    
    %set the steering angle with PD controller to steer towards line
    thetaS = error*kp + integralFactor * ki + kd*deriv;
    U(1) = velocity; %velocity
    U(2) = thetaS; 
    oldD = error; %persistent
    integralFactor = integralFactor + error*dt; %persistent
end