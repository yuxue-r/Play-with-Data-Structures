//
// Created by yyz on 2020/4/8.
//

#ifndef INC_07_SET_AND_MAP_SOLUTION_H
#define INC_07_SET_AND_MAP_SOLUTION_H

#include <set>
#include <iostream>
#include <string>
#include <vector>

class Solution
{
public:
    int uniqueMorseRepresentations(std::vector<std::string> &words) {
        std::vector<std::string> morse = {".-", "-...", "-.-.", "-..", ".", "..-.", "--.", "....", "..", ".---", "-.-",
                                          ".-..", "--", "-.", "---", ".--.", "--.-", ".-.", "...", "-", "..-", "...-",
                                          ".--", "-..-", "-.--", "--.."};
        std::set<std::string> Set;
        for (const std::string &word : words) {
            std::cout << '"' << word << '"' << " -> ";
            std::string code = "";
            for (char c : word) {
                code += morse[c - 'a'];
            }
            std::cout << '"' << code << '"' << std::endl;
            Set.insert(code);
        }
        return Set.size();
    }
};


#endif //INC_07_SET_AND_MAP_SOLUTION_H
