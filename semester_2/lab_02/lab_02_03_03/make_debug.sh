#!/bin/bash
gcc -std=c99 -Werror -Wall -Wpedantic -Wextra -Wvla -g3 -Wfloat-equal -Wfloat-conversion -c -coverage main.c
gcc -o main.exe -coverage main.o