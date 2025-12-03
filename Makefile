RAYLIB_PATH = C:/raylib/w64devkit
INCLUDE_PATH = $(RAYLIB_PATH)/include
LIB_PATH = $(RAYLIB_PATH)/lib

CC = $(RAYLIB_PATH)/bin/g++.exe
CFLAGS = -I$(INCLUDE_PATH) -Wall -std=c++14
LDFLAGS = -L$(LIB_PATH) -lraylib -lopengl32 -lgdi32 -lwinmm

SRC = main.cpp
OUT = main.exe

all:
	$(CC) -fopenmp $(SRC) -o $(OUT) $(CFLAGS) $(LDFLAGS)

clean:
	del $(OUT)
