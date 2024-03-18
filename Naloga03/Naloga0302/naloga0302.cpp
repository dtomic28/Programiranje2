//
// Created by danijel on 3/17/2024.
//
#include <iostream>
#include "TextUtility.h"

using namespace std;

void printVector(vector<int> nums){
    cout << "Num of items in vector: " << nums.size() << endl;
    for(int i = 0; i<nums.size();i++){
        cout << "Item " << i << ": " << nums[i] << endl;
    }
}

int main(){
    float f = 3.14159265;

    cout << "3.14159265 to string with 4 decimals: " <<TextUtility::floatToString(f, 4) << endl;

    const std::string str = "lorem ipSUM dolor sit AMET 12, ConsecTetur adipiscing elit15, sed do eiusmod -16.";
    vector<int> nums = TextUtility::extractIntNumbers(str);

    cout << "Words in test string: " << TextUtility::countWords(str) << endl;

    cout << "Spaces in test string: " << TextUtility::countSpacesInString(str) << endl;

    cout << "Capitalize words in test string: " <<TextUtility::capitalizeWords(str) << endl;

    cout << endl;
    printVector(nums);

    string test = "I love to read articles on read Favtutor.";

    cout << TextUtility::replace(test, "read", "  ") << endl;

    return 0;
}