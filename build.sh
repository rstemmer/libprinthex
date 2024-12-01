#!/bin/sh

if command   -v "clang" > /dev/null 2>&1 ; then
    CC=clang
elif command -v "gcc" > /dev/null 2>&1 ; then
    CC=gcc
elif command -v "cc" > /dev/null 2>&1 ; then
    CC=cc
else
    printf "\033[1;31mNo compiler found! Please install clang or gcc.\033[0m\n"
    exit 1
fi

$CC -O2 -std=c99 -I. -c -o printhex.o printhex.c || exit 1

rm libprinthex.a > /dev/null 2>&1
if [ "$(uname)" = "Darwin" ]; then
ar qs libprinthex.a printhex.o
else
ar qfs libprinthex.a printhex.o
fi
