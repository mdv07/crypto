//
//  MyString.hpp
//  mylib
//
//  Created by Denis on 10.04.16.
//  Copyright © 2016 DenisM. All rights reserved.
//

#ifndef MyString_hpp
#define MyString_hpp

#include <stdio.h>
class MyString{
public:
    MyString();
    MyString(const char*);
    MyString(const MyString&);
    char *getCharPtr();
    ~MyString();
private:
    size_t _size;
    char *_string;
};

#endif /* MyString_hpp */
