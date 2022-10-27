function U = controlCircle(X_bar, resetIntegral)
%controlCircle - controls the car around the circle
    global controlArray;
    global controlIndex;
    global dt;
    global v;
    persistent oldD;
    persistent integral;
    persistent integralPlot;
    persistent t;
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
%     plotting = true;
%     if (isempty(t))
%         t = 0;
%     end
%     if(plotting)
%         if t == 0
%             integralPlot = plot(t, integral, 'k')
%             hold on
%             xlabel('t (s)')
%             ylabel('Integral Component of Controller');
%         else
%             set(integralPlot, 'Xdata', [get(integralPlot,'Xdata') t], 'Ydata', [get(integralPlot,'Ydata') integral])
%         end
%         t = t + dt;
%     end
end

