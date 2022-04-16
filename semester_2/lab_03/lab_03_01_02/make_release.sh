#!/bin/bash
gcc -std=c99 -Werror -Wall -Wpedantic -Wextra -Wvla -c main.c
gcc -o main.exe main.o