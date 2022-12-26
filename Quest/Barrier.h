#pragma once

class Barrier
{
protected:
	string name;             //название преграды
	short value;             //значение
public:
	Barrier() = default;
	Barrier(string n, short v)
	{
		name = n;
		value = v;
	}
	virtual string Get_name() { return nullptr; }; //получить имя участника
	virtual short Get_value() { return 0; };       //получить значение
};

class RunningTrack : public Barrier
{
public:
	RunningTrack() = default;
	RunningTrack(string n, short v) : Barrier(n, v) {};
	string Get_name() { return name; };
	short Get_value() { return value; };
};

class Wall : public Barrier
{
public:
	Wall() = default;
	Wall(string n, short v) : Barrier(n, v) {};
	string Get_name() { return name; };
	short Get_value() { return value; };
};