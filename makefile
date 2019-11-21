CC = gcc
CFLAGS = -Wall 
TARGET = P0 
OBJ = main.o tree.o
SRC = main.c tree.c

all: $(TARGET) 
	
$(TARGET):$(OBJ)
	$(CC) -o $(TARGET) $(OBJ)

$(OBJ): $(SRC)
	$(CC) $(CFLAGS) -c $(SRC)

clean:
	/bin/rm -f *.o $(TARGET) 
	rm *.inorder *.preorder *.postorder
