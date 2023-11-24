import math



 
n = 50

s = 0
x = 4/n *math.tan(math.pi/n)

a = (n-2)*math.pi/(2*n)

t = x*math.cos(a)*math.sin(a)/8

ratio = t*2*n
a = 1
for i in range(1,10000):
	s+=(a*ratio)*i
	a = a-a*ratio
	
print(s*(10**4))