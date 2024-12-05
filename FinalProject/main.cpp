//
//  main.cpp
//  FinalProject
//
//  Created by Kaustubh on 11/10/24.
//

#include "hamming.hpp"
#include <fstream>
#include <vector>
#include <iomanip>

int main(int argc, const char * argv[])
{
    std::vector<std::string> lines;
    std::ifstream f(argv[1]);
    std::string line;
    while(std::getline(f, line)) {
        lines.push_back(line);
    }
    
    std::vector<Hamming> codeWords;
    for(int i = 0; i < lines.size(); i++) {
        Hamming codeWord = Hamming(lines[i]);
        codeWords.push_back(codeWord);
    }
    
    for(Hamming ham : codeWords) {
        ham.errorReport();
    }
    
    return 0;
}
