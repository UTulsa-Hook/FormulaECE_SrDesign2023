function PWM = AutoCodeSetMotorPWM(U)
%UNTITLED9 Summary of this function goes here
%   Detailed explanation goes here
    driveTable = [78 0.92; 80 1.56; 82 2.19; 84 2.61;]; % sample data pwm, speed;
    steerTable = [60, 45; 62, 45; 64, 55; 66, 60;...
                    68, 70; 70 75; 72 80; 74 90;...
                    76 95; 78 105; 80 110; 82 115;...
                    84 120; 86 125; 88 130;]; % sample data pwm, angle

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
        if(isempty(driveCurvePWM) && driveCurve >= 0.3 + driveTable(i, 2) && driveCurve <= -0.3 + driveTable(i, 2))
            driveCurvePWM = driveTable(i,1); % outputting the corresponding PWM happens here
        end
    end
    
    for i = 1:size(steerTable, 1)
        if(isempty(steerCurvePWM) && steerCurve >= 0.9 * steerTable(i, 2) && steerCurve <= 1.1 * steerTable(i, 2))
            steerCurvePWM = steerTable(i,1); % outputting the corresponding PWM happens here
        end
    end
    
    if(isempty(driveCurvePWM))
        driveCurvePWM = 78;
    end
    
    if(steerCurve > 130)
        steerCurvePWM = 88;
    elseif(steerCurve < 45)
        steerCurvePWM = 60;
    end
    
    PWM = [driveCurvePWM, steerCurvePWM];
end