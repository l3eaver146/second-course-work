#pragma once
#include "Users.h"

inline void menu_autorization() {
	cout << "\t \t \t ������������, ������������!" << endl;
	cout << "��������, ������ ������������� :" << endl;
	cout << "1 - ����������� " << endl;
	cout << "2 - ����������� " << endl;
	cout << "0 - ����� " << endl;
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
			obj.authorization(flag);
		case 2: {
			obj.registration(flag);
			break;
		}
		case 0: {
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