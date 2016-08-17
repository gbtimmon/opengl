CC       = g++
SRC_PATH = ./src

INC      = -I /c/MinGW/include -I ./include
LIB      = -L /c/MinGW/lib
STATIC   = -c
CFLAGS   = -w -Wall -std=c11 -pedantic
LINKER   = -l mingw32 -l glew32 -l glfw3 -l opengl32 -l glu32 -l gdi32

BINARY = start.exe

all : $(SOURCES) $(BINARY)

$(BINARY) : vec3.o shader.o
	$(CC) $(SRC_PATH)/window.c++ vec3.o shader.o $(OBJS) $(INC) $(LIB) $(CFLAGS) $(LINKER) -o start.exe

vec3.o: $(SRC_PATH)/vec3.c++
	$(CC) $(SRC_PATH)/vec3.c++ $(INC) $(LIB) $(STATIC) $(CFLAGS) $(LINKER) -o vec3.o

shader.o: $(SRC_PATH)/shader.c++
	$(CC) $(SRC_PATH)/shader.c++ $(INC) $(LIB) $(STATIC) $(CFLAGS) $(LINKER) -o shader.o

.PHONY : clean 

clean : 
	-rm vec3.o shader.o
