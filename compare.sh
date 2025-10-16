#!/bin/bash
stringA="AGGTAB"
stringB="GXTXAYB"
echo "String A: $stringA"
echo "String B: $stringB"
echo "Running Non-Space Optimized LCS..."
echo
{ echo "$stringA $stringB"; } | ./bin/lcs
echo
echo "Running Space Optimized LCS..."
echo
{ echo "$stringA $stringB"; } | ./bin/lcs_op
