#!/bin/bash
gcc ../src/big_int.c test.c -o test.out && valgrind --tool=memcheck --leak-check=yes --track-origins=yes ./test.out && rm -rf *.out