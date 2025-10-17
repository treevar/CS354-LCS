#!/bin/bash
if [ $# -gt 0 ]; then
    stringA="ABCDEABCDEF"; stringB="AXYZBCDEABCF"; # Lengths 11 and 12
    badBin="./bin/lcs_bad 1" # Use seconds for timing
else
    stringA="abcde"; stringB="ace"; # Lengths 5 and 3
    badBin="./bin/lcs_bad" # Use microseconds for timing
fi
echo "String A: $stringA"
echo "String B: $stringB"
echo
echo "Running Bad LCS..."
echo
{ echo "$stringA"; echo "$stringB"; } | $badBin
echo
echo "Running Regular DP LCS..."
echo
{ echo "$stringA"; echo "$stringB"; } | ./bin/lcs
echo
echo "Running Space Optimized DP LCS..."
echo
{ echo "$stringA"; echo "$stringB"; } | ./bin/lcs_op
