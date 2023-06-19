#pragma once

#ifndef FINAL_PRACTICE_UTILS_H
#define FINAL_PRACTICE_UTILS_H

#include <iostream>
#include <string>

namespace Utils
{
    template<typename InputT>
    static InputT getInputNum(const std::string& description)
    {
        InputT num = 0;
        std::string tmpLine;
        while(true)
        {
            try
            {
                std::cout << description;
                std::getline(std::cin, tmpLine);
                num = stoi(tmpLine);

                return num;
            }
            catch(const std::exception& e)
            {
                std::cout << e.what() << std::endl;
            }
        }
    }

    static std::string getLine(const std::string& description)
    {
        std::string tmpString;

        std::cout << description;
        std::cin.sync();

        std::getline(std::cin, tmpString);

        return tmpString;
    }
}

#endif //FINAL_PRACTICE_UTILS_H
