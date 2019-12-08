#include "Users.h"

Users::Users(string login, string password, string root)
{
	this->set_login(login);
	this->set_password(password);
	this->set_root(root);
}

void Users::set_login(string login)
{
	this->login = login;
}

void Users::set_password(string password)
{
	this->password = password;
}

void Users::set_root(string root)
{
	this->root = root;
}

string Users::get_login()
{
	return this->login;
}

string Users::get_password()
{
	return this->password;
}

string Users::get_root()
{
	return this->root;
}

void Users::show_data_users()
{
		cout << "\t\t\t\t" << "Имя учетной записи : " << get_login() << "  Пароль учетной записи : " << get_password() << " Права учетной записи : " << get_root() << endl;
}

std::istream& operator>>(std::ifstream& in, Users& Users)
{
	in >> Users.login;
	in >> Users.password;
	in >> Users.root;
	return in;
}

std::ostream& operator<<(std::ostream& out, const Users& Users)
{
	return out;
}
