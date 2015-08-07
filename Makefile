CC=g++
EXT=-std=c++11
all: $(patsubst %.cpp, %.o, $(wddildcard *.cpp)) find_s_driver q1_driver

find_s_driver: find_s.o find_s_driver.o
	$(CC) -o find_s_driver find_s_driver.o find_s.o $(EXT)

q1_driver: find_s.o q1_driver.o file_controller.o
	$(CC) -o q1_driver q1_driver.o find_s.o file_controller.o $(EXT)

file_controller.o: file_controller.cpp file_controller.h
	$(CC) -c -o file_controller.o file_controller.cpp $(EXT)

find_s.o: find_s.cpp find_s.h
	$(CC) -c -o find_s.o find_s.cpp $(EXT)

%.o: %.cpp
	$(CC) -c -o $@ $< $(EXT)

clean:
	rm -f *.o *.so *.exe *.raw *.dat fleetState testDriver unit_tests/*.o
