#include "Student.h"

double Student::aver()
{
	aver_ball = 0;
	for (int i = 0; i < 5; i++)
	{
		ball[i] = rand() % 12 + 1;
		aver_ball += (double)ball[i];
	}
	aver_ball /= 5;
	return aver_ball;
}

Student::Student(string name, string surname, string group)
{
	this->name = name;
	this->surname = surname;
	this->group = group;
	Count++;
	id = Count;
	aver();
}

bool Student::operator()(const Student& st1, const Student& st2)
{
	return st1.aver_ball > st2.aver_ball;
}

int Student::Count = 0;

ostream& operator<<(ostream& os, Student& st)
{
	os << "|| " << st.id << "\t" << st.name << "\t" << st.surname << "\t  " << st.aver_ball << "\t    " << st.group << "\t" << st.Count << "\t     ||" << endl;
	return os;
}

bool predicat(Student a)
{
	if (a.aver_ball < 7)
	{
		a.Count--;
		return true;
	}
	else
		return false;
}

void frame()
{
	cout << "===============================================================" << endl;
	cout << "|| id || name ||surname|| aver_bal|| group || people in group||" << endl;
	cout << "===============================================================" << endl;

}

void gotoxy(short x, short y)
{
	COORD coord = { x, y };
	HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleCursorPosition(h, coord);
}

void show_menu()
{
	system("cls");
	cout << "Sorting average balls" << endl;
	cout << "Reverse" << endl;
	cout << "Remove_if" << endl;
	cout << "=====================" << endl;
	cout << "Press ESC to exit" << endl;

}
