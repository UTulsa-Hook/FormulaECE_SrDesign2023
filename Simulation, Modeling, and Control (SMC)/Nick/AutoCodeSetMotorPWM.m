function [PWM] = AutoCodeSetMotorPWM(U)
%MotorModels This function takes in duty cycle and outputs v, thetaS
%   Detailed explanation goes here
driveTable = [78 .92; 80 1.56; 82 2.19; 84 2.61;]; % Eriks PWM values, speed;
steerTable = [60, 45; 62, 45; 64, 55; 66, 60;...
                68, 70; 70 75; 72 80; 74 90;...
                76 95; 78 105; 80 110; 82 115;...
                84 120; 86 125; 88 130;];

driveCurvePWM = [0];
steerCurvePWM = [0];

driveCurve = U(1);
steerCurve = rad2deg(U(2));

while(steerCurve < -180 || steerCurve > 180)
    if(steerCurve < -180)
        steerCurve = steerCurve + 360;
    elseif(steerCurve > 180)
        steerCurve = steerCurve - 360;
    end
end

steerCurve = steerCurve + 90;


for i = 1:size(driveTable, 1)
    if(isempty(driveCurvePWM)&& driveCurve >= 0.5 * driveTable(i, 2) && driveCurve <= 1.5 * driveTable(i, 2))
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
    U(2) = deg2rad(130-90); %shift max angle to center around 0 b/c 90 is straight line
elseif(steerCurve < 45)
    steerCurvePWM = 60;
    U(2) = deg2rad(45-90); % shift min angle to center around 0 b/c 90 is straight line
end


if((driveCurvePWM >= 78 && driveCurvePWM <= 84) && (steerCurvePWM <= 88 && steerCurvePWM >= 60))
    % check to see if we have a valid PWM 
    print("continue as normal")

else
    U = [0 0];
    %print('An error occured in motor model. U_bar = %d: %d' + driveCurve + steerCurve);
end

rad2deg(U(2));
PWM = [driveCurvePWM, steerCurvePWM];
end
