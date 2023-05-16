x = [-2 -1 1];
y = [-15 3 9];
m = length(x)
d=y';

for j=2:m
  for i=1:m-(j-1)
    d(i,j) = (d(i+1, j-1) - d(i,j-1)) / (x(i+j-1) - x(i));
  endfor
endfor
for k=1:m
  c(k) = d(1,k)
endfor


t = [-3:.05:2];
p =0;

for k=1:m
   prod=1;
   for i=1:k-1
     prod=prod.*(t-x(i));
   end
   p = p + c(k)*prod;
end
plot(t, p,x,y, '*')
