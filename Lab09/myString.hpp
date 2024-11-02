//
//  myString.hpp
//  Lab09
//
//  Created by Kaustubh on 10/29/24.
//

#ifndef myString_hpp
#define myString_hpp

#include <stdio.h>
#include <string>
#include <vector>

class MyString
{
private:
    std::vector<char> charVector;
    
public:
    MyString() {}
    MyString(std::string inputString);
    ~MyString();
    std::string toString();
    int length();
    std::string substr(int start);
    std::string substr(int start, int n);
    std::vector<char> getCharVector();
    friend MyString operator+(const MyString& add);
    friend std::ostream& operator<<(std::ostream& os, const MyString& out);
    bool operator==(const MyString& compare) const;
    bool operator!=(const MyString& compare) const;
    bool operator<=(const MyString& compare) const;
    bool operator>=(const MyString& compare) const;
    bool operator<(const MyString& compare) const;
    bool operator>(const MyString& compare) const;
};

#endif /* myString_hpp */
