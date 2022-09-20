#include "SettingsLoader.h"
#include <QDebug>

void SettingsLoader::readini(int &amount, std::vector <bool> &toBeEnabled) {
    amount = 0;
    toBeEnabled.clear();

    ini.beginGroup("System.Setting");
    foreach (const QString &key, ini.childKeys()) {
        amount++;
        toBeEnabled.push_back( ini.value(key).toBool() );
    }
    ini.endGroup();
}
