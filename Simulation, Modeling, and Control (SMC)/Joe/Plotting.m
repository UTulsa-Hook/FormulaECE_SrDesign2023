% function Plotting(X,X_bar, U, t)
% %UNTITLED4 Summary of this function goes here
% %   Detailed explanation goes here
% 
% 
%     persistent pos_handle;
%     persistent vel_handle;
%     if t == 0
%         subplot(2,1,1);
%         pos_handle = plot(t, X(1));
%         xlabel('t (s)')
%         ylabel('pos (m)')
% 
%         subplot(2,1,2);
%         vel_handle = plot(t, X(2));
%          xlabel('t (s)')
%          ylabel('vel (m/s)')
% 
%     else 
%         set(pos_handle, 'Xdata', [get(pos_handle,'Xdata') t], 'Ydata', [get(pos_handle,'Ydata') X(1)])
%         set(vel_handle, 'Xdata', [get(vel_handle,'Xdata') t], 'Ydata', [get(vel_handle,'Ydata') X(2)])
%     end
% 
% end
function Plotting(X, X_bar, U, t)
%UNTITLED4 Summary of this function goes here
%   Detailed explanation goes here

    persistent xpos_handle;
    persistent ypos_handle;
    persistent vel_handle;
    persistent xbar_handle;
    persistent ybar_handle;
    persistent vbar_handle;
    persistent x_posError_handle;
    persistent y_posError_handle;
    xbar = X_bar(1);
    vbar = U(1);
    
    if t == 0
        subplot(2,2,1);
        xpos_handle = plot(t, X(1), 'k')
        hold on
        xbar_handle = plot(t, X_bar(1), 'r');
        xlabel('t (s)')
        ylabel('x pos (m)');
        subplot(2,2,2);
        ypos_handle = plot(t, X(2), 'k');
        hold on
        ybar_handle = plot(t, X_bar(2), 'r');
        xlabel('t (s)')
        ylabel('y pos (m)');
        subplot(2,2,4);
        %vel_handle = plot(t, U(1));
%         hold on
%         vbar_handle = plot(t, vbar, 'r');
%         xlabel('t (s)')
%         ylabel('vel (m/s)');
        y_posError_handle = plot(t, X_bar(2)-X(2), 'k');
        xlabel('t(s)')
        ylabel('y pos error (m)')
        subplot(2,2,3)
        x_posError_handle = plot(t, X_bar(1)-X(1), 'k');
        xlabel('t(s)')
        ylabel('x pos error (m)')
    else
        set(xpos_handle, 'Xdata', [get(xpos_handle,'Xdata') t], 'Ydata', [get(xpos_handle,'Ydata') X(1)])
        set(ypos_handle, 'Xdata', [get(ypos_handle,'Xdata') t], 'Ydata', [get(ypos_handle,'Ydata') X(2)])
        %set(vel_handle, 'Xdata', [get(vel_handle,'Xdata') t], 'Ydata', [get(vel_handle,'Ydata') X(3)])
        set(xbar_handle, 'Xdata', [get(xbar_handle,'Xdata') t], 'Ydata', [get(xbar_handle,'Ydata') X_bar(1)])
        set(ybar_handle, 'Xdata', [get(ybar_handle,'Xdata') t], 'Ydata', [get(ybar_handle,'Ydata') X_bar(2)])
        set(vbar_handle, 'Xdata', [get(vbar_handle,'Xdata') t], 'Ydata', [get(vbar_handle,'Ydata') vbar])
        set(x_posError_handle, 'Xdata', [get(x_posError_handle,'Xdata') t], 'Ydata', [get(x_posError_handle,'Ydata') X_bar(1)-X(1)])
        set(y_posError_handle, 'Xdata', [get(y_posError_handle,'Xdata') t], 'Ydata', [get(y_posError_handle,'Ydata') X_bar(2)-X(2)])
    end
end
