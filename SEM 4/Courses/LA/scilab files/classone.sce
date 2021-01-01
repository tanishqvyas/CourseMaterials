a1 = [3 4 -2 2;4 9 -3 5;-2 -3 7 6; 1 4 6 7];

b =[2;8;10;2]


a =[a1 b] // making augmented system
[m,n]=size(a); // finding the size of the matrix

for j=1:m-1
	for z=2:m
		if a(j,j)==0
			t=a(j,:);
			a(j,:)=a(z,:)
			a(z,:)=t
		end
	end
	for i=j+1:m
		a(i,:)=a(i,:)-a(j,:)*(a(i,j)/a(j,j));
	end
end




disp(a); 


for j=m:-1:2
	for i=j-1:-1:1
		a(i,:)=a(i,:)-a(j,:)*(a(i,j)/a(j,j));
    end
end

disp(a)

for s=1:m
	x(s,:)=a(s,:)/a(s,s);
end

disp('Gaussain Elimination Method');
disp(x(:,n))