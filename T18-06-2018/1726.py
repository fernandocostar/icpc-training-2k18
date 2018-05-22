def solve_mult(vet):
	result = {}
	i = 0
	end = len(vet)
	while(i < end):
		if vet[i] == "*":
			result = vet[i-1].intersection(vet[i+1])
			for j in range(2): vet.pop(i-1)
			vet[i-1] = result
			end -= 2
			i -= 1
		i += 1
	return vet

def solve_sum(vet):
	result = set()
	i = 0
	end = len(vet)
	while(i < end):
		if vet[i] == "+":
			result = vet[i-1].union(vet[i+1])
			for j in range(2): vet.pop(i-1)
			i -= 1
			vet[i] = result
			end -= 2
		elif vet[i] == "-":
			result = vet[i-1]-vet[i+1]
			for j in range(2): vet.pop(i-1)
			i -= 1
			vet[i-1] = result
			end -= 2
		i += 1
	return vet

def parse_set(l):
	result = []
	aux = set()
	adding = False
	for each in l:
		if each == "{":
			adding = True
		elif each == "}":
			adding = False
			result.append(aux)
			aux = set()
		elif adding:
			aux.add(each)
		else:
			result.append(each)
	return result

def solve(v):
	result = set()
	if "(" not in v:
		return solve_sum(solve_mult(v))
	parta = []
	partb = []
	begin = 0
	end = len(v)-1
	while(v[begin] != "(" or v[end] != ")" ):
		if v[begin] != "(":
			begin += 1
		if v[end] != ")":
			end -= 1
	return solve_sum(solve_mult(v[:begin] + solve_sum(solve_mult(v[begin + 1:end])) + v[end+1:]))

stack = []
while True:
	try:
		l = input()
		parsed = parse_set(l)
		result = sorted(solve(parsed)[0])
		print("{"+"".join(result)+"}")
	except EOFError:
		break