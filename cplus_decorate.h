/****/
#ifndef _DECORATE_TEST_H
#define _DECORATE_TEST_H
#include <iostream>
#include <string>

using namespace std;

namespace space_decorate
{
    class component
    {
    public:
        component() {}
        virtual void operation(void) = 0;
    };

    class phone : public component
    {
    public:
        phone() {}

        void operation(void)
        {
            printf("This is phone\n");
        }
    };

    class decorate : public component
    {
    public:
        decorate() {}
        decorate(component *c) : c_component(c) {}

        void operation(void)
        {
            this->c_component->operation();
        }

        component *get_component(void)
        {
            return this->c_component;
        }

        void set_component(component *c)
        {
            this->c_component = c;
        }

    private:
        component *c_component;
    };

    class decorator_shell : public decorate
    {
        decorator_shell(){}
        decorator_shell(component *c)
        {
            this->set_component(c);
        }

        void operation(void)
        {
            this->operation();
        }

        void new_behavior(void)
        {
            printf("This is new\n");
        }
    };

}

#endif