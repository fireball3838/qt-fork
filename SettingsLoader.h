#ifndef SETTINGSLOADER_H
#define SETTINGSLOADER_H

#include <QSettings>
#include <vector>

class SettingsLoader {
public:

    /**
     * @brief Opens ini settings file
     * @param File location
     */
    SettingsLoader(): ini("/home/deu/fork/settings.ini", QSettings::NativeFormat) {}

    /**
     * @brief Reads info from file
     * @param Variable to contain amount of classes and a vector to contain list of classes that are needed to be enabled
     * @return Amount of classes, list of classes that are needed to be enabled (by reference)
     */
    void readini(int &amount, std::vector <bool> &toBeEnabled);

private:
    QSettings ini;
};

#endif // SETTINGSLOADER_H
