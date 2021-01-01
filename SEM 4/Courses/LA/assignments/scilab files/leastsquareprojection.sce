clear;close;clc;
A=[1 -1;1 1;1 2];
disp(A,'A=');
b=[1;1;3];
disp(b,"b=");
x=(A'*A)\(A'*b);
disp(x,"x=");;
C=x(1,1);
D=x(2,1);
disp(C,"C=");
disp(D,"D=");
disp("Best fit line is b = C + Dt")