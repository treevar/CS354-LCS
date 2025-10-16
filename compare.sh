#!/bin/bash
stringA="AGGTAB"
stringB="GXTXAYB"
echo "String A: $stringA"
echo "String B: $stringB"
echo
echo "Running Bad LCS..."
echo
{ echo "$stringA"; echo "$stringB"; } | ./bin/lcs_bad
echo
echo "Running Regular DP LCS..."
echo
{ echo "$stringA"; echo "$stringB"; } | ./bin/lcs
echo
echo "Running Space Optimized DP LCS..."
echo
{ echo "$stringA"; echo "$stringB"; } | ./bin/lcs_op
