#!/bin/sh

clang -std=c99 -L. -I. -o phtest test.c -lprinthex && ./phtest

