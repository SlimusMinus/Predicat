#pragma once
#include <iomanip>
#include <iostream>
#include <Windows.h>
#include <conio.h>
#include <vector>
#include <algorithm>
using namespace std;


class Student
{
	int size = 5;
	int* ball = new int[size];
	static int Count;
	int id;
	double aver_ball;
	string name;
	string surname;
	string group;
public:
	friend ostream& operator << (ostream& os, Student& st);
	double aver();
	double Get() { return aver_ball; }
	Student() {};
	Student(string name, string surname, string group);
	bool operator() (const Student& st1, const Student& st2);
	friend bool predicat(Student a);
};

bool predicat(Student a);

void frame();
void gotoxy(short x, short y);
void show_menu();