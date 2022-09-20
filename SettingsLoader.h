#ifndef SETTINGSLOADER_H
#define SETTINGSLOADER_H

#include <QSettings>

class SettingsLoader {
public:

    /**
     * @brief Opens ini settings file
     * @param File location
     */
    SettingsLoader(): ini("/home/deu/fork/settings.ini", QSettings::NativeFormat) {}

    /**
     * @brief Reads info from file
     * @return Amount of classes (by reference)
     */
    void readini(int &amount);

private:
    QSettings ini;
};

#endif // SETTINGSLOADER_H
