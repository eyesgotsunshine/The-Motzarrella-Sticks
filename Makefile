a.out: particleSys.o main.o
	g++ -g -pthread -fsanitize=address -std=c++23 particleSys.o main.o -lgtest 

main.o: main.cc cell.h particleSys.h particleGraphics.h ParticleClass.h
	g++ -g -c -fsanitize=address -std=c++23 -fPIC main.cc -lgtest 

particleSys.o: particleSys.h cell.h
	g++ -g -c -fsanitize=address -std=c++23 -fPIC particleSys.h -lgtest 

clean:
	rm -f *.o a.out core
