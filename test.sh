#!/bin/bash

gcc -std=c99 -L. -I. -o phtest test.c -lprinthex && ./phtest

