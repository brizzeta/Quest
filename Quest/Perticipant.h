#pragma once
#include <iostream>
using namespace std;

class Participant
{
protected:
	string name;        //��������
	short value;        //������� ��������
	short max_jump;     //������������ ������ ������
	short max_run;      //������������ ���������� �������
	short barrier;      //����������� ������� �� �������� (���� 1 - ������� �������, 2 - �����)
public:
	Participant() = default;
	Participant(string n, short j, short r)     //������������� ��� ��������� (�������, ���, �����)
	{
		name = n;
		max_jump = j;
		max_run = r;
		value = 0;
	}	

	virtual string Get_name()        { return nullptr; }; //�������� ��� ���������
	virtual short Get_value()        { return 0; };       //�������� ������������ ������ ������
	virtual short Get_max_jump()     { return 0; };       //�������� ������������ ������ ������
	virtual short Get_max_run()      { return 0; };       //�������� ������������ ���������� �������
	virtual short Get_barrier()      { return 0; };       //�������� ����� ������������� �����������
	virtual void Set_barrier(short b)           = 0;      //������������� ����� ������������� �����������
	virtual void Set_value()                    = 0;      //������������� ������� ������ ������
	virtual void Jump()                         = 0;      //������
	virtual void Run()                          = 0;      //�������
};

class Human : public Participant // ������������
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

class Cat : public Participant // ������������
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

class Robot : public Participant // ������������
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