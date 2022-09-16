function X_bar = SensorModel(X)
%UNTITLED Summary of this function goes here
%   Detailed explanation goes here

    persistent x_bar;
    persistent vbar_hold;
    
    if(isempty(vbar_hold))
        vbar_hold = 0.0;
    end
r_wheel = .025;
dt = .1;
% velocity measurement will be a function of wheel encoder
% linear velocity = Wheel radius * angular velocity of (w) wheel

%Generate a sensor reading
w_expect = X(2)/r_wheel;
beta_w = 30;
n_w = randn(1) * 30; % zero mean gaussian with a std dev of sigma
w_sensor = w_expect + beta_w + n_w;

%Regenerate the state variable
v_bar = w_sensor * r_wheel;



% Position measurement will be a function of integrated velocity
if (isempty(x_bar))
    x_bar = X(1);
else
    x_bar = x_bar + vbar_hold * dt;
end


X_bar = [x_bar v_bar]';
vbar_hold = v_bar;
end

