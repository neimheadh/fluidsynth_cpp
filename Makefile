CXX=g++
LD=g++

CXXFLAGS=-Wall -fexceptions
CXXFLAGS+=-Iinclude

LDFLAGS=

SRC=$(wildcard src/*.cpp)
OBJ=$(SRC:src/%.cpp=obj/%.o)

TST_SRC=$(wildcard tests/*.cpp)
TST_OBJ=$(TST_SRC:tests/%.cpp=obj/test-%.o)
TST_BIN=$(TST_SRC:tests/%.cpp=bin/test-%)

bin:
	mkdir -p bin

bin/test-%: tests/%.cpp bin $(OBJ) $(TST_OBJ)
	$(LD) -o $@ $(OBJ) $(TST_OBJ) $(LDFLAGS)

obj/test-%.o: tests/%.cpp obj
	$(CXX) $(CXXFLAGS) -c $< -o $@

obj/%.o: src/%.cpp obj
	$(CXX) $(CXXFLAGS) -c $< -o $@

obj:
	mkdir -p obj

.PHONY: build clean print test

build: $(OBJ)

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

test: $(TST_BIN)
	@for test in $(TST_BIN); do \
		echo "\033[34;1m### $$test ###\033[0m"; \
		eval $$test; \
	done
		
		
