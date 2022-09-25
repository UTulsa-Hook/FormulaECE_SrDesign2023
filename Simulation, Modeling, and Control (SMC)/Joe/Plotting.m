function Plotting(X, X_bar, U, t)
%UNTITLED4 Summary of this function goes here
%   Detailed explanation goes here

    persistent pos_handle;
    persistent vel_handle;
    persistent xbar_handle;
    persistent vbar_handle;
    persistent posError_handle;

    persistent pool_handle;
    persistent ramp_handle;
    persistent car_handle;

poolXLims = [0 10]';
poolYLims = [0 8]';
rampXLims =[0 4]';
rampYLims =[6 8];
carLocation = [5 1]';  %Car location in the pool frame

thetaC = 0;
thetaS = 0;
move = [.1, 0]';
v = 1;
dt = .1; %time step
ld = .27;

    xbar = X_bar(1);
    vbar = X_bar(2);
    
    if t == 0
% 
%     pool_handle = plot([poolXLims(1), poolXLims(1), poolXLims(2), poolXLims(2), poolXLims(1)], [poolYLims(1), poolYLims(2), poolYLims(2), poolYLims(1), poolYLims(1)], 'b' , 'LineWidth', 3);
%     hold on
%     ramp_handle = plot([rampXLims(1), rampXLims(1), rampXLims(2), rampXLims(2), rampXLims(1)], [rampYLims(1), rampYLims(2), rampYLims(2), rampYLims(1), rampYLims(1)], 'r' , 'LineWidth', 3);
%     car_handle = drawCar(X, thetaC, thetaS);
%     

        subplot(3,1,1);
        pos_handle = plot(t, X(1), 'k');
        hold on
        xbar_handle = plot(t, xbar, 'r');
        xlabel('t (s)')
        ylabel('pos (m)');
        subplot(3,1,2);
        vel_handle = plot(t, X(2));
        hold on
        vbar_handle = plot(t, vbar, 'r');
        xlabel('t (s)')
        ylabel('vel (m/s)');
        subplot(3,1,3)
        posError_handle = plot(t, xbar-X(1), 'k');
        xlabel('t(s)')
        ylabel('pos error (m)')
    else 
           % clear car_handle;
%           car_handle =  drawCar([X(1)*cos(0) X(1)*sin(0)]',thetaC,thetaS);
%           disp(car_handle)
          %set(car_handle, 'Xdata', X(1)*cos(0), 'Ydata', X(1)*sin(0)); 

        set(pos_handle, 'Xdata', [get(pos_handle,'Xdata') t], 'Ydata', [get(pos_handle,'Ydata') X(1)])
        set(vel_handle, 'Xdata', [get(vel_handle,'Xdata') t], 'Ydata', [get(vel_handle,'Ydata') X(2)])
        set(xbar_handle, 'Xdata', [get(xbar_handle,'Xdata') t], 'Ydata', [get(xbar_handle,'Ydata') xbar])
        set(vbar_handle, 'Xdata', [get(vbar_handle,'Xdata') t], 'Ydata', [get(vbar_handle,'Ydata') vbar])
        set(posError_handle, 'Xdata', [get(posError_handle,'Xdata') t], 'Ydata', [get(posError_handle,'Ydata') xbar-X(1)])
    end
end