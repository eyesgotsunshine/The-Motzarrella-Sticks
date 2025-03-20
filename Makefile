a.out: particleSys.o particleGraphics.o ParticleClass.o cell.o main.o
	g++ -g -pthread -fsanitize=address -std=c++23 particleSys.o particleGraphics.o ParticleClass.o cell.o main.o -lgtest 

main.o: main.cc cell.h particleSys.h particleGraphics.h ParticleClass.h
	g++ -g -c -fsanitize=address -std=c++23 -fPIC main.cc -lgtest 

particleSys.o: particleSys.h particleGraphis.o cell.o ParticleClass.o
	g++ -g -c -lgtest-fsanitize=address -std=c++23 -fPIC particleSys.h particleGraphics.o cell.o ParticleClass.o -o particleSys.o

particleGraphics.o: particleGraphis.h cell.o ParticleClass.o
	g++ -g -c -fsanitize=address -std=c++23 -fPIC -lgtest particleGraphics.h cell.o ParticleClass.o -o particleGraphics.o

cell.o: cell.h ParticleClass.o
	g++ -g -c -lgtest -fsanitize=address -std=c++23 -fPIC cell.h ParticleClass.o -o cell.o

ParticleClass.o: ParticleClass.h
	g++ -g -c  -lgtest -fsanitize=address -std=c++23 -fPIC ParticleClass.h -o ParticleClass.o

clean:
	rm -f *.o a.out core
