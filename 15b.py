FACTOR_A = 16807
FACTOR_B = 48271
DIV = 2147483647
line1=input()
line2=input()
a=int(line1.split()[4])
b=int(line2.split()[4])
count=0
for i in range(5000000):
	a=(a*FACTOR_A)%DIV
	while (a%4!=0):
		a=(a*FACTOR_A)%DIV
	b=(b*FACTOR_B)%DIV
	while (b%8!=0):
		b=(b*FACTOR_B)%DIV
	x=a
	y=b
	for j in range(16):
		flag=0
		if (x%2 == y%2):
			x=int(x/2)
			y=int(y/2)
			flag=1
			continue
		break
		
	if (flag==1):
		count=count+1
print(count)
