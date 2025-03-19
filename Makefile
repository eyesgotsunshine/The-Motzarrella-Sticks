particle_sim: particle_system.o particle.o cell.o main.o
	g++ -g -pthread -fsanitize=address -std=c++23 particle_system.o particle.o cell.o main.o -o particle_sim -lgtest

main.o: main.cc particle_system.h particle.h cell.h
	g++ -g -c -fsanitize=address -std=c++23 -fPIC main.cc -lgtest 

particle_system.o: particle_system.cc particle_system.h particle.h cell.h
	g++ -g -c -fsanitize=address -std=c++23 -fPIC particle_system.cc -lgtest 

particle.o: particle.cc particle.h
	g++ -g -c -fsanitize=address -std=c++23 -fPIC particle.cc -lgtest 

cell.o: cell.cc cell.h
	g++ -g -c -fsanitize=address -std=c++23 -fPIC cell.cc -lgtest 

clean:
	rm -f *.o particle_sim core
