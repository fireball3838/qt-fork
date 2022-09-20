#include "ClassSecond.h"
#include <iostream>
#include <unistd.h>
#include <unistd.h>

ClassSecond::ClassSecond() {
    qDebug() << "Second class created in " << getpid() <<" thread id\n";
}

void ClassSecond::action() {
    long k;
    for (long i = 0; i < 9999999; i++) {
        k = i;
    }
    std::cout << "Process 2 is finished. " << k;
}
