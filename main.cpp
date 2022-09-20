#include <QCoreApplication>
#include <iostream>
#include <unistd.h>
#include <QSettings>
#include <list>
#include <chrono>
#include <thread>
#include <QDebug>
#include <sys/wait.h>

#include <SettingsLoader.h>
#include <ClassFirst.h>
#include <ClassSecond.h>
#include <ClassThird.h>



int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    static int amount;
    SettingsLoader loader;
    loader.readini(amount);
    static std::map <__pid_t, std::string> forksList;

    // todo: add list with enabled in ini file classes and in a loop below only create classes that are enabled


    __pid_t id = fork();
    for ( int i= 0; i<amount; i++ ) {
        switch(i) {
        case 0: {
            if ( id == 0 ) {
                ClassFirst something1;
                std::this_thread::sleep_for (std::chrono::seconds(3));
                exit(0);
            } else {
                forksList.insert(std::pair<__pid_t, std::string>(id, "First") );
                if (i!= amount-1)
                    id = fork();
                break;
            }
        }
        case 1:
            if  (id == 0 ) {
                ClassSecond something2;
                std::this_thread::sleep_for (std::chrono::seconds(3));
                exit(0);
            } else {
                forksList.insert(std::pair<__pid_t, std::string>(id, "Second") );
                if (i!= amount-1)
                    id = fork();
                break;
            }
        case 2: {
            if (id == 0) {
                ClassThird something3;
                std::this_thread::sleep_for (std::chrono::seconds(3));
                exit(0);
            } else {
                forksList.insert(std::pair<__pid_t, std::string>(id, "Third") );
                break;
            }
            break;
        }
        }
    }

    std::cout << "Information from thread " << getpid() << ":\n";
    for (auto [key, value] : forksList) {
        std::cout << key << ":" << value <<  " // from " << getpid() << std::endl;
    }
    while ((id = wait(nullptr)) > 0);

}
