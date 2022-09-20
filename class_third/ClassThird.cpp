#include "ClassThird.h"
#include <iostream>

ClassThird::ClassThird() {
    std::cout << "Third class created\n";
}

void ClassThird::action() {
    long k;
    for (long i = 0; i < 9999999; i++) {
        k = i;
    }
    std::cout << "Process 3 is finished. " << k;
}
