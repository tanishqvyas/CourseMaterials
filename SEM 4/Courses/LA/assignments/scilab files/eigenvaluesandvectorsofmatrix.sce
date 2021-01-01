clc;close;clear;
A=[3,-2,5;-2,3,6;5,6,4]
lam=poly(0,'lam')
lam=lam
charMat=A-lam*eye(3,3)
disp(charMat,"the characteristic Matrix is")
charPoly=poly(A,"lam")
disp(charPoly,"the characteristic polynomial is")
lam=spec(A)
disp(lam,"the eigne values of A are")
function[x,lam]=eigenvectors(A)
[n,m]=size(A);
lam=spec(A)';
x=[];

for k=1:3
	B=A-lam(k)*eye(3,3);
	C=B(1:n-1,1:n-1);
	b=-B(1:n-1,n);
	y=C\b;
	y=[y;1];
	y=y/norm(y);
	x=[x y];
end
endfunction

get f('eigenvectors')
[x,lam] = eigenvectors(A)
disp(x,"the eigen vectors of A are")