#include <iostream>
#include <string>
#include <cstring>
#include "Timer.h"

/* A B >
   V0000
    0000
    0000
*/

int lcs(const std::string &a, const std::string &b){
    const int TABLE_SIZE = (a.length()+1) * (b.length()+1);
    int *table = new int[TABLE_SIZE];
    memset(table, 0, TABLE_SIZE * sizeof(typeof(table[0]))); //0 array

    auto tableAt = [&](int col, int row){
        return table + (col + row * b.length());
    };

    for(int i = 1; i <= b.length(); ++i){
        for(int j = 1; j <= a.length(); ++j){
            if(a[j-1] == b[i-1]){
                *tableAt(i, j) = *tableAt(i-1, j-1) + 1;
            }
            else{
                *tableAt(i, j) = std::max(*tableAt(i, j-1), *tableAt(i-1, j));
            }
        }
    }
    int value = *tableAt(b.length(), a.length());
    delete[] table;
    return value;
}

int main(){
    std::string a, b;
    std::cout << "Longest Common Subsequence Length Calculator\n";
    std::cout << "Enter first string: ";
    std::cin >> a;
    std::cout << "Enter second string: ";
    std::cin >> b;
    Timer runtime{TimerUnits::Unit::Micro};

    int lcsLen = lcs(a, b);
    runtime.end();
    
    std::cout << "LCS: " << lcsLen << '\n';
    std::cout << "Ran in " << runtime << '\n';
    return 0;
}