function U = controlCircle(X_bar, resetIntegral)
%UNTITLED3 Summary of this function goes here
%   Detailed explanation goes here
    global controlArray;
    global controlIndex;
    global velocity;
    global dt;
    persistent lineToFollow;
    persistent oldD;
    persistent integralFactor;
    
    if(isempty(oldD))
        oldD = 0;
        integralFactor = 0;
    end

    if(resetIntegral == 1)
        integralFactor = 0;
    end

    x = X_bar(1);
    y = X_bar(2);
    thetaC = X_bar(3);
    
    lambda = controlArray(controlIndex,5);
    Rcirc = controlArray(controlIndex,4);
    center = [controlArray(controlIndex,2); controlArray(controlIndex,3)];
    Rcar = norm(center - [x;y]);

    error = Rcar - Rcirc;

    kp = 0.4;
    kd = .5;
    ki = 0.000005;
    deriv = (error-oldD)/dt;
    
    %set the steering angle with PD controller to steer towards line
    thetaS = error*kp + integralFactor * ki + kd*deriv;
    U(1) = velocity; %velocity
    U(2) = thetaS; 
    oldD = error;
    integralFactor = integralFactor + error/dt;
end