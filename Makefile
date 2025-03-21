a.out: particleSys.o particleGraphics.o ParticleClass.o cell.o main.o
	g++ -g -pthread -lgtest -fsanitize=address -std=c++23 particleSys.o particleGraphics.o ParticleClass.o cell.o main.o

main.o: main.cc particleSys.h
	g++ -g -c -fsanitize=address -std=c++23 -fPIC main.cc -lgtest particleSys.h

particleSys.o: particleSys.h cell.h 
	g++ -g -c -lgtest -fsanitize=address -std=c++23 -fPIC particleSys.h

particleGraphics.o: particleGraphis.h cell.h ParticleClass.h
	g++ -g -c -fsanitize=address -std=c++23 -fPIC -lgtest particleGraphics.h

cell.o: cell.h ParticleClass.h
	g++ -g -c -lgtest -fsanitize=address -std=c++23 -fPIC cell.h

ParticleClass.o: ParticleClass.h
	g++ -g -c  -lgtest -fsanitize=address -std=c++23 -fPIC ParticleClass.h

clean:
	rm -f *.o a.out core
