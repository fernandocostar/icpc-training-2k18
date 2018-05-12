t = int(input())

for i in range(t):
	ax, ay, bx, by, cx, cy, dx, dy, rx, ry = map(int, input().split(" "))
	mat = [[0]*(bx-ax) for i in range(cy-ay)]
	try:
		mat[ry - cy][rx - cx] = 0
		print(1)
	except:
		print(0)

