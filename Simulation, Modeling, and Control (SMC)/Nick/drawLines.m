function drawLines()
global controlArray;
global controlIndex;
%Draws the control line for the car to follow
%controlLine = [1 0 7 4; 7 4 2 8];
%plot([controlLine(1,1) controlLine(1,3)], [controlLine(1,2) controlLine(1,4)], 'R');
%plot([controlLine(2,1) controlLine(2,3)], [controlLine(2,2) controlLine(2,4)], 'R');
if(controlArray(controlIndex,1) == 0) % circle
    drawCircle([controlArray(controlIndex,2);controlArray(controlIndex,3)],controlArray(controlIndex,4))
else
    plot([controlArray(controlIndex,2);controlArray(controlIndex,4)],[controlArray(controlIndex,3);controlArray(controlIndex,5)])
end
