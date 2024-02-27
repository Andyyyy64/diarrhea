CC=gcc
CFLAGS=-Iinclude
LDFLAGS
OBJ_DIR=obj
BIN_DIR=bin

SOURECES=$(wildcard *.c)
OBJECTS=$(patsubst %.c, $(OBJ_DIR)/%.o, $(SOURECES))
EXECUTABLE=$(BIN_DIR)/diarrhea

all: $(EXECUTABLE)

$(EXECUTABLE): $(OBJECTS)
	$(CC) $(LDFLAGS) -o $@ $^

$(OBJ_DIR)/%.o: %.c
	mkdir -p $(OBJ_DIR)
	$(CC) $(CFLAGS) -c -o $@ $<

clean:
	rm -rf $(OBJ_DIR) $(BIN_DIR)

.PHONY: all clean
