CXX=g++
LD=g++

CXXFLAGS=-Wall -fexceptions
CXXFLAGS+=-Iinclude

LDFLAGS=-lfluidsynth

SRC=$(wildcard src/*.cpp)
SRC+=$(wildcard src/exceptions/*.cpp)
OBJ=$(SRC:src/%.cpp=obj/%.o)

TST_SRC=$(wildcard tests/*.cpp)
TST_OBJ=$(TST_SRC:tests/%.cpp=obj/test-%.o)
TST_BIN=$(TST_SRC:tests/%.cpp=bin/test-%)

bin/test-%: tests/%.cpp dir $(OBJ) obj/test-%.o
	$(LD) -o $@ $(OBJ) $(@:bin/%=obj/%.o) $(LDFLAGS)

env.hpp: env.dist.hpp
	cp env.dist.hpp env.hpp

obj/test-%.o: tests/%.cpp env.hpp
	$(CXX) $(CXXFLAGS) -I . -c $< -o $@

obj/%.o: src/%.cpp dir
	$(CXX) $(CXXFLAGS) -c $< -o $@

.PHONY: build clean dir realclean print test

build: $(OBJ)

dir:
	mkdir -p bin obj/exceptions

clean:
	rm -R obj

print:
	@echo CXX=$(CXX)
	@echo LD=$(LD)
	@echo
	@echo CXXFLAGS=$(CXXFLAGS)
	@echo LDFLAGS=$(LDFLAGS)
	@echo
	@echo SRC=$(SRC)
	@echo OBJ=$(OBJ)
	@echo
	@echo TST_SRC=$(TST_SRC)
	@echo TST_OBJ=$(TST_OBJ)
	@echo TST_BIN=$(TST_BIN)

realclean: clean
	rm -R bin

test: $(TST_BIN)
	@for test in $(TST_BIN); do \
		echo "\033[34;1m### $$test ###\033[0m"; \
		eval $$test; \
	done	
