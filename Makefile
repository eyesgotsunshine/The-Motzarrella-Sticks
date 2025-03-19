a.out: particleSys.o particleGraphics.o ParticleClass.o cell.o main.o
	g++ -g -pthread -fsanitize=address -std=c++23 particleSys.o particleGraphics.o ParticleClass.o cell.o main.o -lgtest 

main.o: main.cc cell.h particleSys.h particleGraphics.h ParticleClass.h
	g++ -g -c -fsanitize=address -std=c++23 -fPIC main.cc -lgtest 

particleSys.o: particleSys.h
	g++ -g -c -lgtest-fsanitize=address -std=c++23 -fPIC particleSys.h  -o particleSys.o

cell.o: cell.h particleSys.h particleGraphics.h
	g++ -g -c -lgtest -fsanitize=address -std=c++23 -fPIC cell.h particleSys.h particleGraphics.h -o cell.o

particleGraphics.o: particleGraphis.h ParticleClass.h particleSys.o
	g++ -g -c -fsanitize=address -std=c++23 -fPIC particleGraphics.h -lgtest 

ParticleClass.o: ParticleClass.h
	g++ -g -c -fsanitize=address -std=c++23 -fPIC ParticleClass.h -lgtest 

clean:
	rm -f *.o a.out core
