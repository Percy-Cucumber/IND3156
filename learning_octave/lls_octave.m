% MATLAB code for finding the best fit using least squares method
% based on the wikipedia page on linear least squares (mathematics)
%
% get data 
%input = csvread('machine-learning-ex1/ex1/ex1data1.txt');  % local file
urlwrite('http://web.cecs.pdx.edu/~gerry/MATLAB/plotting/examples/PDXprecip.dat','data.dat');
%urlwrite('http://www.ncl.ucar.edu/Applications/Data/asc/asc2.txt','data.dat');
%urlwrite('http://www.eg.bucknell.edu/physics/ASTR201/IDLTutorial/spectrum.txt','data.dat');
input = dlmread('data.dat',"\t",1,0);  % read local file from one of the above web calls
%input = [1, 6; 2, 5; 3, 7; 4, 10; 5, 11; 0, 4; ];  % uncomment if needed
%
[m,n] = size(input);         % determine the size of the chosen set
y = input(:,2);              % form y for use in all algorithms
%
% GRADIENT DESCENT
% set global parameters
max_iter = 10000;            % maximum number of iterations
alpha = 1.0E-1;              % learning rate
tol = 1.0E-7;                % fractional gain for stopping
% straight-line fit
% assemble the necessary arrays
X = ones(m, n);              % initialize the appropriately sized X matrix
X(:,2) = input(:,1);         % fill the second column with data (the first column remains 1's)
beta = ones(n,1);            % the beta vector of feature parameters
temp = ones(n,1);            % a vector to hold the beta values until simultaneous update
scale = ones(n,1);           % a vector to hold the scaling constants
for i = 1:n
  scale(i) = max(X(:,i),[],1);  
  for j = 1:m
    X(j,i) = X(j,i) / scale(i);  % scale each value in the ith column of X---could this be vectorized?
  endfor  
endfor
gain = tol + 1.;             % initialize the gain measure as poorer than desired
count = 0;                   % initialize the iteration counter
S = 1.;                      % initialize the cost function
% the iterative loop
while ((gain > tol) & (count < max_iter))
    for i = 1:n
        temp(i) = beta(i) - alpha/m*sum( (X*beta-y)'*X(:,i) );
    endfor    
    beta = temp;
    count = count + 1;
    S = ((X*beta)-y)'*((X*beta)-y);
    gain = abs( (gain - S)/gain );
    if ( !mod(count,3000) )
        printf('After %4d counts the sum of the squares of the residuals is %.3f\n', count, S);
    endif
endwhile  
printf('Converged in %d iterations\n', count);
beta = beta ./ scale
% plotting
xx = linspace(min(input,[],1)(1), max(input,[],1)(1), 50); % auto detect min and max
yy1 = beta(1) + beta(2)*xx;
figure(1);
subplot(1,3,1);
plot(xx,yy1,'b');
title("gradient descent");
%
% 2nd degree polynomial
% assemble the necessary arrays
X = ones(m, n+1);             % build a new X with an additional column
X(:,n) = input(:,1);          % fill with data, as before
X(:,n+1) = ( input(:,1) ).^2; % fill the additional column with the 2nd degree
beta = ones(n+1,1);           % the beta vector of feature parameters
temp = ones(n+1,1);           % a vector to hold the beta values until simultaneous update
scale = ones(n+1,1);
for i = 1:n+1
  scale(i) = max(X(:,i),[],1);  % a vector to hold the scaling constants
  for j = 1:m
    X(j,i) = X(j,i) / scale(i);  % scale each value in the ith column of X---could this be vectorized?
  endfor  
endfor
gain = tol + 1.;             % initialize the gain measure as poorer than desired
count = 0;                   % initialize the iteration counter
S = 1.;                      % initialize the cost function
% the iterative loop
while ((gain > tol) & (count < max_iter))
    for i = 1:n+1
        temp(i) = beta(i) - alpha/m*sum( (X*beta-y)'*X(:,i) );
    endfor    
    beta = temp;
    count = count + 1;
    S = ((X*beta)-y)'*((X*beta)-y);
    gain = abs( (gain - S)/gain );
    if ( !mod(count,3000) )
        printf('After %4d counts the sum of the squares of the residuals is %.3f\n', count, S);
    endif
endwhile  
printf('Converged in %d iterations\n', count);
beta = beta ./ scale
% plotting
yy2 = beta(1) + beta(2)*xx + beta(3)*xx.^2;
hold on
plot(xx,yy2,'c');
hold off
hold on
plot(input(:,1), input(:,2), 'or');  % plot the points (data) for which we found the best fit
hold off
%
% NORMAL EQUATIONS
% straight-line fit
X = ones(m, n);              % initialize the appropriately sized X matrix
X(:,2) = input(:,1);         % fill the second column with data (the first remains 1's)
%beta = (X' * X) \ X' * y;    % computing projection of matrix X on y, giving beta
%beta = inv(X' * X) * X' * y; % a different inverse call
beta = pinv(X' * X) * X' * y; % a different inverse call
% disp(beta);                 % display best fit parameters
%
% plotting
yy3 = beta(1) + beta(2)*xx;
subplot(1,3,2);
plot(xx, yy3,'g');
title("normal equations");
%
%  second-degree polynomial fit
X = ones(m, n+1);             % build a new X with an additional column
X(:,n) = input(:,1);          % fill with data, as before
X(:,n+1) = ( input(:,1) ).^2; % fill the additional column with the 2nd degree
%beta = (X' * X) \ X' * y;     % the normal inversion from the wikipedia example
beta = pinv(X' * X) * X' * y; % the inversion call from coursera; aka http://cs229.stanford.edu/materials.html
%beta = inv(X' * X) * X' * y; % or with inverse rather than pseudoinverse
%disp(beta);                   % display best fit parameters
%
% plotting
yy4 = beta(1) + beta(2)*xx + beta(3)*xx.^2; % model a new 2nd degree y function
hold on
plot(xx,yy4,'m');
hold off
hold on
plot(input(:,1), input(:,2), 'or');  % plot the points (data) for which we found the best fit
hold off
%
% comparison plot
subplot(1,3,3)
plot(xx,yy2,'c')
title("comparison");
hold on
plot(xx,yy4,'m');
hold off
hold on
plot(input(:,1), input(:,2), 'or');  % plot the points (data) for which we found the best fit
hold off