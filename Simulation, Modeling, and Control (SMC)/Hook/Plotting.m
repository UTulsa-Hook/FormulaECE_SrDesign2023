function Plotting(X, X_bar, U, t)
%UNTITLED4 Summary of this function goes here
%   Detailed explanation goes here

    persistent pos_handle;
    persistent vel_handle;
    persistent xbar_handle;
    persistent vbar_handle;
    persistent posError_handle;
    xbar = X_bar(1);
    vbar = X_bar(2);
    
    if t == 0
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
        set(pos_handle, 'Xdata', [get(pos_handle,'Xdata') t], 'Ydata', [get(pos_handle,'Ydata') X(1)])
        set(vel_handle, 'Xdata', [get(vel_handle,'Xdata') t], 'Ydata', [get(vel_handle,'Ydata') X(2)])
        set(xbar_handle, 'Xdata', [get(xbar_handle,'Xdata') t], 'Ydata', [get(xbar_handle,'Ydata') xbar])
        set(vbar_handle, 'Xdata', [get(vbar_handle,'Xdata') t], 'Ydata', [get(vbar_handle,'Ydata') vbar])
        set(posError_handle, 'Xdata', [get(posError_handle,'Xdata') t], 'Ydata', [get(posError_handle,'Ydata') xbar-X(1)])
    end
end

