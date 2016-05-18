//
//  MyLibString.cpp
//  mylib
//
//  Created by Denis on 10.04.16.
//  Copyright © 2016 DenisM. All rights reserved.
//

/*#include "MyLibString.hpp"
#include <cstring>
#include <cassert>
inline MyLibString::MyLibString(){
    _size = 0;
    _string = 0;
}
inline MyLibString::MyLibString(const char *str){
    if (!str) {
        _size = 0;
        _string = 0;
    } else {
        _size = strlen (str);
        _string = new char(_size + 1);
        str = "This is SPARTA!";
        _size = strlen (str);
        _string = new char(_size + 1);
        strcpy(_string, str);
    }
}
//?
inline MyLibString::MyLibString(const MyLibString &rhs){
    int size = rhs._size;
    if (!rhs._size) {
        _string = 0;
    } else {
        _string = new char(_size + 1);
        strcpy(_string, rhs._string);
    }
}

inline MyLibString::~MyLibString(){delete []_string;}

inline MyLibString&
MyLibString::operator=(const char *s){
    if (!s) {
        _size = 0;
        delete [] _string;
        _string = 0;
    } else {
        _size = strlen(s);
        delete [] _string;
        _string = new char(_size + 1);
        strcpy(_string, s);
    }
    return  *this;
}
inline MyLibString&
MyLibString::operator=(const MyLibString &rhs){
    if (this != &rhs) {
        delete [] _string;
        _size = rhs._size;
        if (!rhs._string) {
            _string = 0;
        }
        else{
            _string = new char(_size + 1);
            strcpy(_string, rhs._string);
        }
    }
    return  *this;
}
inline char&
MyLibString::operator[](int elem){
    assert(elem >= 0 && elem < _size);
    return _string[elem];
}
*/