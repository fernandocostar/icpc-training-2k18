#karina eu te amo

n = int(input())
while(n):
	possible = []
	p = int(input())
	result = 0
	
	for k in range(n):
		time, pizzas = map(int, input().split())
		possible.append([time, pizzas])
	possible.sort(key=lambda x: x[0], reverse=True)
	print(possible)
	i = 0
	while(p and i < len(possible)):
		if possible[i][1] <= p:
			p -= possible[i][1]
			result += possible[i][0]
		i += 1
	print("{}min.".format(result))

	n = int(input())
