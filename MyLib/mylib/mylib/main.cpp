//
//  main.cpp
//  mylib
//
//  Created by Denis on 10.04.16.
//  Copyright © 2016 DenisM. All rights reserved.
//

#include <iostream>
#include "MyString.hpp"
//#include "Rijnadael.h"
using namespace std;

int main(int argc, const char * argv[]) {
    
    char ch[] = "привет";
    MyString s = ch;
    
    cout<<"Текст : \n"<< s.getCharPtr() <<endl;
    
    return 0;
}
