/****/
#ifndef _CLONE_TEST_H_
#define _CLONE_TEST_H_
#include <iostream>
#include <string>

using namespace std;

namespace clone
{
/*This is our work to be cloned*/
class WorkModel
{
public:
    char *modelName;
    void  setWorkModelName(char *iName)
    {
        this->modelName = iName;
    }
};

/*prototype work */
class PrototypeWork
{
public:
    PrototypeWork()
    {
    }
    virtual PrototypeWork *clone() = 0;
};

/*concrete work*/
class concreteWork : public PrototypeWork
{
public:
    concreteWork(){};
    ~concreteWork()
    {
    }

    concreteWork(char *iName, int iId, char *modelName)
    {
        printf("concreteWork construct 2\n");
        this->name      = iName;
        this->id        = iId;
        this->workmodel = new WorkModel();
        this->workmodel->setWorkModelName(modelName);
    }

    concreteWork *clone()
    {
        concreteWork *work = new concreteWork();
        work->setName(this->name);
        work->setId(this->id);
        work->workmodel = this->workmodel;
        return work;
    }

    void setName(char *iName)
    {
        this->name = iName;
    }
    void setId(int iId)
    {
        this->id = iId;
    }
    void setModel(WorkModel *iWorkModel)
    {
        this->workmodel = iWorkModel;
    }

private:
    char *     name;
    int        id;
    WorkModel *workmodel;
};

} // namespace clone

#endif