function Plotting(X, XBar, U, t)
    persistent xpos_handle;
    persistent ypos_handle;
    persistent vel_handle;
    persistent xbar_handle;
    persistent vbar_handle;
    persistent posError_handle;
    xbar = XBar(1);
    vbar = XBar(2);
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