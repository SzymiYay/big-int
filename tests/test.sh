#!/bin/bash
gcc ../src/big_int.c test.c -o test.out && ./test.out && rm -rf *.out