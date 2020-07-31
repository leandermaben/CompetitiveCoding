import random



def get_path(n):
	c=[random.randint(2,n-1) for i in range(n)]
	s=list(set(c))
	random.shuffle(s)
	return s

lim=10


for i in range(12):
	file=open('test'+str(i+1)+'.txt','w')
	s=get_path(lim)
	s.append(lim)
	paths=[]
	mem=set([])
	prev=1
	for x in s:
		paths.append(str(prev)+' '+str(x)+' '+str(random.randint(1,100000))+'\n')
		mem.add((prev,x))
		prev=x
	for j in range(2*lim-len(s)):
		a=random.randint(1,lim)
		b=random.randint(1,lim)
		while b==a:
			b=random.randint(1,lim)
		if (a,b) not in mem:
			mem.add((a,b))
			paths.append(str(a)+' '+str(b)+' '+str(random.randint(1,100000))+'\n')

	file.write(str(lim)+' '+str(len(paths))+'\n')
	for x in paths:
		file.write(x)
	lim= lim*10 if lim*10<=100000 else lim