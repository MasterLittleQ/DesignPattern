#ifndef SINGLETON
#define SINGLETON

#include <iostream>
#include <string>

using namespace std;

namespace singleton
{
    class Singleton
    {
    public:
        static Singleton *getInstance()
        {
            if (instance == NULL)
            {
                printf("get Singleton\n");
                instance = new Singleton();
            }
            return instance;
        }

    private:
        Singleton()
        {
            printf("init Singleton\n");
        }

        static Singleton *instance;
    };

    Singleton *Singleton::instance = NULL;

}

#endif