function X_bar = SensorModel(X, U)
%UNTITLED Summary of this function goes here
%   Detailed explanation goes here

    persistent x_bar;
    persistent y_bar;
    persistent thetaC;
    persistent thetaS;
    persistent vbar_hold;
    if(isempty(vbar_hold))
        vbar_hold = U(1);
    end
r_wheel = .025;
dt = .01;
doSensorModel = true;
% velocity measurement will be a function of wheel encoder
% linear velocity = Wheel radius * angular velocity of (w) wheel
if(doSensorModel)
    %Generate a sensor reading
    w_expect = 1/r_wheel;
    beta_w = 0.1; 
    n_w = randn(1) * .5; % zero mean gaussian with a std dev of sigma
    w_sensor = w_expect + beta_w + n_w;
    v_bar = w_sensor * r_wheel;
    
    c_expect = X(3);
    beta_c = 0.01;
    n_c = randn(1) * .05;
    if (isempty(thetaC))
        thetaC = X(3);
    else
        thetaC = c_expect + n_c + beta_c; 
    end
        
    % Position measurement will be a function of integrated velocity
    if (isempty(x_bar))
        x_bar = X(1);
    else
        x_bar = x_bar + cos(thetaC) * vbar_hold * dt;
    end
    
    if (isempty(y_bar))
        y_bar = X(2);
    else
        y_bar = y_bar + sin(thetaC) * vbar_hold * dt;
    end
    
    
    X_bar = [x_bar y_bar X(3)]';
    vbar_hold = v_bar;
else
    X_bar = X;
end