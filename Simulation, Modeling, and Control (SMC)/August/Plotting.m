function Plotting(X, X_bar, U, t)
%UNTITLED4 Summary of this function goes here
%   Detailed explanation goes here

    persistent xpos_handle;
    persistent ypos_handle;
    persistent vel_handle;
    persistent xbar_handle;
    persistent vbar_handle;
    persistent posError_handle;
    xbar = X_bar(1);
    vbar = X_bar(2);
    
    if t == 0
        subplot(2,2,1);
        xpos_handle = plot(t, X(1), 'k');
        hold on
        xbar_handle = plot(t, xbar, 'r');
        xlabel('t (s)')
        ylabel('x pos (m)');
        subplot(2,2,2);
        ypos_handle = plot(t, X(1), 'k');
        hold on
        xbar_handle = plot(t, xbar, 'r');
        xlabel('t (s)')
        ylabel('y pos (m)');
        subplot(2,2,3);
        vel_handle = plot(t, X(2));
        hold on
        vbar_handle = plot(t, vbar, 'r');
        xlabel('t (s)')
        ylabel('vel (m/s)');
        subplot(2,2,4)
        posError_handle = plot(t, xbar-X(1), 'k');
        xlabel('t(s)')
        ylabel('pos error (m)')
    else
        set(xpos_handle, 'Xdata', [get(xpos_handle,'Xdata') t], 'Ydata', [get(xpos_handle,'Ydata') X(1)])
        set(ypos_handle, 'Xdata', [get(ypos_handle,'Xdata') t], 'Ydata', [get(ypos_handle,'Ydata') X(2)])
        set(vel_handle, 'Xdata', [get(vel_handle,'Xdata') t], 'Ydata', [get(vel_handle,'Ydata') X(3)])
        set(xbar_handle, 'Xdata', [get(xbar_handle,'Xdata') t], 'Ydata', [get(xbar_handle,'Ydata') xbar])
        set(vbar_handle, 'Xdata', [get(vbar_handle,'Xdata') t], 'Ydata', [get(vbar_handle,'Ydata') vbar])
        set(posError_handle, 'Xdata', [get(posError_handle,'Xdata') t], 'Ydata', [get(posError_handle,'Ydata') xbar-X(1)])
    end
end