function X_bar = SensorModel(X, U)
%UNTITLED Summary of this function goes here
%   Detailed explanation goes here

    persistent x_bar;
    persistent y_bar;
    persistent thetaC;
    persistent thetaS;
    persistent vbar_hold;
    
    if(isempty(vbar_hold))
        vbar_hold = 0.0;
    end
r_wheel = .025;
dt = .1;
doSensorModel = false;
% velocity measurement will be a function of wheel encoder
% linear velocity = Wheel radius * angular velocity of (w) wheel
if(doSensorModel)
    %Generate a sensor reading
    w_expect = U(1)/r_wheel;
    beta_w = 30; %30
    n_w = randn(1) * 0.5; %30 % zero mean gaussian with a std dev of sigma
    w_sensor = w_expect + beta_w + n_w;
    
    %Generate a sensor reading for wheel turn angle
    steering_expect = X(4);
    beta_s = 0.1; %30
    n_s = randn(1) * 0.05; %30 % zero mean gaussian with a std dev of sigma
    steering_sensor = steering_expect + beta_s + n_s;
    
    thetaS = steering_sensor;
    
    %Regenerate the state variable
    v_bar = w_sensor * r_wheel;
    
    if (isempty(thetaC))
        thetaC = X(3);
    else
        thetaC = thetaC + vbar_hold * dt/10; %atan(X(5)*sin(thetaC)/(X(5)*cos(thetaC)))
    end
    
    % Position measurement will be a function of integrated velocity
    if (isempty(x_bar))
        x_bar = X(1);
    else
        x_bar = x_bar + vbar_hold * dt;
    end
    
    if (isempty(y_bar))
        y_bar = X(2);
    else
        y_bar = y_bar + vbar_hold * dt;
    end
    
    
    X_bar = [x_bar y_bar theta_bar]';
    vbar_hold = v_bar;
else
    X_bar = X;
end
