import random
import string

def rand_string(len):
	char_set=string.ascii_letters
	return ''.join([random.choice(char_set) for i in range(len)])

test_sets=15

test_cases=[random.randint(1,10) for i in range(test_sets)]


def spec_gen(s):
	res=set([])
	for i in range(4):
		count=0
		pos=0
		while(pos!=len(s)):
			r=random.randint(1,len(s))
			end=r if pos+r<=len(s) else len(s)
			if count<24:
				res.add(s[pos:end])
				pos=end
			else:
				res.add(s[pos:len(s)])
				pos=len(s)
			count+=1
			res.discard('')
	return res

def rand_gen():
	return set([rand_string(random.randint(1,1000)) for i in range(random.randint(1,75))])


count=0
lim=1
for i in test_cases:
	count+=1
	file=open('test'+str(count)+'.txt','w')
	file.write(str(i)+"\n")
	ch=[True,True,True,True,False]
	for j in range(i):
		s=rand_string(lim)
		file.write(s+"\n")
		if random.choice(ch):
			opts=spec_gen(s)
		else:
			opts=rand_gen()
		file.write(str(len(opts))+"\n")
		file.write(' '.join(opts)+"\n")
	n=lim*10
	lim=n if n<=10000 else lim
	file.close()



