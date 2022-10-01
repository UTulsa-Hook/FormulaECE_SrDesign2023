function drawPoolRamp()
poolXLims = [0 12]';
poolYLims = [0 13]';
rampXLims = [0 4]';
rampYLims = [11 13]';
%drawramp, draw the ramp outlines
hold on;
drawPool(poolXLims, poolYLims)

drawRamp(rampXLims, rampYLims)
drawLines();
hold off;
end