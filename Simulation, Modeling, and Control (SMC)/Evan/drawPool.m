function drawPool()
%DRAWPOOL Summary of this function goes here
% draws the pool environment
poolXLims = [0 11.7]';
poolYLims = [0 13.4]';
rampXLims = [0 4.1]';
rampYLims = [11.8 13.4]';
controlLine = [1 0; 8 7];

hold on
plot([poolXLims(1), rampXLims(1), rampXLims(2), rampXLims(2), poolXLims(2), poolXLims(2), poolXLims(1)], [poolYLims(1), rampYLims(1), rampYLims(1), poolYLims(2), poolYLims(2), poolYLims(1), poolYLims(1)], 'black' , 'LineWidth', 3);
plot(controlLine(:,1), controlLine(:,2), 'R');
hold off
end