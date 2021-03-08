
#include <memory>
#include <Windows.h>
#include <process.h>
#include <vector>
#include <list>

#include "cplus_test.h"
#include "cplus_clone.h"
#include "cplus_singleton.h"
#include "cplus_bridge.h"
//#define SIMPLE_FACTORY
//#define ABSTRACT_FACTORY
//#define BUILDER
//#define PROTO_CLONE
//#define SINGLETON_TEST
//#define THREAD_TEST
//#define BRIDGE_TEST

#define THREAD_NUM 5

unsigned int __stdcall CallSingleton(void *pPM)
{
	int nThreadNum = *(int *)pPM;
	Sleep(50);
	printf("thread = %d\n", nThreadNum);
	return 0;
}

void ThreadTest(void)
{
	HANDLE  handle[THREAD_NUM];

	int threadNum = 0;
	while (threadNum < THREAD_NUM)
	{
		handle[threadNum] = (HANDLE)_beginthreadex(NULL, 0, CallSingleton, &threadNum, 0, NULL);
		threadNum++;
	}
	WaitForMultipleObjects(THREAD_NUM, handle, TRUE, INFINITE);

	system("pause");
}

int main(int argc, char **argv)
{
#ifdef SIMPLE_FACTORY
	using namespace factory_method;
	while (1)
	{
		//abstractionFactory *My_Manufactor = new basketballFactory;
		//abstractionSport *product = My_Manufactor->getProduct();

		unique_ptr<abstractionFactory> My_Manufactor(new basketballFactory);
		unique_ptr<abstractionSport> product(My_Manufactor->getProduct());

		product->print();
	}
#endif // SIMPLE_FACTORY

#ifdef ABSTRACT_FACTORY
	while (1)
	{
		using namespace abstract_factory_mode;

		//unique_ptr<football_factory> My_Manufactor1(new football_factory);
		football_factory *My_Manufactor1 = new football_factory();
		unique_ptr<abstractBall> ball(My_Manufactor1->ball_create());
		unique_ptr<abstractShirt> shirt(My_Manufactor1->shirt_create());

		ball->print();
		shirt->print();

		delete (My_Manufactor1);
	}
#endif // ABSTRACT_FACTORY

#ifdef BUILDER
	while (1)
	{
		using namespace builderpattern;
		unique_ptr<Director> My_Director(new Director(new ConcreteBuilderA()));
		unique_ptr<House> MyHouse(My_Director->construct());
	}

#endif

#ifdef PROTO_CLONE
	using namespace clone;
	char name[] = "Single";
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
	unique_ptr<Singleton>s1(Singleton::getInstance());
	unique_ptr<Singleton>s2(Singleton::getInstance());
#endif


#ifdef THREAD_TEST
	ThreadTest();
#endif

#ifdef BRIDGE_TEST
		using namespace cplus_bridge;
		//unique_ptr<Game> game1(new GameA);
		Game *game1 = new GameA();
		unique_ptr<phoneA> phone1(new phoneA);

		phone1->setupGame(game1);
		phone1->print();
		free(game1);
#endif

	return 0;
}
