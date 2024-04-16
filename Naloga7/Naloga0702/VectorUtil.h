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
#include <unordered_set>

enum class ColorCode
{
    Black = 30,
    Red = 31,
    Green = 32,
    Blue = 34,
    Magenta = 35,
    Cyan = 36,
    Default = 39
};

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

template <ColorCode color = ColorCode::Green, typename T>
void printColor(const std::vector<T>& vec)
{
    std::cout << "\033[" << (int) color << "m"
              << "[ "
              << "\033[0m";
    for (const auto& item : vec)
    {
        std::cout << "\033[" << (int) color << "m" << item << " "
                  << "\033[0m";
    }
    std::cout << "\033[" << (int) color << "m"
              << "]"
              << "\033[0m";
    std::cout << std::endl;
}

template <typename T>
std::vector<std::vector<T>> slice(const std::vector<T>& vec, unsigned int n)
{
    std::vector<std::vector<T>> vecVectors;
    auto numOfVectors = vec.size() / n;
    for (int i = 0; i < numOfVectors; i++)
    {
        auto leftOver = vec.size() - ((i + 1) * n);
        auto size = leftOver < n ? leftOver + 1 : n;
        std::vector<T> vecChild;
        auto end = size + (i * n);
        for (int j = (i * n); j < end; j++)
        {
            vecChild.push_back(vec[j]);
        }
        vecVectors.push_back(vecChild);
    }
    return vecVectors;
}

template <typename T>
void removeElements(std::vector<T>& vec1, const std::vector<T>& vec2)
{
    for (int i = 0; i < vec2.size(); i++)
    {
        auto item = std::find(vec1.begin(), vec1.end(), vec2[i]);
        if (item != vec1.end())
        {
            vec1.erase(item);
        }
    }
}

template <typename T>
std::vector<T> subVector(const std::vector<T>& vec, int start, int end)
{
    if (start < 0 || end > vec.size())
        throw std::invalid_argument("Index out of range");

    std::vector<T> result;
    auto startIter = vec.begin() + start;
    auto endIter = vec.begin() + end + 1;
    for (auto it = startIter; it != endIter; ++it)
    {
        result.push_back(*it);
    }
    return result;
}

template <typename T>
std::vector<T> getLarger(const std::vector<T>& vec, T item)
{
    std::vector<T> result;
    for (auto itemT : vec)
    {
        if (itemT > item)
            result.push_back(itemT);
    }
    return result;
}

template <typename T>
std::vector<T> removeDuplicates(const std::vector<T>& vec)
{
    std::vector<T> result;
    std::unordered_set<T> s;
    for (T i : vec)
        s.insert(i);
    result.assign(s.begin(), s.end());
    return result;
}

#endif  // PROGRAMIRANJE2_VECTORUTIL_H
