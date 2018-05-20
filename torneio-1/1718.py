c, n = map(int, input().split())
azeitonas = [int(x) for x in input().split()]
azeitonas.append(azeitonas[0])

media = c//n
ultima_dif = 0
sobra = 0
flag = False

for i in range(1, len(azeitonas)-1):
	ultima_dif = azeitonas[i] - azeitonas[i-1]
	if ultima_dif > media:
		sobra = ultima_dif - media
	print(ultima_dif, media, azeitonas[i+1]);
	if ultima_dif > azeitonas[i+1]:
		flag = True
		print("N")
		break
if not flag:
	print("Y")

