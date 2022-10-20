function Plotting(X, XBar, U, t)
    persistent xpos_handle;
    persistent ypos_handle;
    persistent vel_handle;
    persistent xbar_handle;
    persistent vbar_handle;
    persistent posError_handle;
    xbar = XBar(1);
    vbar = XBar(2);
    
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
        ylabel('Position (m)');
        subplot(2,2,3);
        vel_handle = plot(t, X(2));
        hold on
        vbar_handle = plot(t, vbar, 'r');
        xlabel('t (s)')
        ylabel('Velocity (m/s)');
        subplot(2,2,4)
        posError_handle = plot(t, xbar-X(1), 'k');
        xlabel('t(s)')
        ylabel('Position Error (m)')

    else
        set(xpos_handle, 'X data', [get(xpos_handle,'X data') t], 'Y data',...
            [get(xpos_handle,'Y data') X(1)])
        set(ypos_handle, 'X data', [get(ypos_handle,'X data') t], 'Y data',...
            [get(ypos_handle,'Y data') X(2)])
        set(vel_handle, 'X data', [get(vel_handle,'X data') t], 'Y data',...
            [get(vel_handle,'Y data') X(2)])
        set(xbar_handle, 'X data', [get(xbar_handle,'X data') t], 'Y data',...
            [get(xbar_handle,'Y data') xbar])
        set(vbar_handle, 'X data', [get(vbar_handle,'X data') t], 'Y data',...
            [get(vbar_handle,'Y data') vbar])
        set(posError_handle, 'X data', [get(posError_handle,'X data') t],...
            'Ydata', [get(posError_handle,'Y data') xbar-X(1)])
    end
end