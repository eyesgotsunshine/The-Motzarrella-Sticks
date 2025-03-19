a.out: particleSys.o main.o
	g++ -g -pthread -fsanitize=address -std=c++23 particleSys.o main.o -lgtest 

main.o: main.cc cell.h particleSys.h
	g++ -g -c -fsanitize=address -std=c++23 -fPIC main.cc -lgtest 

particleSys.o: particleSys.cc particleSys.h
	g++ -g -c -fsanitize=address -std=c++23 -fPIC particleSys.cc -lgtest 

clean:
	rm -f *.o a.out core
