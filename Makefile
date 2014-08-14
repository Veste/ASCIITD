CPP=g++

CPP_FILES := $(wildcard src/*.cpp)
OBJ_FILES := $(patsubst src/%.cpp,obj/%.o,$(CPP_FILES))
LD_FLAGS := -lncurses
CC_FLAGS := -Wall -O2

default: all

all: obj bin bin/asciitd

bin:
	mkdir bin

bin/asciitd: $(OBJ_FILES)
	$(CPP) -o $@ $^ $(LD_FLAGS)

obj:
	mkdir obj

obj/%.o: src/%.cpp
	$(CPP) $(CC_FLAGS) -c -o $@ $<



