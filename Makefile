CC=g++
EXT=-std=c++11
all: $(patsubst %.cpp, %.o, $(wddildcard *.cpp)) fleetState testDriver

find_s_driver: find_s.o
	$(CC) -o find_s_driver find_s.o $(EXT)

find_s.o: find_s.cpp find_s.h
	$(CC) -c -o find_s.o find_s.cpp $(EXT)	

%.o: %.cpp
	$(CC) -c -o $@ $< $(EXT)

clean:
	rm -f *.o *.so *.exe *.raw *.dat fleetState testDriver unit_tests/*.o
