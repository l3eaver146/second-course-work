#pragma once
#include "Users.h"

inline void menu_autorization() {
	cout << "\t \t \t Здравствуйте, пользователь!" << endl;
	cout << "Выберите, способ идентификации :" << endl;
	cout << "1 - Авторизация " << endl;
	cout << "2 - Регистрация " << endl;
	cout << "0 - Выход " << endl;
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
			cout << "Нет такого варианта! \nПовторите попытку ввода : ";
			break;
		}
		}
		}
	}
}