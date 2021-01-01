clc;clear;
A = [1 6 7; 3 6 -2; 8 5 3];
n = length ( A (1, :));
Aug = [A, eye(n,n)];

for j = 1:n-1
	for i = j+1:n

Aug(1,j:2*n) = Aug(i,j:2*n) - Aug(i,j)/Aug(j,j)*Aug(j,j:2*n);
end
end

for j = n: -1:2
Aug(j,:) = Aug(j,:)/Aug(j,j);
end

B=Aug(:,n+1:2*n);
disp(B,"The inverse of the matrix is")
