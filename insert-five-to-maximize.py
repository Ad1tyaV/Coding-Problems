# https://ideone.com/1r07UC
inp = 9234
target = 5
m=None

for i in range(0, len(str(inp))):
	if target > int(str(inp)[i]):
		m = i
		break

i = 0
sum=0
exp = len(str(inp))

while exp>=0 :
	if i==m:
		sum+= (pow(10, exp) * target)
		m=-1
	else:
		sum+= (pow(10, exp) * int(str(inp)[i]))
		i+=1		
	exp-=1

print(sum)
