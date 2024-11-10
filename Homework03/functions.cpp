//
//  functions.cpp
//  Project3
//
//  Created by Kaustubh Holcomb on 11/8/24.
//

#include <sstream>
#include <iostream>

class Functions {
public:
    // Problem 1: Common Permutations
    std::vector<std::string> permutations(std::vector<std::string> wordList)
    {
        
        std::vector<std::string> input = wordList;
        std::vector<std::string> output;
        
        for(int i = 0; i < input.size() - 1; i = i + 2) {
            std::string push = "";
            for(int j = 0; j < input[i].size(); j++) {
                char search = input[i][j];
                size_t pos = input[i+1].find(search);
                if(pos != std::string::npos) {
                    input[i+1].erase(pos, 1);
                    push += search;
                }
            }
            output.push_back(push);
        }
        
        return output;
    }

    // Problem 4: Primary Arithmetic
    void arithmetic(std::string inputLines)
    {
        
        std::vector<std::vector<int>> problems;
        std::stringstream ss(inputLines);
        std::string temp;
        
        while(std::getline(ss, temp)) {
            if(temp.compare("0 0") == 0) break;
            else {
                for(int i = 0; i < temp.size(); i++) {
                    if(temp[i] == ' ') {
                        std::string str1 = temp.substr(0,i);
                        std::string str2 = temp.substr(i+1,std::string::npos);
                        std::vector<int> add;
                        add.push_back(std::stoi(str1));
                        add.push_back(std::stoi(str2));
                        problems.push_back(add);
                    }
                }
            }
        }
        
        std::vector<int> output;
        for(int i = 0; i < problems.size(); i++) {
            int carry = 0;
            int count = 0;
            while(problems[i][0] > 0 || problems[i][1] > 0) {
                int d1 = problems[i][0] % 10;
                int d2 = problems[i][1] % 10;
                int temp = d1 + d2 + carry;
                if (temp > 9) {
                    carry = 1;
                    count++;
                } else {
                    carry = 0;
                }
                problems[i][0] /= 10;
                problems[i][1] /= 10;
            }
            output.push_back(count);
        }
        
        for(int i = 0; i < output.size(); i++) {
            if(output[i] == 0) {
                std::cout << "No carry operation." << std::endl;
            } else if(output[i] == 1) {
                std::cout << "1 carry operation." << std::endl;
            } else {
                std::cout << output[i] << " carry operations." << std::endl;
            }
        }
    }

};
