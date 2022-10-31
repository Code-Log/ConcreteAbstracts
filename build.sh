#!/bin/bash

mkdir build
cd build && cmake .. -DCMAKE_CXX_CLANG_TIDY=$(which clang-tidy) -DCMAKE_EXPORT_COMPILE_COMMANDS=ON
