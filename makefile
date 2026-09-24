CC ?= gcc
CFLAGS ?= -std=c11 -Wall -Wextra -Wpedantic -O2
CPPFLAGS ?= -Isrc/includes

TARGET := bin/paa
SOURCES := src/main.c src/map.c
OBJECTS := $(SOURCES:src/%.c=bin/%.o)
DEPS := $(OBJECTS:.o=.d)

TEST_BIN_DIR := tests/bin
TESTS := $(TEST_BIN_DIR)/test_vectormap $(TEST_BIN_DIR)/test_hashmap

.PHONY: all run clean test

all: $(TARGET)

$(TARGET): $(OBJECTS)
	$(CC) $(CFLAGS) $(OBJECTS) -o $@
	@rm -f $(OBJECTS) $(DEPS)

bin/%.o: src/%.c
	@mkdir -p $(dir $@)
	$(CC) $(CPPFLAGS) $(CFLAGS) -MMD -MP -c $< -o $@

$(TEST_BIN_DIR):
	@mkdir -p $@

$(TEST_BIN_DIR)/test_vectormap: tests/test_vectormap.c src/vectormap.c src/entry.c | $(TEST_BIN_DIR)
	$(CC) $(CPPFLAGS) $(CFLAGS) $^ -o $@

$(TEST_BIN_DIR)/test_hashmap: tests/test_hashmap.c src/hashmap.c src/vectormap.c src/entry.c | $(TEST_BIN_DIR)
	$(CC) $(CPPFLAGS) $(CFLAGS) $^ -o $@

test: $(TESTS)
	@./$(TEST_BIN_DIR)/test_vectormap
	@./$(TEST_BIN_DIR)/test_hashmap

run: $(TARGET)
	./$(TARGET)

clean:
	rm -rf bin tests/bin

-include $(DEPS)
