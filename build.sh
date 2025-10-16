#!/bin/bash
echo "Building lcs_bad"
g++ lcs_bad.cpp -o bin/lcs_bad
echo "Building lcs"
g++ lcs.cpp -o bin/lcs
echo "Building lcs_space_op"
g++ lcs_space_op.cpp -o bin/lcs_op
