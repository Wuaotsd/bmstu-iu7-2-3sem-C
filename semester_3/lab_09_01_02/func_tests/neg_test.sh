#!/bin/bash
../main.exe `cat "neg_$1_args.txt"` > "out.txt"
rc=$?

errors=("EXIT_SUCCESS" "ARGV_ERR" "PARAMS_ERR" "FILE_NOT_FOUND" "FILE_IS_EMPTY " "STRUCT_ERROR" "NEGATIVE_DATA" "NOT_FOUND_STRUCT" "MEMORY_ERR")

{
FC out.txt neg_00_out.txt
rc_s=$?
} &> /dev/null

if [ $rc_s == 0 ] && [ $rc != 0 ]
then
    echo -e NEG_"$1": "\e[32mPASSED\e[0m Код ошибки: ${errors[rc]} = $rc"
else
    FC out.txt neg_00_out.txt
    echo -e NEG_"$1": "\e[31mFAILED\e[0m Код ошибки: ${errors[rc]} = $rc"
fi
rm "out.txt"