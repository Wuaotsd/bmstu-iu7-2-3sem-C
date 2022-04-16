#!/bin/bash
gcc -std=c99 -Werror -Wall -Wpedantic -Wextra -Wvla -Wfloat-equal -Wfloat-conversion -g3 -c -coverage main.c
gcc -o main.exe -coverage main.o