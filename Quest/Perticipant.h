#pragma once
#include <iostream>
using namespace std;

class Participant
{
protected:
	string name;        //участник
	short value;        //текущее значение
	short max_jump;     //максимальная высота прыжка
	short max_run;      //максимальное расстояние пробега
	short barrier;      //препятствие которое не пройдено (если 1 - беговая дорожка, 2 - стена)
public:
	Participant() = default;
	Participant(string n, short j, short r)     //устанавливаем имя участника (человек, кот, робот)
	{
		name = n;
		max_jump = j;
		max_run = r;
		value = 0;
	}	

	virtual string Get_name()        { return nullptr; }; //получить имя участника
	virtual short Get_value()        { return 0; };       //получить максимальную высоту прыжка
	virtual short Get_max_jump()     { return 0; };       //получить максимальную высоту прыжка
	virtual short Get_max_run()      { return 0; };       //получить максимальное расстояние пробега
	virtual short Get_barrier()      { return 0; };       //получить номер непройденного препятствия
	virtual void Set_barrier(short b)           = 0;      //устанавливаем номер непройденного препятствия
	virtual void Set_value()                    = 0;      //устанавливаем текущую высоту прыжка
	virtual void Jump()                         = 0;      //бегать
	virtual void Run()                          = 0;      //прыгать
};

class Human : public Participant // наследование
{
public:
	Human();
	Human(string n, short j, short r) : Participant(n, j, r) {};

	string Get_name()    { return name; };
	short Get_value()    { return value; };
	short Get_max_jump() { return max_jump; };
	short Get_max_run()  { return max_run; };
	short Get_barrier()  { return barrier; };
	void Set_barrier(short b)
	{
		barrier = b;
	}
	void Set_value()
	{
		value += 1;
	}
	void Jump()
	{
		cout << "Human jump.\n";
	}
	void Run()
	{
		cout << "Human run.\n";
	}
};

class Cat : public Participant // наследование
{
public:
	Cat() { value = 0; };
	Cat(string n, short j, short r) : Participant(n, j, r) {};

	string Get_name()    { return name; };
	short Get_value()    { return value; };
	short Get_max_jump() { return max_jump; };
	short Get_max_run()  { return max_run; };
	short Get_barrier()  { return barrier; };
	void Set_barrier(short b)
	{
		barrier = b;
	}
	void Set_value()
	{
		value += 1;
	}
	void Jump()
	{
		cout << "Cat jump.\n";
	}
	void Run()
	{
		cout << "Cat run.\n";
	}
};

class Robot : public Participant // наследование
{
public:
	Robot() { value = 0; };
	Robot(string n, short j, short r) : Participant(n, j, r) {};

	string Get_name()       { return name; };
	short Get_value()       { return value; };
	short Get_max_jump()    { return max_jump; };
	short Get_max_run()     { return max_run; };
	short Get_max_barrier() { return barrier; };
	void Set_barrier(short b)
	{
		barrier = b;
	}
	void Set_value()
	{
		value += 1;
	}
	void Jump()
	{
		cout << "Robot jump.\n";
	}
	void Run()
	{
		cout << "Robot run.\n";
	}
};