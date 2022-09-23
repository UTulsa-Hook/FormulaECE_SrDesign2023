clf;
clear;
poolXLims = [-2 15]';
poolYLims = [0 15]';
carLocation = [9 4]';  %Car location initial point

thetaC = pi/4; %Angle of car with respect to X-axis
thetaS = pi/4; %Angle of Front Tires
thetaDot = pi/12;
move = [.1, 0]';
v=0.3;

plot([poolXLims(1), poolXLims(1), poolXLims(2), poolXLims(2), poolXLims(1)], [poolYLims(1), poolYLims(2), poolYLims(2), poolYLims(1), poolYLims(1)], 'b' , 'LineWidth', 3)
drawCar(carLocation, thetaC, thetaS);

for t = 0:8
     %Draw the pool area
     clf;
     plot([poolXLims(1), poolXLims(1), poolXLims(2), poolXLims(2), poolXLims(1)], [poolYLims(1), poolYLims(2), poolYLims(2), poolYLims(1), poolYLims(1)], 'b' , 'LineWidth', 3)
    
     %Draw the car
     thetaS = pi/4;
     thetaC = thetaC + thetaDot;
     carLocation = carLocation + [v*cos(thetaC), v*sin(thetaC)]';
     drawCar(carLocation, thetaC, thetaS);
     carLocation = carLocation + move;
     pause(.1)
end

 move = [-.4, 0]';
 for t = 0:12 
     %Draw the pool area
     clf;
     thetaS = 0;
     thetaC = pi;
     plot([poolXLims(1), poolXLims(1), poolXLims(2), poolXLims(2), poolXLims(1)], [poolYLims(1), poolYLims(2), poolYLims(2), poolYLims(1), poolYLims(1)], 'b' , 'LineWidth', 3)
    
     %Draw the car
     drawCar(carLocation, thetaC, thetaS);
     carLocation = carLocation + move;
     pause(.1)
 end

thetaDot = -pi/12;
move = [.1, 0]'
 for t = 0:5
     %Draw the pool area
     clf;
     plot([poolXLims(1), poolXLims(1), poolXLims(2), poolXLims(2), poolXLims(1)], [poolYLims(1), poolYLims(2), poolYLims(2), poolYLims(1), poolYLims(1)], 'b' , 'LineWidth', 3)
     
     %Draw the car
     thetaS = -pi/4;
     thetaC = thetaC + thetaDot;
     carLocation = carLocation + [v*cos(thetaC), v*sin(thetaC)]';
     drawCar(carLocation, thetaC, thetaS);
     carLocation = carLocation + move;
     pause(.1)
 end

  move = [0, .4]';
 for t = 0:8 
     %Draw the pool area
     clf;
     thetaS = 0;
     thetaC = pi/2;
     plot([poolXLims(1), poolXLims(1), poolXLims(2), poolXLims(2), poolXLims(1)], [poolYLims(1), poolYLims(2), poolYLims(2), poolYLims(1), poolYLims(1)], 'b' , 'LineWidth', 3)
     %Draw the car
     drawCar(carLocation, thetaC, thetaS);
     carLocation = carLocation + move;
     pause(.1);
 end

move = [.1,0]'
  for t = 0:11
     %Draw the pool area
     clf;
     plot([poolXLims(1), poolXLims(1), poolXLims(2), poolXLims(2), poolXLims(1)], [poolYLims(1), poolYLims(2), poolYLims(2), poolYLims(1), poolYLims(1)], 'b' , 'LineWidth', 3)
   
     %Draw the car
     thetaS = -pi/4;
     thetaC = thetaC + thetaDot;
     carLocation = carLocation + [v*cos(thetaC), v*sin(thetaC)]';
     drawCar(carLocation, thetaC, thetaS);
     carLocation = carLocation + move;
     pause(.1)
  end

   move = [0, -.4]';
 for t = 0:12 
     %Draw the pool area
     clf;
     thetaS = 0;
     thetaC = -pi/2;
     plot([poolXLims(1), poolXLims(1), poolXLims(2), poolXLims(2), poolXLims(1)], [poolYLims(1), poolYLims(2), poolYLims(2), poolYLims(1), poolYLims(1)], 'b' , 'LineWidth', 3)
     
     %Draw the car
     drawCar(carLocation, thetaC, thetaS);
     carLocation = carLocation + move;
     pause(.1);
 end

 move = [-.1,0]';
 for t = 0:12
     %Draw the pool area
     clf;
     plot([poolXLims(1), poolXLims(1), poolXLims(2), poolXLims(2), poolXLims(1)], [poolYLims(1), poolYLims(2), poolYLims(2), poolYLims(1), poolYLims(1)], 'b' , 'LineWidth', 3)
     
     %Draw the car
     thetaS = -pi/4;
     thetaC = thetaC + thetaDot;
     carLocation = carLocation + [v*cos(thetaC), v*sin(thetaC)]';
     drawCar(carLocation, thetaC, thetaS);
     carLocation = carLocation + move;
     pause(.1)
end
