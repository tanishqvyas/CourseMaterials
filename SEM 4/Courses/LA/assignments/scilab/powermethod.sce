clear;clc;close();
A=[6 3 5;2 7 2;7 2 9];
disp(A,"The given matrix is")
u0=[1 1 1]';
disp(u0,"The initial vector is")
v=A*u0;
a=max(u0);
disp(a,"First approximation to eigen value is");
while abs(max(v)-a)>0.002
	disp(v,"Current eigen vector is");
	a = max(v);
	disp(a,"Current eigen value is")
	u0=v/max(v);
	v=A*u0;
end
format('v',4);
disp(max(v),"the largest eigen value is")
format('v',5)
disp(u0,"The corresponding Eigen Vector is")
