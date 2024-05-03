//
// Created by Danijel Tomić on 14. 04. 24.
//

#ifndef PROGRAMIRANJE2_VECTORUTIL_H
#define PROGRAMIRANJE2_VECTORUTIL_H
#include <vector>
#include <iostream>
#include <sstream>
#include <random>
#include <string>
#include <stdexcept>

template <typename T>
void fillDefault(std::vector<T>& vec, int n)
{
    vec.clear();
    for (int i = 0; i < n; ++i)
    {
        vec.push_back(T());
    }
}

template <>
void fillDefault<int>(std::vector<int>& vec, int n)
{
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> dis(1, 100);

    vec.clear();
    for (int i = 0; i < n; ++i)
    {
        vec.push_back(dis(gen));
    }
}

template <typename T>
void print(const std::vector<T>& vec)
{
    std::cout << "[ ";
    for (const auto& item : vec)
    {
        std::cout << item << " ";
    }
    std::cout << "]";
    std::cout << std::endl;
}

template <typename T>
std::vector<T> reverse(const std::vector<T>& vec)
{
    std::vector<T> revVec;
    for (auto it = vec.rbegin(); it != vec.rend(); ++it)
    {
        revVec.push_back(*it);
    }
    return revVec;
}

template <typename T>
std::vector<int> toInt(const std::vector<T>& vec)
{
    std::vector<int> intVec;
    for (const auto& item : vec)
    {
        std::stringstream ss;
        ss << item;
        std::string s = ss.str();
        try
        {
            intVec.push_back(std::stoi(s));
        }
        catch (const std::invalid_argument&)
        {
            std::cout << "Exception: stoi for " << s << std::endl;
        }
    }
    return intVec;
}

template <typename T>
std::vector<T> mergeVectors(std::vector<std::vector<T>> vec)
{
    std::vector<T> result;

    for (int i = 0; i < vec.size(); i++)
    {
        for (int j = 0; j < vec[i].size(); j++)
        {
            result.push_back(vec[i][j]);
        }
    }
    return result;
}

#endif  // PROGRAMIRANJE2_VECTORUTIL_H
