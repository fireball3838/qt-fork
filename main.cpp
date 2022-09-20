#include <QCoreApplication>
#include <iostream>
#include <unistd.h>
#include <QSettings>
#include <list>
#include <chrono>
#include <thread>
#include <QDebug>

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

    __pid_t id = fork();
    for ( int i= 0; i<amount; i++ ) {
        switch(i) {
        case 0: {
            if ( id == 0 ) {
                ClassFirst something1;
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
                exit(0);
            } else {
                forksList.insert(std::pair<__pid_t, std::string>(id, "Third") );
                break;
            }
            break;
        }
        }
    }


    for (auto [key, value] : forksList) {
        std::cout << key << ":" << value <<  " // from " << getpid() << std::endl;
    }


}
