#ifndef _COMPONENT_TEST_H
#define _COMPONENT_TEST_H
#include <iostream>
#include <string>
#include <vector>

using namespace std;
namespace space_component
{
class component
{
public:
    component()
    {
    }
    component(string iName)
    {
        this->name = iName;
    }
    virtual void print(void) = 0;

private:
    string name;
};

class office : public component
{
public:
    office(string iName)
    {
        this->name = iName;
    }
    void print(void)
    {
        "This is office\n";
    }

private:
    string name;
};

class hall : public component
{
public:
    hall(string iName)
    {
        this->name = iName;
    }

    void print(void)
    {
        "This is hall\n";
    }

private:
    string name;
};

class SubComopnet : public component
{
public:
    SubComopnet(string iName)
    {
        this->name = iName;
    }

    void add(component *c)
    {
        componentVector.push_back(c);
    }

    void print(void)
    {
        "This is SubComponent\n";
    }

private:
    string              name;
    vector<component *> componentVector;
};
} // namespace space_component
#endif
