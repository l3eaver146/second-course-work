#pragma once
#include "Users.h"

inline void menu_autorization() {
	system("color 11");
	system("cls");
	cout << "\t \t \t Здравствуйте, пользователь!" << endl;
	cout << "\t \t \tВыберите, способ идентификации :" << endl;
	cout << "\t \t \t---------------------" << endl;
	cout << "\t \t \t| 1 | Авторизация   |" << endl;
	cout << "\t \t \t---------------------" << endl;
	cout << "\t \t \t| 2 | Регистрация   |" << endl;
	cout << "\t \t \t---------------------" << endl;
	cout << "\t \t \t| 0 |    Выход      |" << endl;
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
			cout << "Нет такого варианта! \nПовторите попытку ввода : ";
			break;
		}
		}
		}
	}
}