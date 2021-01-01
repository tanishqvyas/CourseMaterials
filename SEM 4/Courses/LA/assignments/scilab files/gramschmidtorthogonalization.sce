clear;close;clc;
A=[1 0 1;1 0 0;2 1 0];

disp(A,"A=");
[m,n]=size(A);
for k=1:n
	V(:,k)=A(:,k);
	for j=1:k-1
	R(j,k)=v(:,j)'*A(:,k);

			V(:,k)=V(:,k)-r(j,k)*V(:,j);

	end
	R(k,k)=norm(V(:,k));
	V(:,k)=V(:,k)/R(k,k);
end
disp(V,"Q=");