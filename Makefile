all: main-v1.exe main-v2.exe

CC=clang++
CFLAGS=-Wall -O2

%.o: %.cpp
	$(CC) $(CFLAGS) -c $< -o $@

main-v1.exe: main.o v1/mmm.o
	$(CC) $(CFLAGS) $< -o $@ v1/mmm.o

main-v2.exe: main.o v2/mmm.o
	$(CC) $(CFLAGS) $< -o $@ v2/mmm.o

clean: 
	rm *.exe *.o v1/*.o v2/*.o

test:
	echo "01.dat" "01-v1.out" | ./main-v1.exe
	echo "02.dat" "02-v1.out" | ./main-v1.exe
	echo "03.dat" "03-v1.out" | ./main-v1.exe
	echo "01.dat" "01-v2.out" | ./main-v2.exe
	echo "02.dat" "02-v2.out" | ./main-v2.exe
	echo "03.dat" "03-v2.out" | ./main-v2.exe
