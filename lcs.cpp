#include <iostream>
#include <string>
#include <cstring>
#include "Timer.h"

int lcs(const std::string &a, const std::string &b){
    const int TABLE_SIZE = (b.length()+1) * (a.length()+1);
    int *table = new int[TABLE_SIZE];
    memset(table, 0, TABLE_SIZE * sizeof(typeof(table[0]))); //0 array

    auto tableAt = [&](int col, int row){
        return table + (col + row * a.length());
    };

    for(int i = 1; i <= a.length(); ++i){
        for(int j = 1; j <= b.length(); ++j){
            if(b[j-1] == a[i-1]){
                *tableAt(i, j) = *tableAt(i-1, j-1) + 1;
            }
            else{
                *tableAt(i, j) = std::max(*tableAt(i, j-1), *tableAt(i-1, j));
            }
        }
    }
    int value = *tableAt(a.length(), b.length());
    delete[] table;
    return value;
}

std::string promptForStr(const std::string &prompt){
    std::cout << prompt << "\n > ";
    std::string str{};
    std::getline(std::cin, str);
    return str;
}

int main(){
    std::string a, b;
    std::cout << "Longest Common Subsequence Length Calculator\n";
    a = promptForStr("Enter first string:");
    b = promptForStr("Enter second string:");

    Timer runtime{TimerUnits::Unit::Micro};

    int lcsLen = lcs(a, b);
    runtime.end();
    
    std::cout << "LCS: " << lcsLen << '\n';
    std::cout << "Ran in " << runtime << '\n';
    return 0;
}