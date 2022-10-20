clear;
clear Plotting;
clear SensorModel;
clear drawTire;
clear Control;
clf;

carLocation = [2 2]';
thetaC = 0;
thetaDot = -pi/16;
X = [carLocation(1) carLocation(2) thetaDot]';
U = [1 0];

seed = rng('shuffle');