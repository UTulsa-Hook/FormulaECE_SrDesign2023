clear;
clear Plotting;
clear SensorModel;
clear drawTire;
clear Control;
clf;
carLocation = [2 2]'; %car location in pool
thetaC = 0;%car orientation
thetaS = 0;% steering angle
X = [carLocation(1) carLocation(2) thetaC]';
U = [1,0]
seed = rng('shuffle');

