#include "ClassFirst.h"
#include <iostream>
#include <QDebug>
#include <unistd.h>

ClassFirst::ClassFirst() {
    qDebug() << "First class created in " << getpid() <<" thread id\n";
}

void ClassFirst::run() {
    qDebug()  << "Fist class is working...\n";
    while (true) {}
}
