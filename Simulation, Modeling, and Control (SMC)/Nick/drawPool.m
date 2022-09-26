function drawPool(poolXLims, poolYLims)
%drawPool, draw the pool outlines
fill([poolXLims(1), poolXLims(1), poolXLims(2), poolXLims(2), poolXLims(1)], ...
    [poolYLims(1), poolYLims(2), poolYLims(2), poolYLims(1), poolYLims(1)], 'k' , 'LineWidth', 3)
end