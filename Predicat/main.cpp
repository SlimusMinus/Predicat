#include "Student.h"

int main()
{
	srand(time(NULL));
	Student a;
	system("color F0");
	const int num_menu = 3;
	int ch = 0, active_menu = 0;
	bool q;
	vector<Student>stud
	{
		Student("Kris", "Evans", "BV-221"),
		Student("Marlon", "Brando", "BV-221"),
		Student("Robert", "De_Niro", "MI-331"),
		Student("Tom", "Hanks", "VR-15"),
		Student("Cary", "Grant", "ER-157"),
		Student("Clint", "Hoffman", "PO-777"),
		Student("Kris", "Estwood", "PO-777"),
		Student("Johnny", "Dep", "NR-458"),
		Student("Morgan", "Freeman", "NR-458"),
		Student("Anthony", "Hopkins", "MU-221"),
		Student("John", "Wayne", "MT-237"),
	};
	vector<Student>::iterator it;
	frame();
	for (int i = 0; i < stud.size(); i++)
	{
		cout << stud[i];
		cout << "---------------------------------------------------------------" << endl;
	}
	system("pause");

	do
	{
		bool exit = false;
		while (!exit)
		{

			show_menu();
			gotoxy(0, active_menu);
			ch = _getch();
			if (ch == 224) ch = _getch();
			switch (ch)
			{

			case 27: exit = true; break;
			case 72: active_menu--; break;
			case 80: active_menu++; break;
			case 13:

				if (active_menu == 0)
				{
					system("cls");
					frame();
					sort(stud.begin(), stud.end(), stud.front());
					for (int i = 0; i < stud.size(); i++)
						cout << stud[i];
					cout << "---------------------------------------------------------------" << endl;
					system("pause");
				}
				else if (active_menu == 1)
				{
					system("cls");
					frame();
					reverse(stud.begin(), stud.end());
					for (int i = 0; i < stud.size(); i++)
						cout << stud[i];
					cout << "---------------------------------------------------------------" << endl;
					system("pause");
				}
				else if (active_menu == 2)
				{
					system("cls");
					frame();
					for (int i = 0; i < stud.size(); i++)
					{
						cout << stud[i];
						cout << "---------------------------------------------------------------" << endl;
					}
					cout << "\t\n After the exam, they entered the university \n\n" << endl;
					frame();
					it = remove_if(stud.begin(), stud.end(), predicat);
					for (auto iter = stud.begin(); iter != it; iter++)
						cout << *iter << "  ";
					cout << "---------------------------------------------------------------" << endl;
					system("pause");
				}
				break;
			}
			if (active_menu < 0) active_menu = num_menu - 1;
			if (active_menu > num_menu - 1) active_menu = 0;

		}
		system("cls");
		cout << "If you wanna continue press 1, no 0" << endl;
		cin >> q;
		system("cls");
	} while (q == 1);
	system("cls");

	return 0;




}