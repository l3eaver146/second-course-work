#pragma once
#include "Header.h"
#include "List.h"
#include "Users.h"
static void check(int& n) {
	while (true) {
		cin >> n;
		if (cin.get() == '\n') {
			break;//�������� �� ������������ �������� ������
		}
		else {
			cin.clear();
			cin.ignore(256, '\n');//������������ ����������� ����� 
			cout << "������������ ����, ��������� ������� \n Enter parametr again ";
		}//���� ������ �� ������������� ����, �� �������� �� ������
	}
}
static void menu_autorization() {
	cout << "\t \t \t ������������, ������������!" << endl;
	cout << "��������, ������ ������������� :" << endl;
	cout << "1 - ����������� " << endl;
	cout << "2 - ����������� " << endl;
	cout << "0 - ����� " << endl;
}
static string enter_password() {
	string s;
	int ch = 0;
	while (true) {
		ch = _getwch();
		if (ch == 13) {//������ �� enter
			break;
		}
		else if (ch == 8) {
			cout << (char)8 << ' ' << (char)8;
			s.erase(s.length() - 1);//��������� ����������� �������������� �� ����� �����
		}
		else {
			cout << "*";
			s += (char)ch;
		}
	}
	return s;
}
static void edintification() {
	List <Users> list_of_users;
	string File_of_users = "Users.txt", temp_login, temp_password;
	list_of_users.readFileusers(File_of_users);
	bool flag = true, result = false;
	int choise = 0;
	while (flag == true) {
		menu_autorization();
		check(choise);
		switch (choise) {
		case 1: {
			bool flag_exit_authorization = true;
			while (flag_exit_authorization == true) {
				cout << "������� ���� ����� � ������ :" << endl;
				cout << "����� : ";
				cin >> temp_login;
				cout << "������ :";
				temp_password = enter_password();
				result = list_of_users.check_user_data(temp_login, temp_password);
				if (result == true) {
					cout << endl << "�������� �����������!";
					flag_exit_authorization = false;
					flag = false;
					system("cls");
				}
				else {
					cout << endl << "��������� ������� �����������!\n��������� ���� ������ �������!\n";
				}
			}
			break;
		}
		case 2: {
			bool flag_exit_registration = true;
			cout << "����� ���������� � ������ ����������� �������������! " << endl;
			while (flag_exit_registration == true) {
				cout << endl << "������� �������� ����� : ";
				cin >> temp_login;
				bool res = list_of_users.check_on_copy(temp_login);
				if (res == true) {
					cout << "������� ��� ������ : ";
					temp_password = enter_password();
					Users temp_obj(temp_login, temp_password, "user");
					list_of_users.push(temp_obj);
					list_of_users.writeEndFileusers(File_of_users,temp_obj);
					cout << endl << "�� ������� ������������������.���� ����� - user !" << endl;
					flag = false;
					flag_exit_registration = false;
				}
				else {
					cout << "��� ����� �� �������! ��������� ������� ����� ! ";
				}
			}
			break;
		}
		case 0: {
			flag = false;
			break;
		}
		default: {
			cout << "��� ������ ��������! \n��������� ������� ����� : ";
		}
		}
	}
}