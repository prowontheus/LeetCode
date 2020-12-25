//
// Created by 丁月星 on 2020/12/24.
//

#ifndef LEETCODE_0000DEF_H
#define LEETCODE_0000DEF_H

#include <iostream>
#include <vector>
#include <string>

template<typename T>
void printVec(std::vector<T>& vec)
{
    std::cout << "{";
    for(auto a:vec)
    {
        std::cout << a << ",";
    }
    std::cout << "}" << std::endl << "vec.size()=" << vec.size() << std::endl << std::endl;
}

template<>
void printVec(std::vector<std::string>& vec)
{
    for(auto a:vec)
    {
        std::cout << "{";
        for(auto b:a)
        {
            std::cout << b << ",";
        }
        std::cout << "}" << std::endl;
    }
    std::cout << "vec.size()=" << vec.size() << std::endl << std::endl;
}

template<typename T>
void printVec(std::vector<std::vector<T>>& vec)
{
    for(auto a:vec)
    {
        std::cout << "{";
        for(auto b:a)
        {
            std::cout << b << ",";
        }
        std::cout << "}" << std::endl;
    }
    std::cout << "vec.size()=" << vec.size() << std::endl << std::endl;
}

#endif //LEETCODE_0000DEF_H
