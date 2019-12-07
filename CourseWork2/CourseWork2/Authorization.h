#pragma once
#include "List.h"
#include "UserWork.cpp"

static void menu_autorization() {
	cout << "\t \t \t Здравствуйте, пользователь!" << endl;
	cout << "Выберите, способ идентификации :" << endl;
	cout << "1 - Авторизация " << endl;
	cout << "2 - Регистрация " << endl;
	cout << "0 - Выход " << endl;
}
static string enter_password() {
	string s;
	int ch = 0;
	while (true) {
		ch = _getwch();
		if (ch == 13) {//вводим до enter
			break;
		}
		else if (ch == 8) {
			cout << (char)8 << ' ' << (char)8;
			s.erase(s.length() - 1);//внедрение возможности редактирования во время ввода
		}
		else {
			cout << "*";
			s += (char)ch;
		}
	}
	return s;
}
static void authotize(string &login, string &password,List <Users> &list_of_users,bool &flag) {
	bool flag_exit_authorization = true;
	while (flag_exit_authorization == true) {
		cout << "Введите ваши логин и пароль :" << endl;
		cout << "Логин : ";
		cin >> login;
		cout << "Пароль :";
		password = enter_password();
		bool result = list_of_users.check_user_data(login, password);
		if (result == true) {
			cout << endl << "Успешная авторизация!";
			flag = false;
			flag_exit_authorization = false;
			system("cls");
		}
		else {
			cout << endl << "Повторите попытку авторизации!\nВведенные вами данные неверны!\n";
		}
	}
}
static void registration(string& login, string& password, List <Users>& list_of_users, bool& flag,string File_of_users) {
	bool flag_exit_registration = true;
	cout << "Добро пожаловать в раздел регистрации пользователей! " << endl;
	while (flag_exit_registration == true) {
		cout << endl << "Введите желаемый логин : ";
		cin >> login;
		bool res = list_of_users.check_on_copy(login);
		if (res == true) {
			cout << "Введите ваш пароль : ";
			password = enter_password();
			Users temp_obj(login, password, "user");
			list_of_users.push(temp_obj);
			list_of_users.writeEndFileusers(File_of_users, temp_obj);
			cout << endl << "Вы успешно зарегистрировались.Ваши права - user !" << endl;
			flag = false;
			flag_exit_registration = false;
		}
		else {
			cout << "Ваш логин не униклен! Повторите попытку ввода ! ";
		}
	}
}
static void edintification() {
	List <Users> list_of_users;
	string File_of_users = "Users.txt", temp_login, temp_password;
	list_of_users.readFileusers(File_of_users);
	bool flag = true, result = false;
	int choise = 0;
	while (flag == true) {
		menu_autorization();
		cin >> choise;
		switch (choise) {
		case 1: {
			authotize(temp_login,temp_password,list_of_users,flag);
			break;
		}
		case 2: {
			registration(temp_login, temp_password, list_of_users, flag, File_of_users);
			work_user();
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
