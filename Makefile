all:	btree.cpp main.cpp
	g++ -g main.cpp btree.cpp -o btree
clean:
	rm -f btree
