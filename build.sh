#!/bin/bash

if type "clang" > /dev/null 2>&1 ; then
    CC=clang
elif type "gcc" > /dev/null 2>&1 ; then
    CC=gcc
else
    echo -e "\e[1;31mNo compiler found! Please install clang or gcc.\e[0m"
    exit 1
fi

$CC -O2 -std=c99 -I. -c -o printhex.o printhex.c || exit 1

rm libprinthex.a > /dev/null 2>&1
ar qfs libprinthex.a printhex.o

