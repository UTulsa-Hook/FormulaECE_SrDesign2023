function H = checkHalfPlane(X_bar)
%checkHalfPlane checks to see if we have passed the halfplane
    global controlIndex;
    global controlArray;
    x = [X_bar(1);X_bar(2)]
    P = controlArray(controlIndex,8:9)';
    N = controlArray(controlIndex,6:7)';

    H = sign(dot((x-P)',N));
end