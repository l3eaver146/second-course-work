#pragma once
#include "Header.h"

class Users
{
protected:
	string login;
	string password;
	string root;
public:
	Users() {}
	~Users(){}
	Users(string login, string password, string root);
	void set_login(string);
	void set_password(string);
	void set_root(string);
	string get_login();
	string get_password();
	string get_root();
	void enter_password();
	void show_data_users();
	void authorization(bool &flag);
	void registration(bool& flag);
	void make_bo();
	void userwork();
	void adminwork();
	void make_eo();
	void menu_user();
	friend std::ifstream& operator>> (std::ifstream& in, Users& Users);
	friend std::ostream& operator<< (std::ostream& out, const Users& Users);
	friend std::istream& operator>> (std::istream& in, Users& Users);
	friend std::ofstream& operator<< (std::ofstream& out, const Users& Users);
};

