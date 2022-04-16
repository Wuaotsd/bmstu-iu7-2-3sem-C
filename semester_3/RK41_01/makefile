CC = gcc
SRC_DIR := ./src
INC_DIR := ./inc
OUT_DIR := ./out

CFLAGS =-std=c99 -Wall -Werror -Wpedantic -ggdb -I$(INC_DIR)
LFLAGS =--coverage
.PHONY : clean dir release debug func
.NOTPARALLEL: release debug

release: CFLAGS+= -o2
release: $(OUT_DIR)/release.lastbuildstate app.exe

debug: CFLAGS+= --coverage
debug: LFLAGS+= -g3
debug: $(OUT_DIR)/debug.lastbuildstate app.exe

func: CFLAGS+= --coverage
func: LFLAGS+= -g3

OBJECTS_ALL := $(OUT_DIR)/list_op.o $(OUT_DIR)/read_students.o $(OUT_DIR)/print_students.o
OBJECTS_MAIN := $(OUT_DIR)/main.o

%.exe: $(OBJECTS_MAIN) $(OBJECTS_ALL)
	$(CC) $(LFLAGS) -ggdb -o $@ $^

$(OUT_DIR)/%.o: $(SRC_DIR)/%.c | dir
	$(CC) $(CFLAGS) -c $^ -o $@

$(OUT_DIR)/release.lastbuildstate: | dir
	rm -rf *.exe $(OUT_DIR)/*.o $(OUT_DIR)/debug.lastbuildstate
	touch $(OUT_DIR)/release.lastbuildstate

$(OUT_DIR)/debug.lastbuildstate: | dir
	rm -rf *.exe $(OUT_DIR)/*.o $(OUT_DIR)/release.lastbuildstate
	touch $(OUT_DIR)/debug.lastbuildstate

dir:
	mkdir -p $(OUT_DIR)/

func:
	cd $(FTESTS_DIR) && bash all_tests.sh

clean :
	rm -fv *.exe
	rm -fv $(OUT_DIR)/*.o
	rm -fv $(OUT_DIR)/*.gcno
	rm -fv $(OUT_DIR)/*.gcda
	rm -rf $(OUT_DIR)/*.lastbuildstate
	rm -rf $(OUT_DIR)