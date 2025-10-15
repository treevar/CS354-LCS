# Longest Common Subsequence
## Problem
Given string a, b find the longest common subsequence.
## Approaches
### Calculate all possible subsequences and check (2^n)
First we remove all characters that aren't common among strings\
For every character in string a we either keep the character or drop it. \
We do this for every char and then for every char in the resulting subsequences.\
This results in S 2^n runtime where n = len(a)
### Dynamic Programming (n * m) where n = len(a)+1, m = len(b)+1
[Source](./lcs.cpp)\
For this approach we build a 2d array that is n * m and set it to 0\
Then we check every char of the strings to see they match.\
If it does then we set table[i][j] to table[i-1][j-1] + 1\
If it doesnt then we set it to max(table[i][j-1], table[i-1][j])\
With this method we save the previous results of whether the chars match.\
If they match the left diagonal contains the number of char matches before.\
If they don't match we set the cell to the max of the cell to the left and above, this cascades the LCS length so far downward.\
The LCS length will be in table[n-1][m-1] because of this.
### Dyanmic Programming with space optimization (n * m) where n = len(a)+1, m = len(b)+1
[Source](./lcs_space_op.cpp)\
This is very similar to the regular DP method but uses much less space.\
Since we only ever look at the previous row, we don't need to save any other rows.\
This method only saves the previous and current row and discards the rest.\
The space used is only 2 * min(n, m) comapred to the regular DP method where teh apce used is n * m