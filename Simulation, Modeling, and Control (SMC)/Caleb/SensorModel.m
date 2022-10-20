function X_bar = SensorModel(X, U)
%UNTITLED Summary of this function goes here
%   Detailed explanation goes here
    global dt;
    persistent x_bar;
    persistent y_bar;
    persistent thetaC;
    persistent thetaS;
    persistent vbar_hold;
    
    if(isempty(vbar_hold))
        vbar_hold = U(1);
    end
r_wheel = .025;
doSensorModel = false;
% velocity measurement will be a function of wheel encoder
% linear velocity = Wheel radius * angular velocity of (w) wheel
if(doSensorModel)
    %Generate a sensor reading
    w_expect = U(1)/r_wheel;
    beta_w = 30; %30 %bias 
    n_w = randn(1) * 5; %30 % zero mean gaussian with a std dev of sigma
    w_sensor = w_expect + beta_w + n_w;

    %Regenerate the state variable
    v_bar = w_sensor * r_wheel;
    
    %Generate a sensor reading for wheel turn angle
    steering_expect = U(2);
    beta_s = 30; %30
    n_s = randn(1) * 0.05; %30 % zero mean gaussian with a std dev of sigma
    steering_sensor = steering_expect + beta_s + n_s;
    if(isempty(thetaS))
        thetaS = U(2);
    else
        thetaS = steering_sensor;
    end

    %Generate a sensor reading for car heading
    heading_expect = X(3);
    beta_h = 0.01; %30
    n_h = randn(1) * 0.05; %30 % zero mean gaussian with a std dev of sigma
    heading_sensor = heading_expect + beta_h + n_h;
    
    thetaC = heading_sensor;
   
    
    % Position measurement will be a function of integrated velocity
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
    
    
    X_bar = [x_bar y_bar thetaC]';
    vbar_hold = v_bar;
    error = X - X_bar;
else
    X_bar = X;
end