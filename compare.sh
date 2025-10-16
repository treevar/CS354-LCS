#!/bin/bash
if [ $# -gt 0 ]; then
    stringA="ABCDEABCDEF"; stringB="AXYZBCDEABCF"; # Lengths 11 and 12
else
    stringA="abcde"; stringB="ace"; # Lengths 5 and 3
fi
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
