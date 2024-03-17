//
// Created by danijel on 3/17/2024.
//

#include "TextUtility.h"
#include <sstream>


TextUtility::TextUtility() {}

std::string TextUtility::floatToString(float value, unsigned int numDecimals) {
    std::ostringstream oss;
    oss.precision(numDecimals);
    oss << std::fixed << value;
    return oss.str();
}

unsigned int TextUtility::countWords(const std::string &str) {
    return countSpacesInString(str)+1;
}

std::string TextUtility::capitalizeWords(const std::string &str) {
    std::string result = str;
    for(char& ch : result){
        ch = std::tolower(ch);
    }
    char previousChar = ' ';
    for(char& ch : result){
        if(previousChar == ' '){
            ch = std::toupper(ch);
        }
        previousChar = ch;
    }
    return result;
}

std::vector<int> TextUtility::extractIntNumbers(const std::string &str) {
    std::vector<int> numbers;
    int currentNum = 0;
    bool isNegative = false;
    for(auto ch: str){
        if(std::isdigit(ch)){
            currentNum *= 10;
            currentNum += ch - '0';
        }else if(currentNum > 0 && !std::isdigit(ch)){
            if(isNegative)
                currentNum *= -1;
            isNegative = false;
            numbers.push_back(currentNum);
            currentNum = 0;
        }else if(ch == '-'){
            isNegative = true;
        }
    }
    return numbers;
}

unsigned int TextUtility::countSpacesInString(const std::string &str) {
    int c = 0;
    for(auto ch: str){
        if(ch == ' ')
            c++;
    }
    return c;
}
