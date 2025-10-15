#include <iostream>
#include <string>
#include <cstring>
#include "Timer.h"

int lcs(const std::string &a, const std::string &b){
    const int rowSize = b.length()+1;
    const int byteCount = rowSize * sizeof(int);

    int *prev = new int[rowSize], *cur = new int[rowSize], *temp; //Only need the previous and current rows

    memset(prev, 0, byteCount);
    memset(cur, 0, byteCount);

    for(int i = 1; i <= a.length(); ++i){
        for(int j = 1; j <= b.length(); ++j){
            if(a[i-1] == b[j-1]){ //Add 1 to diagonal
                cur[j] = prev[j-1] + 1;
            }
            else{
                cur[j] = std::max(cur[j-1], prev[j]); //Max of left and above
            }
        }
        //Swap rows
        temp = prev;
        prev = cur;
        cur = temp;
        memset(cur, 0, byteCount);
    }

    int value = prev[rowSize-1];

    delete[] cur;
    delete[] prev;

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