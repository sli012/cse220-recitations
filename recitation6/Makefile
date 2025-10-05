# Directories
SRC_DIR := src
BUILD_DIR := bin
INCLUDE_DIR := include
TEST_DIR := test

# Detect Homebrew prefix dynamically
BREW_PREFIX := $(shell brew --prefix)

# Include and library paths (for Homebrew)
INCLUDE_PATHS := -I$(BREW_PREFIX)/include
LIB_PATHS := -L$(BREW_PREFIX)/lib

# Compiler and flags
CC := gcc
CFLAGS := -Wall -O2 -std=c99 -I$(INCLUDE_DIR) $(INCLUDE_PATHS)
LDFLAGS := $(LIB_PATHS)
LDLIBS := -lcriterion

# Sources
SRCS := $(wildcard $(SRC_DIR)/*.c)
TEST_SRCS := $(TEST_DIR)/student_tests.c $(TEST_DIR)/unit_tests.c
OBJS := $(SRCS:.c=.o)

.PHONY: all clean test

all: $(BUILD_DIR)/test_file

$(BUILD_DIR)/test_file: $(SRCS) $(TEST_SRCS) | $(BUILD_DIR)
	$(CC) $(CFLAGS) $^ -o $@ $(LDFLAGS) $(LDLIBS)

$(BUILD_DIR):
	mkdir -p $@

test: $(BUILD_DIR)/test_file
	./$(BUILD_DIR)/test_file

clean:
	rm -rf $(BUILD_DIR)
