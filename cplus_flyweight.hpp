#ifndef FLYWEIGHT_H
#define FLYWEIGHT_H

#include <iostream>
#include <string>

using namespace std;

namespace flyweight
{
<<<<<<< HEAD
    //abstracton 享元
    class NetDevice
    {
    public:
        NetDevice(){};

        virtual string getName() = 0;
        void print(void)
        {
            printf("NetDevic\n");
        }
    };

    //concrete
    class Hub : public NetDevice
    {
    public:
        Hub(){};

        string getName()
        {
            return "This is Hub";
        }
    };

    class Switch : public NetDevice
    {
    public:
        Switch(){};

        string getName()
        {
            return "This is Switch";
        }
    };

    class NetDeviceFactory
    {
    public:
        static NetDeviceFactory *getFactory()
        {
            if (NULL == c_instance)
            {
                return new NetDeviceFactory();
            }
            else
            {
                return NULL;
            }
        }

        void addDevice(NetDevice* iDevice)
        {
            c_NetDevices.push_back(iDevice);
        }

    private:
        NetDeviceFactory()
        {
            Hub *hub = new Hub();
            Switch *switcher = new Switch();
            c_NetDevices.push_back(hub);
            c_NetDevices.push_back(switcher);
        }

        static NetDeviceFactory *c_instance;
        vector<NetDevice*> c_NetDevices;
    };

NetDeviceFactory* NetDeviceFactory::c_instance = NULL;

}
=======
// abstracton 享元
class NetDevice
{
public:
    NetDevice(){};

    virtual string getName() = 0;
    void           print(void)
    {
        printf("NetDevic\n");
    }
};

// concrete
class Hub : public NetDevice
{
public:
    Hub(){};

    string getName()
    {
        return "This is Hub";
    }
};

class Switch : public NetDevice
{
public:
    Switch(){};

    string getName()
    {
        return "This is Switch";
    }
};

class NetDeviceFactory
{
public:
    static NetDeviceFactory *getFactory()
    {
        if (NULL == c_instance) {
            return new NetDeviceFactory();
        } else {
            return NULL;
        }
    }

    void addDevice(NetDevice *iDevice)
    {
        c_NetDevices.push_back(iDevice);
    }

private:
    NetDeviceFactory()
    {
        Hub *   hub      = new Hub();
        Switch *switcher = new Switch();
        c_NetDevices.push_back(hub);
        c_NetDevices.push_back(switcher);
    }

    static NetDeviceFactory *c_instance;
    vector<NetDevice *>      c_NetDevices;
};

NetDeviceFactory *NetDeviceFactory::c_instance = NULL;

} // namespace flyweight
>>>>>>> 03c272c5bbf93713491e5bc2d13135e39fe65c47

#endif
