a.out: particleSys.o particleGraphics.o ParticleClass.o cell.o main.o
	g++ -g -pthread -fsanitize=address -std=c++23 particleSys.o particleGraphics.o ParticleClass.o cell.o main.o -lgtest 

main.o: main.cc cell.h particleSys.h particleGraphics.h ParticleClass.h
	g++ -g -c -fsanitize=address -std=c++23 -fPIC main.cc -lgtest 

particleSys.o: particleSys.h
	g++ -g -c -fsanitize=address -std=c++23 -fPIC particleSys.h -lgtest 

cell.o: cell.h
	g++ -g -c -fsanitize=address -std=c++23 -fPIC cell.h -lgtest 

particleGraphics.o: particleGraphis.h
	g++ -g -c -fsanitize=address -std=c++23 -fPIC particleGraphics.h -lgtest 

ParticleClass.o: ParticleClass.h
	g++ -g -c -fsanitize=address -std=c++23 -fPIC ParticleClass.h -lgtest 

clean:
	rm -f *.o a.out core
