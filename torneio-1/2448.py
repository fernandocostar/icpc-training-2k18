n, m = map(int, input().split())

l1 = [int(x) for x in input().split()]
l2 = [int(x) for x in input().split()]

m = {}
for i in range(len(l1)):
	m[l1[i]] = i 

atual = 0
count = 0
for each in l2:
	count += abs(atual - m[each])
	atual = m[each]
	
print(count)