#ifndef SETTINGSLOADER_H
#define SETTINGSLOADER_H

#include <QSettings>

class SettingsLoader {
public:
    SettingsLoader(): ini("/home/deu/fork/settings.ini", QSettings::NativeFormat) {}
    void readini(int &amount);
private:
    QSettings ini;
};

#endif // SETTINGSLOADER_H
