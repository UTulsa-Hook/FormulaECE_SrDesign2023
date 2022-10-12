function U = controlCircle(X_bar, resetIntegral)
%UNTITLED3 Summary of this function goes here
%   Detailed explanation goes here
    global controlArray;
    global controlIndex;
    global velocity;
    global dt;
    persistent oldD;
    persistent integralFactor;
    persistent integralPlot;
    persistent t;

    plotting = false;

    if(plotting)
        if(isempty(t))
            t = 0;
        end
    end
    
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
    
    if(controlIndex == 14)
        ki = 0.0004;
    elseif(controlIndex == 7)
        ki = 0.0002;
    else
        ki = 0.00035;
    end

    if(lambda == 0)
        kp = -0.4;
        kd = -.5;
        ki = -ki;
    else
        kp = 0.4;
        kd = .5;
    end

    deriv = (error-oldD)/dt;
    
    %set the steering angle with PD controller to steer towards line
    thetaS = error*kp + integralFactor * ki + kd*deriv;
    U(1) = velocity; %velocity
    U(2) = thetaS; 
    oldD = error;
    integralFactor = integralFactor + error/dt

    if(plotting)
        if t == 0
            integralPlot = plot(t, integralFactor, 'k')
            hold on
            xlabel('t (s)')
            ylabel('Integral Component of Controller');
        else
            set(integralPlot, 'Xdata', [get(integralPlot,'Xdata') t], 'Ydata', [get(integralPlot,'Ydata') integralFactor])
        end
        t = t + dt;
    end
end