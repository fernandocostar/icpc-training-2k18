d = [2]*26
change = ["A", "E", "I", "O", "S"]

for i in range(5):
	d[ord(change[i].lower()) - ord("a")] += 1

t = int(input())
for i in range(t):
	l = input()
	count = 1
	for each in l:
		count *= d[ord(each.lower()) - ord("a")]
	print(count)