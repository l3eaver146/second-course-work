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
	void show_data_users();
	friend std::istream& operator>> (std::ifstream& in, Users& Users);
	friend std::ostream& operator<< (std::ostream& out, const Users& Users);
};

