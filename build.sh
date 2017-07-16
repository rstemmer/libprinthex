#!/bin/bash

gcc -O2 -std=c99 -I. -c -o printhex.o printhex.c || exit 1

rm libprinthex.a > /dev/null 2>&1
ar qfs libprinthex.a printhex.o

