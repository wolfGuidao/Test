SRC=oj_server.cc 
DES=oj_server
CC=g++
FLAG=-std=c++11 -lpthread -L ./include/ctemplate/lib -lctemplate -L ./include/json/ -ljsoncpp

$(DES):$(SRC)
	$(CC) $^ -o $@ $(FLAG)

clean:
	rm -rf $(DES)
