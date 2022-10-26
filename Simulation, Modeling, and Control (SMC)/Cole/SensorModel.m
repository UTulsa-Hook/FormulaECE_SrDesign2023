function XBar = SensorModel(X, U)
    persistent x_bar;
    persistent y_bar;
    persistent thetaC;
    persistent thetaDot;
    persistent vbar_hold;
    
    if(isempty(vbar_hold))
        vbar_hold = U(1);
    end
    
    rWheel = 0.025;
    doSensorModel = false;

    if(doSensorModel)
        %Create Sensor Signal
        wExpect = U(1)/rWheel;
        beta_w = 0.1; %beta_w is a constant, difference from actual value
        nw = randn(1) * 0.5;  %zero mean gaussian with std dev of sigma
        wSensor = wExpect + beta_w + nw;

        v_bar = wSensor * rWheel;
        
        %Create Sensor Signal for wheel angle
        steering_expect = U(2);
        betaS = 30; %30
        ns = randn(1) * 0.05; %30 % zero mean gaussian with a std dev of sigma
        steering_sensor = steering_expect + betaS + ns;

        if(isempty(thetaDot))
            thetaDot = U(2);
        else
            thetaDot = steering_sensor;
        end
        
        %Regenerate State Variable
        headingExpect = X(3);
        betaH = 0.01
        nh = randn(1) * 0.05;
        headingSensor = headingExpect + betaH + nh;
        thetaC = headingSensor;

        %Position will be function of integrated velocity
        if (isempty(x_bar))
            x_bar = X(1);
        else
            x_bar = x_bar + vbar_hold * dt * cos(thetaC);
        end
        
        if (isempty(y_bar))
            y_bar = X(2);
        else
            y_bar = y_bar + vbar_hold * dt * sin(thetaC);
        end
        
        XBar = [x_bar y_bar thetaC]';
        vbar_hold = v_bar;
        error = X - XBar
    else
        XBar = X;
    end
end