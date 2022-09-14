function Plotting(X, X_bar, U, t)
%UNTITLED4 Summary of this function goes here
%   Detailed explanation goes here

    persistent pos_handle;
    persistent vel_handle;
    
    if t == 0
        subplot(2,1,1);
        pos_handle = plot(t, X(1));
        xlabel('t (s)')
        ylabel('pos (m)');
        subplot(2,1,2);
        vel_handle = plot(t, X(2));
        xlabel('t (s)')
        ylabel('vel (m/s)');
    else
        set(pos_handle, 'Xdata', [get(pos_handle,'Xdata') t], 'Ydata', [get(pos_handle,'Ydata') X(1)])
        set(vel_handle, 'Xdata', [get(vel_handle,'Xdata') t], 'Ydata', [get(vel_handle,'Ydata') X(2)])
    end
end

