CC=clang++
CFLAGS=-Wall -Wextra -O2 -Iinclude
SRC=$(wildcard src/*.cpp)
BUILD_DIR=build
BIN_NAME=m3

# Pattern rule for building per target object files
define BUILD_TARGET

$(1)_OBJ := $(patsubst src/%.cpp,$(BUILD_DIR)/$(1)/%.o,$(SRC))

build-$(1): CFLAGS += -target $(2)
build-$(1): $($(1)_OBJ)
	mkdir -p $(BUILD_DIR)
	$(CC) $(CFLAGS) -o $(BUILD_DIR)/$(BIN_NAME)-$(1) $($(1)_OBJ)

$(BUILD_DIR)/$(1)/%.o: src/%.cpp
	mkdir -p $(dir $@)
	$(CC) $(CFLAGS) -c $$< -o $$@

endef

# Define targets with (target-name, clang target triple)
$(eval $(call BUILD_TARGET,linux-amd64,x86_64-linux-gnu))
$(eval $(call BUILD_TARGET,macos-amd64,x86_64-apple-macos11))
$(eval $(call BUILD_TARGET,macos-arm64,arm64-apple-macos11))

.PHONY: all clean
all: build-linux-amd64 build-macos-amd64 build-macos-arm64

clean:
	rm -rf $(BUILD_DIR)
