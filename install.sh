#!/usr/bin/env bash

PREFIX=/usr/local
if [ "$(uname)" == "Darwin" ]; then
install -m 644 -v libprinthex.a $PREFIX/lib
install -m 644 -v printhex.h    $PREFIX/include
else
install -m 644 -v -g root -o root libprinthex.a $PREFIX/lib
install -m 644 -v -g root -o root printhex.h    $PREFIX/include
fi
