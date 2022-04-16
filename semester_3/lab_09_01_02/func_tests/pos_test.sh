#!/bin/bash

../main.exe `cat pos_"$1"_args.txt` > "out.txt"
rc=$?
errors=("EXIT_SUCCESS" "ARGV_ERR" "PARAMS_ERR" "FILE_NOT_FOUND" "FILE_IS_EMPTY " "STRUCT_ERROR" "NEGATIVE_DATA" "NOT_FOUND_STRUCT" "MEMORY_ERR")

{
FC out.txt pos_"$1"_out.txt
  rc_f=$?
} &> /dev/null

if [ $rc == 0 ] && [ $rc_f == 0 ]
then
    echo -e POS_"$1": "\e[32mPASSED\e[0m Код ошибки: ${errors[rc]} = $rc"
else
    FC out.txt pos_"$1"_out.txt
    echo -e POS_"$1": "\e[31mFAILED\e[0m Код ошибки: ${errors[rc]} = $rc"
fi
rm out.txt

