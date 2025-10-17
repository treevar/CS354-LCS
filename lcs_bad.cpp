#include <iostream>
#include <string>
#include <cstring>
#include "Util.h"

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

int checkSubSeq(const std::string &str, std::string seq){
    if(seq.empty()){
        return 0;
    }
    if(containsSubsequence(str, seq)){ 
        return seq.length(); //All other subsequences will be shorter
    }
    int maxLen = 0;
    for(int i = 0; i < seq.length(); ++i){ //Try removing each char from seq and see if it is a subsequence
        std::string subSeq = seq;
        subSeq.erase(i, 1);
        int len = checkSubSeq(str, subSeq);
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

//Returns a string containing chars that are not common
std::string uncommonChars(const std::string &a, const std::string &b){
    std::string result {};
    for(char c : a){
        if(b.find(c) == std::string::npos){
            result += c;
        }
    }
    for(char c : b){
        if(a.find(c) == std::string::npos){
            result += c;
        }
    }
    return result;
}

//Remove every char in chars from str
std::string removeChars(const std::string &str, const std::string &chars){
    std::string result {};
    for(char c : str){
        if(chars.find(c) == std::string::npos){
            result += c;
        }
    }
    return result;
}

int main(int argc, char **argv){
    std::string a, b;
    std::cout << "Longest Common Subsequence Length Calculator\n";
    a = promptForStr("Enter first string");
    b = promptForStr("Enter second string");

    Timer runtime{argc > 1 ? TimerUnits::Unit::Sec : TimerUnits::Unit::Micro};
    //Remove uncommon chars
    const std::string uc = uncommonChars(a, b);
    a = removeChars(a, uc);
    b = removeChars(b, uc);

    int lcsLen = lcs(a, b);
    runtime.end();
    
    std::cout << "LCS: " << lcsLen << '\n';
    std::cout << "Ran in " << runtime << '\n';
    return 0;
}