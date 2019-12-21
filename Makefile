CXX=g++

CXXFLAGS=-Wall -fexceptions
CXXFLAGS+=-Iinclude

SRC=$(wildcard src/*.cpp)
OBJ=$(SRC:src/%.cpp=obj/%.o)


obj/%.o: src/%.cpp obj
	$(CXX) $(CXXFLAGS) -c $< -o $@

obj:
	mkdir -p obj

.PHONY: build clean print

build: $(OBJ)

clean:
	rm -R obj

print:
	@echo CXX=$(CXX)
	@echo CXXFLAGS=$(CXXFLAGS)
	@echo
	@echo SRC=$(SRC)
	@echo OBJ=$(OBJ)

