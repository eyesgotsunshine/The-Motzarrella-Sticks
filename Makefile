a.out: cell.o particleSys.o main.o
	g++ -g -pthread -fsanitize=address -std=c++23 cell.o particleSys.o main.o -lgtest 

main.o: main.cc cell.h particleSys.h
	g++ -g -c -fsanitize=address -std=c++23 -fPIC main.cc -lgtest 

cell.o: cell.cc cell.h
	g++ -g -c -fsanitize=address -std=c++23 -fPIC cell.cc -lgtest 

particleSys.o: particleSys.cc particleSys.h
	g++ -g -c -fsanitize=address -std=c++23 -fPIC particleSys.cc -lgtest 

clean:
	rm -f *.o a.out core
