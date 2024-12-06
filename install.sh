#!/bin/sh

PREFIX=/usr/local
mkdir -p $PREFIX/lib
mkdir -p $PREFIX/include

if [ "$(uname)" = "Darwin" ]; then
install -m 644 -v libprinthex.a $PREFIX/lib/
install -m 644 -v printhex.h    $PREFIX/include/
elif [ "$(uname)" = "OpenBSD" -o "$(uname)" = "NetBSD" ]; then
install -m 644 -o root libprinthex.a $PREFIX/lib/
install -m 644 -o root printhex.h    $PREFIX/include/
else
install -m 644 -v -o root libprinthex.a $PREFIX/lib/
install -m 644 -v -o root printhex.h    $PREFIX/include/
fi
