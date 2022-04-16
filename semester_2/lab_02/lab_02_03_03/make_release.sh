#!/bin/bash
gcc -std=c99 -Werror -Wall -Wpedantic -Wextra -Wvla -Wfloat-equal -Wfloat-conversion -c main.c
gcc -o main.exe main.o