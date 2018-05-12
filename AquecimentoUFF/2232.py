t = int(input())

for i in range(t):
	n = int(input())
	s = 0
	for i in range(n):
		s += 2**i
	print(s)