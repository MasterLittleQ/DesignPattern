/****/
#ifndef _WFD_TEST_H_
#define _WFD_TEST_H_
#include <iostream>
#include <string>

using namespace std;

/* factory */
namespace factory_method
{
    class abstractionSport
    {
    public:
        abstractionSport(){};
        ~abstractionSport(){};
        virtual void print() = 0;
    };

    class basketball : public abstractionSport
    {
    public:
        basketball()
        {
        }
        void print()
        {
            printf("basketball\n");
        }
    };

    class abstractionFactory
    {
    public:
        virtual abstractionSport *getProduct() = 0;
    };

    class basketballFactory : public abstractionFactory
    {
    public:
        basketballFactory()
        {
            printf("basketball factory\n");
        }

        abstractionSport *getProduct()
        {
            return new basketball();
        }
    };
}

namespace abstract_factory_mode
{
    /*abstractions*/
    class abstractBall
    {
    public:
        abstractBall(){};
        virtual void print() = 0;
    };

    class abstractShirt
    {
    public:
        abstractShirt(){};
        virtual void print() = 0;
    };

    class abstractFactory
    {
    public:
        abstractFactory(){};
        virtual void print() = 0;
        virtual abstractBall *ball_create() = 0;
        virtual abstractShirt *shirt_create() = 0;
    };

    /*children of balls*/
    class football : public abstractBall
    {
    public:
        football()
        {
        }
        void print()
        {
            printf("This is football\n");
        }
    };

    class baseball : public abstractBall
    {
    public:
        baseball()
        {
        }

        void print()
        {
            printf("This is baseball\n");
        }
    };

    /*children of shirts*/
    class football_shirt : public abstractShirt
    {
    public:
        football_shirt()
        {
        }

        void print()
        {
            printf("This is football_shirt\n");
        }
    };

    /*children of factory*/
    class football_factory : public abstractFactory
    {
    public:
        football_factory()
        {
            print();
        }

        void print()
        {
            printf("This is football factory\n");
        }

        abstractBall *ball_create()
        {
            return new football();
        }

        abstractShirt *shirt_create()
        {
            return new football_shirt();
        }
    };
}

namespace builderpattern
{
    /*abstractions*/
    class House
    {
    public:
        House()
        {
        }

        void setFloor(string iFloor)
        {
            this->floor = iFloor;
        }

        void setWall(string iWall)
        {
            this->wall = iWall;
        }

    private:
        string floor;
        string wall;
    };

    class AbstractBuilder : public House
    {
    public:
        AbstractBuilder()
        {
            house = new House();
        }
		~AbstractBuilder()
		{
			//delete house; 
			/* shouldn't delete here, because I have already deleted it in Director*/
		}

        virtual void buildFloor() = 0;
        virtual void buildWall() = 0;
        virtual House *getHouse() = 0;

        House *house;
    };

    /*concrete of builder*/
    class ConcreteBuilderA : public AbstractBuilder
    {
    public:
        ConcreteBuilderA()
        {
            printf("This is ConcreteBuilderA\n");
        }

        void buildFloor()
        {
            this->house->setFloor("FloorA");
        }

        void buildWall()
        {
            this->house->setWall("WallA");
        }

        House *getHouse()
        {
            return this->house;
        }
    };

     /*concrete of builder2*/
    class ConcreteBuilderB : public AbstractBuilder
    {
    public:
        ConcreteBuilderB()
        {
            printf("This is ConcreteBuilderB\n");
        }

        void buildFloor()
        {
            this->house->setFloor("FloorB");
        }

        void buildWall()
        {
            this->house->setWall("WallB");
        }

        House *getHouse()
        {
            return this->house;
        }
    };

    /*Director*/
    class Director
    {
    public:
        Director(AbstractBuilder *iBuilder)
        {
            this->builder = iBuilder;
        }
		~Director()
		{
			delete builder;
		}

        House *construct()
        {
            builder->buildFloor();
            builder->buildWall();

            return builder->getHouse();
        }

    private:
        AbstractBuilder *builder;
    };

}




#endif
