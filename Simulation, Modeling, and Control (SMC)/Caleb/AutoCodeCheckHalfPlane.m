function result = AutoCodeCheckHalfPlane(X)
%UNTITLED4 Summary of this function goes here
%   Detailed explanation goes here
    controlArray = [0, 1, 9, 1, 2, 0, -1, 1, 2; 
                            0, 2.1, 2.1, 1, 1, 1, 0, 2, 1
                            1, 2, 1, 6, 2, 1, 0, 6, 2
                            1, 6, 2, 10, 1.5, 1, 0, 9.8, 1.5
                            0, 9.9, 2.6, 1, 1, 0, 1, 10.8, 2.5
                            1, 11, 2.5, 11, 5, 0, 1, 11, 5
                            0, 10, 4.9, 1, 1, 0, -1, 9, 5
                            0, 7.9, 5.1, 1, 0, -1, 0, 8, 4
                            1, 8, 4, 4, 4.5, -1, 0, 4.2, 4.5
                            0, 4.1, 5.6, 1, 0, 0, 1, 3, 5.3
                            1, 3, 5.5, 3, 8, 0, 1, 3, 7.6
                            0, 4.1, 7.9, 1, 0, 1, 0, 3.8, 9
                            1, 4, 9, 10, 9, 1, 0, 10.1, 9
                            0, 10, 10.5, 1.5, 1, -1, 0, 10, 12
                            1, 10, 12, 6, 10, -1, 0, 6, 10
                            1, 6, 10, 2, 10, -1, 0, 2, 10
                            0, 2, 9, 1, 1, 0, -1, 1, 9];
    controlIndex = 1;

    x = [X(1), X(2)];
    P = [controlArray(controlIndex, 8), controlArray(controlIndex, 9)];
    N = [controlArray(controlIndex, 6), controlArray(controlIndex, 7)];

    result = sign(dot((x - P)', N));
end