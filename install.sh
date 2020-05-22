#!/usr/bin/env bash

PREFIX=/usr/local

install -m 644 -v -g root -o root libprinthex.a $PREFIX/lib
install -m 644 -v -g root -o root printhex.h    $PREFIX/include

