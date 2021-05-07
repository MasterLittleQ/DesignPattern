/****/
#ifndef _NORMAL_TEST_H_
#define _NORMAL_TEST_H_
<<<<<<< HEAD
#include <iostream>
#include <string>
#include <functional>
=======
#include <functional>
#include <iostream>
#include <string>
>>>>>>> 03c272c5bbf93713491e5bc2d13135e39fe65c47

using namespace std;

class easy_test
{
public:
<<<<<<< HEAD
	easy_test() {};
	~easy_test() {};
	int array[10];
=======
    easy_test(){};
    ~easy_test(){};

    easy_test operator+(easy_test &input)
    {
        easy_test ret;
        for (int i = 0; i < (sizeof(this->array)) / sizeof(int); i++) {
            ret.array[i] = this->array[i] + input.array[i];
        }
        return ret;
    }

    int array[10];
>>>>>>> 03c272c5bbf93713491e5bc2d13135e39fe65c47
};

class go
{
public:
<<<<<<< HEAD
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
=======
    go()
    {
    }
    ~go()
    {
        cout << "go die.\n";
    }
};
auto d = [](go *gp) {
    delete gp;
    cout << "deletor done.\n";
>>>>>>> 03c272c5bbf93713491e5bc2d13135e39fe65c47
};
class go_de
{
public:
<<<<<<< HEAD
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

=======
    void operator()(go *g)
    {
        d(g);
    }
};

using SafeWFDHandle = unique_ptr<easy_test, std::function<void(easy_test *)>>;
SafeWFDHandle weirdFunc()
{
    int dev      = 0;
    int temp[10] = {1};

    return SafeWFDHandle(new easy_test{}, [](easy_test *temp) {
        cout << "Oh\n" << endl;
    });
}

template <class T> class easy_template_class
{
public:
    easy_template_class(){};
    T array[10];
};

class A
{
public:
    void addfun(void);

private:
    int text;
};

void A::addfun(void)
{
    text = 5;
}

typedef struct TEST_STRUCT
{
    int    num;
    string name;
} TEST_STRUCT_T;

>>>>>>> 03c272c5bbf93713491e5bc2d13135e39fe65c47
#endif
