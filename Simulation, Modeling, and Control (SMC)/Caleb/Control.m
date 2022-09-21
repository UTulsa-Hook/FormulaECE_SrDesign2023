function U = Control(X_bar)
%UNTITLED2 Summary of this function goes here
%   Detailed explanation goes here
Acc = 0.2; %m/s/s

U(1) = X_bar(3);
U(2) = Acc;
U(3) = 0;
U(4) = X_bar(4);
U(5) = X_bar(5); %velocity
end