function drawLines()
%Draws the control line for the car to follow
controlLine = [1 0 7 4; 7 4 2 8];
plot([controlLine(1,1) controlLine(1,3)], [controlLine(1,2) controlLine(1,4)], 'R');
plot([controlLine(2,1) controlLine(2,3)], [controlLine(2,2) controlLine(2,4)], 'R');