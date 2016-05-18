//
//  main.cpp
//  lib
//
//  Created by Denis on 10.04.16.
//  Copyright © 2016 DenisM. All rights reserved.
//

#include <iostream>
#include "Library.hpp"

using namespace std;

int main(int argc, const char * argv[]) {
    
    Library s;
    s = "Privet";
    cout << "Plan text - " << &s << endl;
    return 0;
}
