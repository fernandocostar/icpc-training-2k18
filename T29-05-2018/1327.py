n = int(input())
while(n):
	cartas = [4]*13
	nomes = input().split()
	baralho = [int(x) for x in input().split()]
	for i in range(3): baralho += [int(x) for x in input().split()]
	i = 0
	cont_cartas = 0
	while(i < 52 and len(nomes) > 1):
		i_menor = []
		menor = -1
		if 52-i < len(nomes): break
		for k in range(len(nomes)):
			i += 1
			if len(i_menor) == 0:
				i_menor.append(k)
				menor = baralho[cont_cartas+k]
			elif baralho[cont_cartas+k] == menor: i_menor.append(k)
			elif baralho[cont_cartas+k] < menor:
				i_menor.clear()
				i_menor.append(k)
				menor = baralho[cont_cartas+k]
		if len(i_menor) == len(nomes): break
		cont_cartas += len(nomes)
		aux = 0
		for k in range(len(i_menor)):
			if len(nomes) == 1: break
			nomes.pop(i_menor[k]-aux)
			aux += 1
	for each in nomes:
		print(each, end=" ")
	print("")
	n = int(input())
