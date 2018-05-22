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
	stack = []
	to_solve = []
	i = 0
	while(i < len(v)):
		if v[i] == ")":
			while(stack[-1] != "("):
				to_solve.insert(0, stack.pop())
			stack.pop() #remove ( parentheses
			if len(to_solve): stack.append(solve_sum(solve_mult(to_solve))[0])
			to_solve.clear()
		else:
			stack.append(v[i])
		i += 1
	return solve_sum(solve_mult(stack))

while True:
	try:
		l = input()
		parsed = parse_set(l)
		result = sorted(solve(parsed)[0])
		print("{"+"".join(result)+"}")
	except EOFError:
		break