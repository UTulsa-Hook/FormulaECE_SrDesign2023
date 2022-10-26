function Plotting(X, XBar, U, t)
    persistent xpos_handle;
    persistent ypos_handle;
    persistent vel_handle;
    persistent xbar_handle;
    persistent ybar_handle;
    persistent vbar_handle;
    persistent posError_handle;
    persistent xPosError_handle;
    persistent yPosError_handle;
    vbar = U(1);

    set(xpos_handle, 'X data', [get(xpos_handle,'X data') t], 'Y data',...
        [get(xpos_handle,'Y data') X(1)])
    set(ypos_handle, 'X data', [get(ypos_handle,'X data') t], 'Y data',...
        [get(ypos_handle,'Y data') X(2)])
    set(vel_handle, 'X data', [get(vel_handle,'X data') t], 'Y data',...
        [get(vel_handle,'Y data') X(2)])
    set(xbar_handle, 'X data', [get(xbar_handle,'X data') t], 'Y data',...
        [get(xbar_handle,'Y data') XBar(1)])
      set(ybar_handle, 'Xdata', [get(ybar_handle,'Xdata') t], 'Ydata',...
          [get(ybar_handle,'Ydata') X_bar(2)])
    set(vbar_handle, 'X data', [get(vbar_handle,'X data') t], 'Y data',...
        [get(vbar_handle,'Y data') vbar])
    set(xPosError_handle, 'Xdata', [get(xPosError_handle,'Xdata') t],...
        'Ydata', [get(xPosError_handle,'Ydata') XBar(1)-X(1)])
    set(yPosError_handle, 'Xdata', [get(yPosError_handle,'Xdata') t],...
        'Ydata', [get(yPosError_handle,'Ydata') XBar(2)-X(2)])
end