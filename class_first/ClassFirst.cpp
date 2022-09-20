#include "ClassFirst.h"
#include <iostream>
#include <QDebug>


ClassFirst::ClassFirst() {
    std::cout << "First class created\n";
}

void ClassFirst::run() {
    qDebug()  << "Fist class is working...\n";
    while (true) {}
}
