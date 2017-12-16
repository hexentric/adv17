COMPILER=clang++
STD=c++14
STDLIB=libstdc++

CC=$(COMPILER) -std=$(STD) -stdlib=$(STDLIB)

DEPS=*.hpp
%.o: %.cpp $(DEPS)

main:
	$(CC) -o main.o main.cpp

.PHONY: clean

clean:
	rm -f GPATH GTAGS GRTAGS *.o
