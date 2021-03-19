/****/
#ifndef _NORMAL_TEST_H_
#define _NORMAL_TEST_H_
#include <iostream>
#include <string>
#include <functional>

using namespace std;

class easy_test
{
public:
	easy_test() {};
	~easy_test() {};
	int array[10];
};

class go
{
public:
	go() {}
	~go()
	{
		cout << "go die.\n";
	}
};
auto d = [](go * gp)
{
	delete gp;
	cout << "deletor done.\n";
};
class go_de
{
public:
	void operator() (go* g)
	{
		d(g);
	}
};

using SafeWFDHandle = unique_ptr<easy_test, std::function<void(easy_test*)>>;
SafeWFDHandle weirdFunc()
{
	int dev = 0;
	int temp[10] = { 1 };

	return SafeWFDHandle(new easy_test{}, [](easy_test* temp)
	{
		cout << "Oh\n" << endl;
	});
}

template <class T>
class easy_template_class
{
public:
	easy_template_class() {};
	T array[10];
};

#endif
