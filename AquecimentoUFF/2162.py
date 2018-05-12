n = int(input())
l = [int(x) for x in input().split(" ")]
def check(l):
	UP = 1
	DOWN = 0
	INIT = -1

	flag = INIT
	for i in range(len(l)-1):
		if l[i] > l[i+1] and (flag == DOWN or flag == INIT):
			flag = UP
		elif l[i] < l[i+1] and (flag == UP or flag == INIT):
			flag = DOWN
		else:
			return False
	return True
print(1) if check(l) else print(0)