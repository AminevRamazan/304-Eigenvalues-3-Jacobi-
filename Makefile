all: spectrum

spectrum: main.o matrix_io.o jacobi.o functions.o
	g++ main.o matrix_io.o jacobi.o functions.o -o spectrum

main.o: main.cpp matrix_io.h jacobi.h functions.h
	g++ -g -Wall -Wextra -Werror -pedantic -std=gnu++0x -O3 -c main.cpp

matrix_io.o: matrix_io.cpp matrix_io.h
	g++ -g -Wall -Wextra -Werror -pedantic -std=gnu++0x -O3 -c matrix_io.cpp

jacobi.o: jacobi.cpp jacobi.h
	g++ -g -Wall -Wextra -Werror -pedantic -std=gnu++0x -O3 -c jacobi.cpp

functions.o: functions.cpp functions.h
	g++ -g -Wall -Wextra -Werror -pedantic -std=gnu++0x -O3 -c functions.cpp

clean:
	rm -f *.o spectrum
