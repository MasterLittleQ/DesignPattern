/****/
#ifndef _FACADE_TEST_H
#define _FACADE_TEST_H
#include <iostream>
#include <string>

using namespace std;

namespace space_facade
{
    class Memory
    {
    public:
        Memory()
        {
        }
        void print(void)
        {
            printf("This is memory\n");
        }

    private:
        int age;
    };

    class CPU
    {
    public:
        CPU()
        {
        }
        void print(void)
        {
            printf("This is CPU\n");
        }

    private:
        int age;
    };

    class Facade
    {
    public:
        Facade(Memory *iMemory, CPU *iCpu)
        {
            this->c_memory = iMemory;
            this->c_cpu = iCpu;
        }
        ~Facade()
        {
            delete (c_memory);
            delete (c_cpu);
        }

        void power_on(void)
        {
            this->c_cpu->print();
            this->c_memory->print();
        }

    private:
        Memory *c_memory;
        CPU *c_cpu;
    };

}

#endif