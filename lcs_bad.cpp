#include <iostream>
#include <string>
#include <cstring>
#include "Timer.h"

//Returns whether str contains seq as a subsequence
bool containsSubsequence(const std::string &str, const std::string &seq){
    int seqIndex = 0;
    for(int i = 0; i < str.length() && seqIndex < seq.length(); ++i){
        if(str[i] == seq[seqIndex]){
            ++seqIndex;
        }
    }
    return seqIndex == seq.length(); //If we reached the end of seq, all chars were found in order
}

int checkSubSeq(const std::string &str, std::string seq, int curMax = 0){
    if(seq.empty()){
        return 0;
    }
    if(seq.length() <= curMax){
        return 0; //No need to check smaller subsequences
    }
    if(containsSubsequence(str, seq)){ 
        return seq.length(); //All other subsequences will be shorter
    }
    int maxLen = 0;
    for(int i = 0; i < seq.length(); ++i){ //Try removing each char from seq and see if it is a subsequence
        std::string subSeq = seq;
        subSeq.erase(i, 1);
        int len = checkSubSeq(str, subSeq, curMax);
        if(len > maxLen){
            maxLen = len;
        }
    }
    return maxLen;
}

int lcs(const std::string &a, const std::string &b){
    //Ensure we are always checking if the shorter string is a subsequence of the longer string
    return checkSubSeq(a.length() > b.length() ? a : b, a.length() > b.length() ? b : a);
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