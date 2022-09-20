#include "ClassThird.h"
#include <iostream>
#include <unistd.h>
#include <unistd.h>


ClassThird::ClassThird() {
    qDebug() << "Third class created in " << getpid() <<" id\n";
}

void ClassThird::action() {
    long k;
    for (long i = 0; i < 9999999; i++) {
        k = i;
    }
    std::cout << "Process 3 is finished. " << k;
}
