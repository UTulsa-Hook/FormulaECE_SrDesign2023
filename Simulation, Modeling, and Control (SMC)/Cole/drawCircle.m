function drawCircle(center, radius)
    i = 0:50;
    P = center' + [cos(2*pi/50*i)*radius; sin(2*pi/50*i)*radius];
    plot(P(1,:), P(2,:), 'k-')
end