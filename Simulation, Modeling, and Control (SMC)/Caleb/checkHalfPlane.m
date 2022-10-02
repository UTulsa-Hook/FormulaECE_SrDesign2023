function result = checkHalfPlane(X_bar)
%UNTITLED4 Summary of this function goes here
%   Detailed explanation goes here
    global controlArray;
    global controlIndex;
    x = [X_bar(1), X_bar(2)];
    P = [controlArray(controlIndex, 8), controlArray(controlIndex, 9)];
    N = [controlArray(controlIndex, 6), controlArray(controlIndex, 7)];

    %result = sign((x - P)' * N);
    result = sign(dot((x - P)', N));
end