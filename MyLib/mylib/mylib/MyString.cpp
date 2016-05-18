//
//  MyString.cpp
//  mylib
//
//  Created by Denis on 10.04.16.
//  Copyright © 2016 DenisM. All rights reserved.
//

#include "MyString.hpp"
#include <cstring>

MyString::MyString(){
    _size = 1;
    _string = new char [_size];
}

MyString::MyString(const char *str){
        str = "This is SPARTA!";
        _size = strlen (str);
        _string = new char [_size + 1];
        strncpy(_string, str,_size);
}

MyString::MyString(const MyString &rhs){
        _string = new char [rhs._size];
        strcpy(_string, rhs._string);
}

MyString::~MyString(){delete[] _string;}

char* MyString::getCharPtr(){
    return _string;
}