function XBar = SensorModel(X, U)
dt = 0.1;
doSensorModel = false;

 persistent x_bar;
    persistent y_bar;
    persistent thetaC;
    persistent thetaDot;
    persistent vbar_hold;

    if(isempty(vbar_hold))
        vbar_hold = 0.0;
    end

rWheel = 0.025;

%Velocity will be function from wheel encoder
%Linear velocity = Wheel radius times angular velosity of w wheel

if(doSensorModel)
    %Create Sensor Signal
    wExpect = U(1)/rWheel;
    beta_w = 3; %beta_w is a constant, difference from actual value
    nw = randn(1) * 40;  %zero mean gaussian with std dev of sigma
    wSensor = wExpect + beta_w + nw;

    %Create Sensor Signal for wheel angle
    steering_expect = X(4);
    beta_s = 0.1; %30
    n_s = randn(1) * 40; %30 % zero mean gaussian with a std dev of sigma
    steering_sensor = steering_expect + betaS + ns;

    thetaDot = steering_sensor;

    %Regenerate State Variable
    v_bar = wSensor * rWheel;

    if (isempty(thetaC))
        thetaC = X(3);
    else
        thetaC = thetaC + vbar_hold * dt/10;
    end

    %Position will be function of integrated velocity
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

    XBar = [x_bar y_bar theta_bar]';
    vbar_hold = v_bar;
    else
    XBar = X;
    end