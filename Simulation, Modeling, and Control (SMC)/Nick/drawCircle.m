function drawCircle(C, R)
i = 0:20;
    P = C + [cos(2*pi/20*i)*R; sin(2*pi/20*i)*R];
    plot(P(1,:), P(2,:), 'R')
end