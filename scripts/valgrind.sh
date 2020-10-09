#! /bin/sh

./scripts/tests.sh

valgrind ./HW01/fibbonachi_logn/tests_fibbonachi
valgrind ./HW01/fast_power/tests_power