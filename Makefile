CC=clang++
CFLAGS=-Wall -Wextra -O2 -Iinclude
SRC=$(wildcard src/*.cpp)
OBJ=$(SRC:.cpp=.o)
BINARY=m3

# Output dir for builds
BUILD_DIR=build

.PHONY: all clean

all: build-linux-amd64 build-macos-amd64 build-macos-arm64

build-linux-amd64: CFLAGS += -target x86_64-linux-gnu
build-linux-amd64: $(OBJ)
	mkdir -p $(BUILD_DIR)
	$(CC) $(CFLAGS) -o $(BUILD_DIR)/m3-linux-amd64 $(OBJ)

build-macos-amd64: CFLAGS += -target x86_64-apple-macos11
build-macos-amd64: $(OBJ)
	mkdir -p $(BUILD_DIR)
	$(CC) $(CFLAGS) -o $(BUILD_DIR)/m3-macos-amd64 $(OBJ)

build-macos-arm64: CFLAGS += -target arm64-apple-macos11
build-macos-arm64: $(OBJ)
	mkdir -p $(BUILD_DIR)
	$(CC) $(CFLAGS) -o $(BUILD_DIR)/m3-macos-arm64 $(OBJ)

%.o: %.cpp
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -rf $(OBJ) $(BUILD_DIR)
