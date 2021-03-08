/****/
#ifndef _BRIDGE_TEST_H
#define _BRIDGE_TEST_H
#include <iostream>
#include <string>

using namespace std;
namespace cplus_bridge
{
	class Game
	{
	public:
		Game() {}
		virtual void play(void) = 0;
	};

    class GameA : public Game
    {
    public:
        GameA() {}
		void play(void)
        {
            printf("playing Game A\n");
        }
    };

    class GameB : public Game
    {
    public:
        GameB() {}
        void play(void)
        {
            printf("playing Game B\n");
        }
    };

    class phone
    {
    public:
        phone() {}
        virtual void setupGame(Game *game) = 0;

    private:
        Game *game;
    };

    class phoneA : public phone
    {
    public:
        phoneA() {}
        void setupGame(Game *igame)
        {
            this->game = igame;
        }
        void print(void)
        {
            this->game->play();
        }
	private:
		Game *game;
    };
}

#endif