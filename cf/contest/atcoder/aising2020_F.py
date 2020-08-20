import math
M = 1000000007
T = int(input())
for i in range(T):
	n = int(input())
	r = 0
	for i in range((n-5)%2,12,2):
		r+=math.comb(11,i)%M*math.comb((n-i+25)//2,15)%M;
	print(r%M)