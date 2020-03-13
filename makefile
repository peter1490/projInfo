CC = g++
BIN = my_world
SRC = ./src/main.cpp \
	  ./src/Block.cpp \
	  ./src/Camera.cpp \
	  ./src/Cube.cpp \
	  ./src/House.cpp \
	  ./src/Map.cpp \
	  ./src/Map.cpp \
	  ./src/Rectangle.cpp \
	  ./src/Road.cpp \
	  ./src/Robot.cpp \
	  ./src/Wall.cpp \
OBJ = $(SRC:.cpp=.o)

ERROR_CFLAGS = -Wall -Werror -Wextra

GLUT_CFLAGS = -lX11 -lGL -lGLU -lglut -lSOIL
CFLAGS += $(GLUT_CFLAGS) -I./



all: $(BIN)

$(BIN): main.o Block.o Camera.o Cube.o House.o Map.o Rectangle.o Road.o Robot.o Wall.o
	$(CC)  -o $@ $^ $(CFLAGS) -g
#
#$(OBJ): $(SRC)
#	$(CC) $(CFLAGS) -o $@ -c $<

Block.o: ./src/Block.cpp
	$(CC) -o $@ -c $< $(CFLAGS)

Camera.o : ./src/Camera.cpp
	$(CC) -o $@ -c $< $(CFLAGS)

Cube.o: ./src/Cube.cpp
	$(CC) -o $@ -c $< $(CFLAGS)

House.o : ./src/House.cpp
	$(CC) -o $@ -c $< $(CFLAGS)

Map.o: ./src/Map.cpp
	$(CC) -o $@ -c $< $(CFLAGS)

Rectangle.o : ./src/Rectangle.cpp
	$(CC) -o $@ -c $< $(CFLAGS)

Road.o: ./src/Road.cpp
	$(CC) -o $@ -c $< $(CFLAGS)

Robot.o : ./src/Robot.cpp
	$(CC) -o $@ -c $< $(CFLAGS)

Wall.o : ./src/Wall.cpp
	$(CC) -o $@ -c $< $(CFLAGS)

main.o: ./src/main.cpp
	$(CC) -o $@ -c $< $(CFLAGS)

clean: 
	rm -f $(OBJ)
	rm -f Block.o
	rm -f Camera.o
	rm -f Cube.o
	rm -f House.o
	rm -f Map.o
	rm -f Rectangle.o
	rm -f Road.o
	rm -f Robot.o
	rm -f Wall.o

run: fclean all
	./$(BIN)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re