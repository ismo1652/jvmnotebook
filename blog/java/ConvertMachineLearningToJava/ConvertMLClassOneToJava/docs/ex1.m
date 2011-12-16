%% Machine Learning Online Class - Exercise 1: Linear Regression
%% From: http://www.ml-class.org/course/class/index

clear all; close all; clc

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
 %%%%% Minimize cost: j = 1 / 2m * sum( ... )
 m = length(y);
 J = 0;  
 hthetaByX = X * theta;
 dd = (hthetaByX - y) .^ 2;
J = 1 / (2 * m) * sum(dd);
end

function [theta, J_history] = gradientDescent2(X, y, theta, alpha, num_iters)
 %% Batch gradient descent  
 m = length(y);
 J_history = zeros(num_iters, 1);
 for iter = 1:num_iters    
     
    hthetaByX = X * theta;                              
    theta0 = theta(1) - (alpha / m) * sum( (hthetaByX - y) .* X(:,1) );
    theta1 = theta(2) - (alpha / m) * sum( (hthetaByX - y) .* X(:,2) );
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

theta = gradientDescent2(X, y, theta, alpha, iterations);

fprintf('Theta found by gradient descent: ');
fprintf('%f %f \n', theta(1), theta(2));

hold on;

plot(X(:,2), X * theta, '-')
legend('Training data', 'Linear regression')
hold off 

predict1 = [1, 3.5] * theta;
fprintf('For population = 35,000, we predict a profit of %f\n', predict1 * 10000);

predict2 = [1, 7] * theta;
fprintf('For population = 70,000, we predict a profit of %f\n', predict2 * 10000);

%% End of File %%

