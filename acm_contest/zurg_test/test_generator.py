import random
import string
from random import randint
test_sets=12

lim1=100
lim2=1000
count=0
for i in range(test_sets):
	count+=1
	file=open('test'+str(count)+'.txt','w')
	n=randint(lim1,lim2)
	file.write(str(n)+"\n")
	for j in range(n):
		file.write(str(randint(1,1000000000))+" ")
		file.write(str(randint(1,1000000000))+"\n")
	x=lim1*10
	y=lim2*10
	lim1=x if x<=100000 else lim1
	lim2=x if x<=100000 else lim2
	file.close()



