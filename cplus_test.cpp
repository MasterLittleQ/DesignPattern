#include "cplus_test.h"
#include <memory>
//#define SIMPLE_FACTORY
//#define ABSTRACT_FACTORY
//#define BUILDER
 

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
		football_factory* My_Manufactor1 = new football_factory();
		unique_ptr<abstractBall> ball(My_Manufactor1->ball_create());
		unique_ptr<abstractShirt> shirt(My_Manufactor1->shirt_create());

		ball->print();
		shirt->print();

		delete(My_Manufactor1);
	}
#endif // ABSTRACT_FACTORY

#ifdef BUILDER
	while (1)
	{
		using namespace builderpattern;
		unique_ptr<Director> My_Director(new Director(new ConcreteBuilderA()));
		unique_ptr<House> MyHouse (My_Director->construct());
	}

#endif

}




