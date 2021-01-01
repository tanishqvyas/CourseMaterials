A =[0 1 0;0 0 1; 0 0 0];
[m,n] = size(A);
[v,p]=rref(A);
disp(v);
disp(p,'Pivot')

//Rank
r=length(p)
disp(r,'Rank')
cs=A(:,p)
disp(cs,'Col Space')
ns=kernel(A)
disp(ns,'Null Space')

rs=v(1:r,:)
disp(rs,'Row Space')

lns=kernel(A')
disp(lns,'Left NULL SPace')


//Find the basis ???