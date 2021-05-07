
#include <Windows.h>
#include <array>
#include <fstream>
#include <iostream>
#include <iterator>
#include <list>
#include <map>
#include <memory>
#include <process.h>
#include <vector>

#include "cplus_bridge.h"
#include "cplus_clone.h"
#include "cplus_component.h"
#include "cplus_decorate.h"
#include "cplus_facade.h"
#include "cplus_flyweight.hpp"
<<<<<<< HEAD

#include "normal_test.hpp"
=======
#include "cplus_singleton.h"
#include "cplus_test.h"
>>>>>>> 03c272c5bbf93713491e5bc2d13135e39fe65c47

#include "normal_test.hpp"

/*Design Test*/
//#define SIMPLE_FACTORY
//#define ABSTRACT_FACTORY
//#define BUILDER
//#define PROTO_CLONE
//#define SINGLETON_TEST
//#define BRIDGE_TEST
//#define COMPONENT_TEST
//#define FACADE_TEST
//#define DECORATE_TEST
//#define FLYWEIGHT_TEST

/*Normal Test*/
//#define THREAD_TEST
<<<<<<< HEAD
#define UNIQUE_PTR_LAMDBA
=======
//#define MAP_PAIR_TEST
//#define UNIQUE_PTR_LAMDBA_TEST
//#define OPERATOR_TEST
#define VECTOR_ITERATOR_TEST
#define FSTREAM_TEST

>>>>>>> 03c272c5bbf93713491e5bc2d13135e39fe65c47
#define THREAD_NUM 5

using namespace std;

unsigned int __stdcall CallSingleton(void *pPM)
{
    int nThreadNum = *(int *)pPM;
    Sleep(50);
    printf("thread = %d\n", nThreadNum);
    return 0;
}

void ThreadTest(void)
{
    HANDLE handle[THREAD_NUM];

    int threadNum = 0;
    while (threadNum < THREAD_NUM) {
        handle[threadNum] =
            (HANDLE)_beginthreadex(NULL, 0, CallSingleton, &threadNum, 0, NULL);
        threadNum++;
    }
    WaitForMultipleObjects(THREAD_NUM, handle, TRUE, INFINITE);

    system("pause");
}

void cplus_normal_testFunc()
{
#ifdef THREAD_TEST
    ThreadTest();
#endif

#ifdef UNIQUE_PTR_LAMDBA_TEST
    SafeWFDHandle                                           temp = weirdFunc();
    unique_ptr<easy_test, std::function<void(easy_test *)>> myTest(
        new easy_test{}, [](easy_test *p) { cout << p->array[0] << endl; });
    myTest->array[0] = 0xA;
    unique_ptr<go, function<void(go *)>> a{new go{}, d};
#endif

#ifdef OPERATOR_TEST
    easy_test test1, test2;
    test1.array[0] = 1;
    test2.array[0] = 2;
    test1          = test1 + test2;
#endif

#ifdef VECTOR_ITERATOR_TEST
    vector<TEST_STRUCT> myVector{{0, "Start"}};

    TEST_STRUCT temp;
    temp.num  = 1;
    temp.name = "HI";
    myVector.push_back(temp);
    temp.num  = 2;
    temp.name = "BYE";
    myVector.push_back(temp);

    for (std::vector<TEST_STRUCT>::iterator iter = myVector.begin();
         iter != myVector.end(); iter++) {
        printf("%d\n", iter->num);
    }
#endif // VECTOR_ITERATOR

#ifdef FSTREAM_TEST
    std::ifstream           s1("C:\dumbfile.txt");
    const std::vector<char> buffer((istream_iterator<char>(s1)), {});

    cout << buffer.size();
    cout << buffer[0];
    cout << buffer[5];
#endif
}

void cplus_design_testFunc()
{
#ifdef SIMPLE_FACTORY
    using namespace factory_method;
    while (1) {
        // abstractionFactory *My_Manufactor = new basketballFactory;
        // abstractionSport *product = My_Manufactor->getProduct();

        unique_ptr<abstractionFactory> My_Manufactor(new basketballFactory);
        unique_ptr<abstractionSport>   product(My_Manufactor->getProduct());

        product->print();
    }
#endif // SIMPLE_FACTORY

#ifdef ABSTRACT_FACTORY
    while (1) {
        using namespace abstract_factory_mode;

        // unique_ptr<football_factory> My_Manufactor1(new football_factory);
        football_factory *        My_Manufactor1 = new football_factory();
        unique_ptr<abstractBall>  ball(My_Manufactor1->ball_create());
        unique_ptr<abstractShirt> shirt(My_Manufactor1->shirt_create());

        ball->print();
        shirt->print();

        delete (My_Manufactor1);
    }
#endif // ABSTRACT_FACTORY

#ifdef BUILDER
    while (1) {
        using namespace builderpattern;
        unique_ptr<Director> My_Director(new Director(new ConcreteBuilderA()));
        unique_ptr<House>    MyHouse(My_Director->construct());
    }

#endif

#ifdef PROTO_CLONE
    using namespace clone;
    char name[]  = "Single";
    char name2[] = "Second";
    char model[] = "Single_Model";
    char mode2[] = "Second_Model";

    unique_ptr<concreteWork> A_work(new concreteWork(name, 1001, model));
    unique_ptr<concreteWork> B_work(A_work->clone());
    B_work->setId(2);
    B_work->setName(name2);
    WorkModel B_work_Model;
    B_work_Model.setWorkModelName(mode2);
    B_work->setModel(&B_work_Model);
#endif

#ifdef SINGLETON_TEST
    using namespace singleton;
    unique_ptr<Singleton> s1(Singleton::getInstance());
    unique_ptr<Singleton> s2(Singleton::getInstance());
#endif

#ifdef BRIDGE_TEST
    using namespace cplus_bridge;
    // unique_ptr<Game> game1(new GameA);
    Game *             game1 = new GameA();
    unique_ptr<phoneA> phone1(new phoneA);

    phone1->setupGame(game1);
    phone1->print();
    free(game1);
#endif

#ifdef COMPONENT_TEST
    using namespace space_component;
    unique_ptr<SubComopnet> Company(new SubComopnet("MyCompany"));
    office *                office1 = new office("Room1");
    hall *                  hall1   = new hall("Hall1");

    Company->add(office1);
    Company->add(hall1);
#endif

#ifdef MAP_PAIR_TEST
    typedef std::pair<int, string> MyPairType;
    typedef std::map<int, string>  MyMapType;

    MyMapType MyMap;
    MyMap.insert(pair<int, string>(001, "number1"));
    MyMap.insert(pair<int, string>(002, "number2"));
    MyMap.insert(MyPairType(003, "third"));

    const MyMapType::iterator iter = MyMap.find(003);
    if (iter != MyMap.end()) {
        cout << iter->second << endl;
    }
#endif

#ifdef DECORATE_TEST
    using namespace space_decorate;
    {
        component *          MyPhone = new phone();
        unique_ptr<decorate> MyDecorate(new decorate(MyPhone));
        MyDecorate->operation();
    }
#endif

#ifdef FACADE_TEST
    using namespace space_facade;
    {
        Memory *           myMem = new Memory;
        CPU *              myCpu = new CPU;
        unique_ptr<Facade> myFacade(new Facade(myMem, myCpu));
        myFacade->power_on();

    } // namespace space_facade
#endif
#ifdef FLYWEIGHT_TEST
    using namespace flyweight;

    Hub *             MyHub     = new Hub();
    NetDeviceFactory *myFactory = NetDeviceFactory::getFactory();
    myFactory->addDevice(MyHub);
#endif
<<<<<<< HEAD
#ifdef FLYWEIGHT_TEST
	using namespace flyweight;

	Hub *MyHub = new Hub();
	NetDeviceFactory *myFactory = NetDeviceFactory::getFactory();
	myFactory->addDevice(MyHub);
#endif

#ifdef UNIQUE_PTR_LAMDBA
	SafeWFDHandle temp = weirdFunc();
	unique_ptr<easy_test, std::function<void(easy_test*)>> myTest(new easy_test{}, [](easy_test *p) {cout << p->array[0] << endl;});
	myTest->array[0] = 0xA;
	unique_ptr < go, function<void(go*) > > a{ new go{}, d };
#endif
=======
}

int main(int argc, char **argv)
{
    cplus_design_testFunc();

    cplus_normal_testFunc();
>>>>>>> 03c272c5bbf93713491e5bc2d13135e39fe65c47

    return 0;
}
