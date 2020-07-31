from os import system
for i in range(1,13):
	system('./flight_disc < test'+str(i)+'.txt > output'+str(i)+'.txt')