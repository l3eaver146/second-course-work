#pragma once
#include "Users.h"

inline void menu_autorization() {
	system("color 11");
	system("cls");
	cout << "\t \t \t ������������, ������������!" << endl;
	cout << "\t \t \t��������, ������ ������������� :" << endl;
	cout << "\t \t \t---------------------" << endl;
	cout << "\t \t \t| 1 | �����������   |" << endl;
	cout << "\t \t \t---------------------" << endl;
	cout << "\t \t \t| 2 | �����������   |" << endl;
	cout << "\t \t \t---------------------" << endl;
	cout << "\t \t \t| 0 |    �����      |" << endl;
	cout << "\t \t \t---------------------" << endl;
}
inline void edintification() {
	
	Users obj;
	bool flag = true, result = false;
	int choise = 0;
	while (flag == true) {
		menu_autorization();
		cin >> choise;
		switch (choise) {
		case 1: {
			system("cls");
			obj.authorization(flag);
			break;
		case 2: {
			system("cls");
			obj.registration(flag);
			break;
		}
		case 0: {
			system("cls");
			flag = false;
			break;
		}
		default: {
			cout << "��� ������ ��������! \n��������� ������� ����� : ";
			break;
		}
		}
		}
	}
}