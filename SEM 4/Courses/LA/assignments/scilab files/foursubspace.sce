clear;close;clc;
A = [0 1 0;0 0 1;0 0 0];
disp(A,"A=");
[m,n] = size(A);
disp(m,"m=");
disp(n."n=");
[v, pivot] = rref(A);
disp(rref(A));
disp(v);
r=length(pivot);
disp(r,"Rank =")
cs=A(:,pivot);
disp(cs,"column space =");
ns=kernel(A);
disp(ns,"null space =");
rs=v(1:r,:)';
disp(rs,"Row space =");
lns=kernel(A');
disp(lns,"Left null space =");