function result = checkHalfPlane(XBar)
    global Array;
    global Index;
    x = [XBar(1), XBar(2)];
    P = [Array(Index, 8), Array(Index, 9)];
    N = [Array(Index, 6), Array(Index, 7)];
    result = sign(dot((x - P)', N))

end