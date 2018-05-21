def solve(hist):
	stack = []
	max_found = 0
	i = 0
	while(i < len(hist)):
		if len(stack) == 0 or hist[stack[-1]] <= hist[i]:
			stack.append(i)
			i += 1
		else:
			currMax = stack.pop(-1)
			area = hist[currMax]* ((i-1-stack[-1]) if len(stack) else (i-1))
			if area > max_found: max_found = area
	while(len(stack)):
		currMax = stack.pop(-1)
		area = hist[currMax]* ((i-1-stack[-1]) if len(stack) else (i-1))
		if(area > max_found): max_found = area
	return max_found

l = [int(x) for x in input().split()]
while(not(len(l) == 1 and l[0] == 0)):
	print(solve(l))
	l = [int(x) for x in input().split()]
