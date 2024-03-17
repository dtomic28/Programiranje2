//
// Created by danijel on 3/17/2024.
//

#ifndef PROGRAMIRANJE2_TEXTUTILITY_H
#define PROGRAMIRANJE2_TEXTUTILITY_H
#include <string>
#include <vector>

class TextUtility {
private:
    TextUtility();
public:
    static std::string floatToString(float value, unsigned int numDecimals);
    static unsigned int countWords(const std::string& str);
    static std::string capitalizeWords(const std::string& str);
    static std::vector<int> extractIntNumbers(const std::string& str);
    static unsigned int countSpacesInString(const std::string& str);
};


#endif //PROGRAMIRANJE2_TEXTUTILITY_H
