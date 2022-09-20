#include "ClassSecond.h"
#include <iostream>

ClassSecond::ClassSecond() {
    std::cout << "Second class created\n";
}

void ClassSecond::action() {
    long k;
    for (long i = 0; i < 9999999; i++) {
        k = i;
    }
    std::cout << "Process 2 is finished. " << k;
}
