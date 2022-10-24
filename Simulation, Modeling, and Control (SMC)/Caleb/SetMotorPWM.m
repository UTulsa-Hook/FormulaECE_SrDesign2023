function PWM = SetMotorPWM(U)
%UNTITLED9 Summary of this function goes here
%   Detailed explanation goes here
driveCurvePWM = [];
steerCurvePWM = [];

if(isempty(Ubar_hold))
    Ubar_hold = 0;
    uncert = [0 0];
end

driveCurve = U_bar(1);
steerCurve = rad2deg(U_bar(2))

while(steerCurve < -180 || steerCurve > 180)
    if(steerCurve < -180)
        steerCurve = steerCurve + 360;
    elseif(steerCurve > 180)
        steerCurve = steerCurve - 360;
    end
end

steerCurve = steerCurve + 90;

for i = 1:size(driveTable, 1)
    if(isempty(driveCurvePWM) && driveCurve >= 0.3 + driveTable(i, 2) && driveCurve <= -0.3 + driveTable(i, 2))
        U(1) = driveTable(i,2); %set the velocity in the model to a possible velocity based on the curves
        driveCurvePWM = driveTable(i,1); % outputting the corresponding PWM happens here
    end
end

for i = 1:size(steerTable, 1)
    if(isempty(steerCurvePWM) && steerCurve >= 0.9 * steerTable(i, 2) && steerCurve <= 1.1 * steerTable(i, 2))
        U(2) = deg2rad(steerTable(i,2)-90); %set the velocity in the model to a possible velocity based on the curves
        steerCurvePWM = steerTable(i,1); % outputting the corresponding PWM happens here
    end
end

if(isempty(driveCurvePWM))
    driveCurvePWM = 78;
    U(1) = driveTable(1,2);
end

if(steerCurve > 130)
    steerCurvePWM = 88;
    U(2) = deg2rad(130-90); %shift max angle to center around 0
elseif(steerCurve < 45)
    steerCurvePWM = 60;
    U(2) = deg2rad(45-90); % shift min angle to center around 0
end


U = U + uncert;
Ubar_hold = U_bar;
PWMtoSend = [driveCurvePWM, steerCurvePWM];
end