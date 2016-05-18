//
//  Library.hpp
//  lib
//
//  Created by Denis on 10.04.16.
//  Copyright © 2016 DenisM. All rights reserved.
//

#ifndef Library_hpp
#define Library_hpp

#include <stdio.h>

class Library{
public:
    Library();
    Library(const char*);
    ~Library();
private:
    int _size;
    char *_string;
};
#endif /* Library_hpp */
