#!/usr/bin/env bash

# Compilation of `weekday`
# Works on macOS Mojave

EXEC_NAME=weekday
rm -f $EXEC_NAME

g++                   \
    -I ../src/        \
    weekday.cpp       \
    -o $EXEC_NAME     \
    && ./$EXEC_NAME
