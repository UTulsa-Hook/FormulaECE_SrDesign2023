function drawRamp(rampXLims, rampYLims)
%drawramp, draw the ramp outlines
fill([rampXLims(1), rampXLims(1), rampXLims(2), rampXLims(2), rampXLims(1)], ...
    [rampYLims(1), rampYLims(2),rampYLims(2), rampYLims(1), rampYLims(1)], 'y' , 'LineWidth', 3)
end