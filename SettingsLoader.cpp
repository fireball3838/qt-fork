#include "SettingsLoader.h"
#include <QDebug>

void SettingsLoader::readini(int &amount) {
    ini.beginGroup("System.Setting");
    //QStringList keys = ini.allKeys();
    //qDebug() << keys;
    amount = ini.value("number_of_classes").toInt();
    ini.endGroup();
}
