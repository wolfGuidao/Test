SRC=test.cpp
DES=test
CC=g++
FLAG=-std=c++11 -lpthread

$(DES):$(SRC)
	$(CC) $^ -o $@ $(FLAG)

clean:
	rm -rf $(DES)
