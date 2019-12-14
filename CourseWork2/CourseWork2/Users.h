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
	void show();
	Users(string login, string password, string root);
	void set_login(string);
	void set_password(string);
	void set_root(string);
	string get_login();
	string get_password();
	string get_root();
	void enter_password();
	void dell_EO(string login);
	void dell_BO(string login);
	void show_data_users();
	void authorization(bool &flag);
	void registration(bool& flag);
	void make_bo(string);
	void userwork(string);
	void show_orders(string);
	void adminwork(string);
	void make_eo(string);
	void edit_flights();
	void edit_flight();
	void menu_user();
	void menu_admin();
	void edit_user_root();
	void make_order(string login);
	friend std::ifstream& operator>> (std::ifstream& in, Users& Users);
	friend std::ostream& operator<< (std::ostream& out, const Users& Users);
	friend std::istream& operator>> (std::istream& in, Users& Users);
	friend std::ofstream& operator<< (std::ofstream& out, const Users& obj);
};

