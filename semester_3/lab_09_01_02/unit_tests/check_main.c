#include "check_read.h"
#include "check_memory.h"
#include "check_sort.h"

int main(void)
{
    int failed_tests = 0;

    failed_tests += tests_default_subject();

    failed_tests += tests_get_size_string();
    failed_tests += tests_get_size_struct();

    failed_tests += tests_str_shift_left();
    failed_tests += tests_trim_beg_end_str();

    failed_tests += tests_read_struct_info();
    failed_tests += tests_read_struct();

    failed_tests += tests_check_prefix();
    failed_tests += tests_file_is_empty();

    failed_tests += tests_allocate_and_free_malloc_string();
    failed_tests += tests_allocate_and_free_malloc_structs();

    failed_tests += test_sort_array_by_density();

    return failed_tests;
}
