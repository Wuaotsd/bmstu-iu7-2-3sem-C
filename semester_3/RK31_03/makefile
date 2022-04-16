SRC_DIR := ./src
INC_DIR := ./inc
OUT_DIR := ./out

CC := gcc
CFLAGS := -std=c99 -Werror -Wall -Wpedantic  -ggdb -I$(INC_DIR)/

OBJECTS_ALL := $(OUT_DIR)/allocate.o $(OUT_DIR)/read.o $(OUT_DIR)/sort.o $(OUT_DIR)/print.o
OBJECTS_MAIN := $(OUT_DIR)/main.o


%.exe: $(OBJECTS_MAIN) $(OBJECTS_ALL)
	$(CC) -o $@ $^

$(OUT_DIR)/%.o: $(SRC_DIR)/%.c  $(INC_DIR)/*.h object_dir
	$(CC) $(CFLAGS) -c $< -o $@


.PHONY: object_dir
object_dir:
	@mkdir -p $(OUT_DIR)

.PHONY: clean
clean:
	$(RM) $(OUT_DIR)/*.o
	$(RM) *.exe
	$(RM) *.o
	rm -rf $(OUT_DIR)

