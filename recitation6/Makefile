# This is the Makefile responsible for compiling your code
SRC_DIR := src
BUILD_DIR := bin
INCLUDE_DIR := include
TEST_DIR := test

SRCS := $(wildcard $(SRC_DIR)/*.c)
CC := gcc
CFLAGS := -I$(INCLUDE_DIR) -Wall -O2 -std=c99
TFLAGS := -lcriterion

.PHONY: all clean test

all: $(BUILD_DIR)/test_file
$(BUILD_DIR)/test_file: $(TEST_DIR)/student_tests.c $(TEST_DIR)/unit_tests.c $(SRCS) | $(BUILD_DIR)
	$(CC) $(CFLAGS) $(SRCS) $(TEST_DIR)/student_tests.c $(TEST_DIR)/unit_tests.c -o $@ $(TFLAGS)

$(BUILD_DIR):
	mkdir -p $@

test: $(BUILD_DIR)/test_file
	./$(BUILD_DIR)/test_file

clean:
	rm -rf $(BUILD_DIR)