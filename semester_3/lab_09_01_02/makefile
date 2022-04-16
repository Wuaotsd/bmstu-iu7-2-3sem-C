SRC_DIR := ./src
INC_DIR := ./inc
OUT_DIR := ./out

CC := gcc
CFLAGS := -std=c99 -Werror -Wall -Wpedantic  -ggdb -I$(INC_DIR)/

FTESTS_DIR := ./func_tests
UTESTS_DIR := ./unit_tests

OBJECTS_ALL := $(OUT_DIR)/memory.o $(OUT_DIR)/read_struct.o $(OUT_DIR)/read_check.o $(OUT_DIR)/sort_struct.o $(OUT_DIR)/print_struct.o
OBJECTS_MAIN := $(OUT_DIR)/main.o
OBJECTS_UNIT := $(OUT_DIR)/check_main.o $(OUT_DIR)/check_read.o $(OUT_DIR)/check_memory.o $(OUT_DIR)/check_sort.o

%.exe: $(OBJECTS_MAIN) $(OBJECTS_ALL)
	$(CC) -o $@ $^

unit_tests.exe: $(OBJECTS_UNIT) $(OBJECTS_ALL)
	$(CC) -o $@ $^

$(OUT_DIR)/check_%.o: ${UTESTS_DIR}/check_%.c ${INC_DIR}/*.h objects_dir
	$(CC) $(CFLAGS) -c $< -o $@

$(OUT_DIR)/%.o: ${SRC_DIR}/%.c ${INC_DIR}/*.h objects_dir
	$(CC) $(CFLAGS) -c $< -o $@

.PHONY: objects_dir
objects_dir:
	@mkdir -p $(OUT_DIR)

.PHONY: func
func:
	cd $(FTESTS_DIR) && bash all_tests.sh

.PHONY: clean
clean:
	$(RM) -rf $(OUT_DIR)
	$(RM) *.exe *.o
	$(RM) -rf ./.idea
