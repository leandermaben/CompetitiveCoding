from os import system
for i in range(1,13):
	system('./rest < test'+str(i)+'.txt > output'+str(i)+'.txt')