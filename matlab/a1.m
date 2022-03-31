# question 1

matrix = zeros(2,4)
L = 1:2:21
Sum = sum(L)
A = [2 3 2 1 0 1]

# question 2

V1 = [3 4 5 6 7 8]
V2 = [1 2 3 4 5 6]
V3 = V1 + V2
V4 = V1 - V2
V5 = V1 .* V2
V6 = power(V1,2)
Mat33 = [1 2 3; 4 5 6; 7 8 9]
disp(Mat33(1,2))

# question 3

A = [5 3 1]
B = [1 3 5]
add = A + B
sub = A - B
mult = A .* B
div = A ./ B
power(A,2)
mat33 = [10 20 30; 40 50 60; 70 80 90]
disp(mat33(1,2))

# question 4

g=9.8
x0=0
y0=0
v0=50.75
theta=5*pi/12
t=0:0.1:10
x=x0+v0*cos(theta)*t
y=y0+v0*sin(theta)*t-0.5*g*t.^2
plot(x,y)

# question 5

x=0:pi/30:2*pi
# plot two graphs in one figure
plot(x,sin(x),x,cos(x))