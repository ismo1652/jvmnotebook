#################################################
# Below is the script from the mlclass
# Ex1
#################################################

 The machine learning examples from the Stanford machine learning class
 were implemented with Octave/Matlab.
 
 This package contains an implementation using Java.
 
 See:
 http://www.ml-class.org/course/class/index
  
#################################################

Output from the example:

INFO: data loaded : ex1data1.txt
INFO : ScaleX : 31.97766067648516
INFO : ScaleX : 31.97766067648516
Theta-->: -3.63029143940436, 1.166362350335582
For population = 35,000, we predict a profit of : 4519.767867701768
For population = 70,000, we predict a profit of : 45342.45012944714
For population = 140,000, we predict a profit of : 126987.81465293789
INFO : angle 49.39131956808885 rad=0.8620411483678542
INFO : 0 : 22.203
INFO : 1 : 24.147
  

#################################################

%% Machine Learning Online Class - Exercise 1: Linear Regression

clear all; close all; clc

%% ==================== Part 1: Basic Function

function A = warmUpExercise2()
 A = eye(5);
end

function plotData2(x, y)
 figure;
 plot(x, y, 'rx', 'MarkerSize', 10);
 ylabel('Profit in $10,000s');
 xlabel('Population of City in 10,000s');
end

function J = computeCost2(X, y, theta)
 m = length(y);
 J = 0;  
 htheta = X * theta;
 dd = (htheta - y) .^ 2;
J = 1 / (2 * m) * sum(dd);
end

function [theta, J_history] = gradientDescent2(X, y, theta, alpha, num_iters)
 m = length(y);
 J_history = zeros(num_iters, 1);
 for iter = 1:num_iters
    htheta = X * theta;
    theta0 = theta(1) - alpha / m * sum((htheta - y) .* X(:,1));
    theta1 = theta(2) - alpha / m * sum((htheta - y) .* X(:,2));
    theta  = [theta0; theta1];     
    J_history(iter) = computeCost(X, y, theta);
 end
end

warmUpExercise2()

%% ======================= Part 2: Plotting

fprintf('Plotting Data ...\n')
data = load('ex1data1.txt');

X = data(:, 1); 
y = data(:, 2);
m = length(y);

plotData2(X, y);

%% =================== Part 3: Gradient descent

fprintf('Running Gradient Descent ...\n')

X = [ones(m, 1), data(:,1)];
theta = zeros(2, 1);

iterations = 1500;
alpha = 0.01;

computeCost2(X, y, theta)

theta = gradientDescent2(X, y, theta, alpha, iterations);

fprintf('Theta found by gradient descent: ');
fprintf('%f %f \n', theta(1), theta(2));

hold on;

plot(X(:,2), X * theta, '-')
legend('Training data', 'Linear regression')
hold off 

predict1 = [1, 3.5] * theta;
fprintf('For population = 35,000, we predict a profit of %f\n', predict1*10000);

predict2 = [1, 7] * theta;
fprintf('For population = 70,000, we predict a profit of %f\n', predict2*10000);

#################################################
# End of the script
#################################################