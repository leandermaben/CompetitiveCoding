from os import system
for i in range(1,16):
	system('./pi < test'+str(i)+'.txt > output'+str(i)+'.txt')