//
//  Library.cpp
//  lib
//
//  Created by Denis on 10.04.16.
//  Copyright © 2016 DenisM. All rights reserved.
//

#include "Library.hpp"
#include <cstring>

inline Library::Library(){
    _size = 0;
    _string = 0;
}
inline Library::Library(const char *str){
    if (!str) {
        _size = 0;
        _string = 0;
    } else {
        str = "This is SPARTA!";
        _size = strlen (str);
        _string = new char(_size + 1);
        strcpy(_string, str);
    }
}
inline Library::~Library(){
    delete []_string;
}


