#include "Users.h"
#include "Protect.h"
#include "List.h"
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

void Users::make_order(string login) {
	Order obj;
	bool exit = true;
	while (exit) {
		cout << "1 - �������� ����� ������� ������ " << endl;
		cout << "2 - �������� ����� ������ ������ " << endl;
		cout << "0 - �����" << endl;
		int cho = 0;
		check(cho);
		switch (cho)
		{
		case 1: {
			obj.make_bo(login);
			cout << "��� ����� ������� ��������!" << endl;
			break;
		}
		case 2: {
			obj.make_eo(login);
			cout << "��� ����� ������� ��������!" << endl;
			break;
		}
		case 0: {
			exit = false;
			break;
		}
		default:cout << "������ �������� ���!" << endl;
			break;
		}
	}
}
void Users::enter_password()
{
	string s;
	int ch = 0;
	bool flag = true;
	//while (flag == true) {
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
		/*if (s.length() < 8) {
			cout << "��� ������ ������� ��������!����� ������ ���� �� ����� 8 ��������." << endl;
			cout << " ��������� ������� ����� : " << endl;
		}
		else {
			flag = false;
		}*/
	//}
	this->set_password(s);
}

void Users::dell_EO(string login)
{
	bool flag = true;
	while (flag == true) {
		List <Order> list;
		list.readFileEO("Econom_orders.txt");
		list.show_orders_by_login(login);
		cout << "������� ����� ������ ������ : ";
		int number_of_ticket;
		check(number_of_ticket);
		string flight;
		cout << "������� ����� ����� : ";
		cin >> flight;
		int i = list.return_index_of_order(flight, login, number_of_ticket);
		if (i==-1) {
			cout << "������ ������ �� ���������!" << endl;
			cout << "��������� ������� ����� : " << endl;
		}
		else {
			list.dellPoint(list[i]);
			flag = false;
		}
		list.writeFileEO("Econom_orders.txt");
	}
}

void Users::dell_BO(string login)
{
	bool flag = true;
	while (flag == true) {
		List <Order> list;
		list.readFileBO("Econom_orders.txt");
		list.show_orders_by_login(login);
		cout << "������� ����� ������ ������ : ";
		int number_of_ticket;
		check(number_of_ticket);
		string flight;
		cout << "������� ����� ����� : ";
		cin >> flight;
		int i = list.return_index_of_order(flight, login, number_of_ticket);
		if (i == -1) {
			cout << "������ ������ �� ���������!" << endl;
			cout << "��������� ������� ����� : " << endl;
		}
		else {
			list.dellPoint(list[i]);
			flag = false;
		}
		list.writeFileBO("Econom_orders.txt");
	}
}

void Users::show_data_users()
{
	cout << "\t\t\t\t" << "��� ������� ������ : " << get_login() << "  ������ ������� ������ : " << get_password() << " ����� ������� ������ : " << get_root() << endl;
}

std::ifstream& operator>>(std::ifstream& in, Users& Users)
{
	in >> Users.login;
	in >> Users.password;
	in >> Users.root;
	return in;
}

std::ostream& operator<<(std::ostream& out, const Users& Users)
{
	out << endl;
	out << "__________________________________________" << endl;
	out << "���������� � ������������ : " << endl;
	out << "login : " << Users.login << endl;
	out<< "root : "<<Users.root << endl;
	out << "__________________________________________" << endl;
	return out;
}

std::istream& operator>>(std::istream& in, Users& Users)
{
	cout << "������� ����� : ";
	in >> Users.login;
	cout << "������� ������ : ";
	Users.enter_password();
	return in;
}

std::ofstream& operator<<(std::ofstream& out, const Users& Users)
{
	out << Users.login << " " << Users.password << " " << Users.root;
	return out;
}

void Users::authorization(bool& flag)
{
	system("color 02");
	List<Users> list_of_users;
	string File_of_users = "Users.txt";
	list_of_users.readFile(File_of_users);
	bool flag_exit_authorization = true;
	while (flag_exit_authorization == true) {
		string root;
		Users temp_obj;
		cin >> temp_obj;
		
		bool result = list_of_users.check_user_data(temp_obj.get_login(), temp_obj.get_password(),root);
		temp_obj.set_root(root);
		if (result == true) {
			cout << endl << "�������� �����������!";
			this->set_login(temp_obj.get_login());
			this->set_password(temp_obj.get_password());
			this->set_root(temp_obj.get_root());
			flag = false;
			flag_exit_authorization = false;
			system("cls");
		}
		else {
			cout << endl << "��������� ������� �����������!\n��������� ���� ������ �������!\n";
		}
	}
	if (this->get_root() == "admin") {
		this->adminwork(this->get_login());
	}
	else {
		this->userwork(this->get_login());
	}
	}
void Users::show_orders(string login) {
	int ch = 0;
	bool fl = true;
	while (fl == true) {
		cout << "1 - ������ ������ ������ " << endl;
		cout << "2 - ������ ������ ������ " << endl;
		cout << "0 - ����� " << endl;
		check(ch);
		switch (ch)
		{
		case 1: {
			List <Order> list;
			list.readFileEO("Econom_orders.txt");
			list.show_orders_by_login(login);
			break;
		}
		case 2: {
			List <Order> list;
			list.readFileBO("Business_orders.txt");
			list.show_orders_by_login(login);
			break;
		}
		case 0: {
			fl = false;
			break;
		}
		default:cout << "������ �������� ���!" << endl;
			break;
		}
	}
}
void Users::registration(bool& flag)
{
	List<Users> list_of_users;
	string File_of_users = "Users.txt";
	list_of_users.readFile(File_of_users);
	Users temp;
	bool flag_exit_registration = true;
	cout << "����� ���������� � ������ ����������� �������������! " << endl;
	while (flag_exit_registration == true) {
		cout << "������� ��� ����� : ";
		cin >> temp.login;
		bool res = list_of_users.check_on_copy(temp.get_login());
		if (res == true) {
			cout << "������� ��� ������ : ";
			temp.enter_password();
			temp.set_root("user");
			list_of_users.writeEndFileusers(File_of_users, temp);
			cout << endl << "�� ������� ������������������.���� ����� - user !" << endl;
			this->set_login(temp.get_login());
			this->set_password(temp.get_password());
			this->set_root("user");
			flag = false;
			flag_exit_registration = false;
		}
		else {
			cout << "��� ����� �� �������! ��������� ������� ����� ! ";
		}
	}
	this->userwork(this->get_login());
}

void Users::make_bo(string login)
{
	List<Order>list;
	list.readFileFlights("Flights.txt");
	string temp_flight;
	cout << "������� ����� ��������� ����� :";
	cin >> temp_flight;
	Order obj = list.search_by_flight(temp_flight);
	/*((Passenger_data)obj).set_all();
	((Air_ticket)obj).set_all();
	((Econom_class)obj).set_all();*/
	obj.set_data_bo();
	obj.set_login(login);
	list.writeEndFileBO("Business_orders.txt", obj);
}

void Users::make_eo(string login)
{
	List<Order>list;
	list.readFileFlights("Flights.txt");
	string temp_flight;
	cout << "������� ����� ��������� ����� :";
	cin >> temp_flight;
	Order obj = list.search_by_flight(temp_flight);
	/*((Passenger_data)obj).set_all();
	((Air_ticket)obj).set_all();
	((Econom_class)obj).set_all();*/
	obj.set_data();
	obj.set_login(login);
	list.writeEndFileEO("Econom_orders.txt",obj);
}
void Users::edit_flights()
{
	bool flag = true;
	while (flag) {
		int choise = 0;
		cout << "�������� , ��� ������ �� ������ ��������� ���� ������ :" << endl;
		cout << "1 - �������� ���� " << endl;
		cout << "2 - ������� ���� " << endl;
		cout << "3 - ������������� ���� " << endl;
		cout << "4 - ���������� � ���� ������ " << endl;
		cout << "0 - �����" << endl;
		check(choise);
		switch (choise)
		{
		/*ready*/case 1: {
			List<Order>list_of_flights;
			Order flight;
			flight.set_data_flight();
			list_of_flights.writeEndFileFlights("Flights.txt",flight);
			break;
		}
		case 2: {

			break;
		}
		case 3: {
			this->edit_flight();
			break;
		}
		/*ready*/case 4: {
			List<Order>list;
			list.readFileFlights("Flights.txt");
			list.show_flights();
			break;
		}
		case 0: {
			flag = false;
			break;
		}
		default: {
			cout << "������ �������� ���!" << endl;
			break; }
		}
	}
}
void Users::edit_flight()
{
	List<Order>list;
	list.readFileFlights("Flights.txt");
	bool flag = true;
	while (flag) {
		cout << "������� ����� �����, ���� �����������/�������� , �������� �� ������ �������� : " << endl;
		string temp_flight;
		cin >> temp_flight;
		list.edit_flight(temp_flight);
		list.writeFileFlights("Flights.txt");
		break;
	}
}
void Users:: menu_admin() {
	cout << "������������, ������������� !" << endl;
	cout << "1 - �������� ����� ������������ �� admin " << endl;
	cout << "2 - �������� ���������� � ��������� ������ " << endl;
	cout << "3 - ������� ����� " << endl;
	cout << "4 - ���������� ���������� � ������� " << endl;/*���� �������� �� �������, ������� � ������������� ������� ������*/
	cout << "5 - ���������� ���������� � ������������� " << endl;
	cout << "0 - ����� " << endl;
}
void Users::edit_user_root()
{
	string login;
	List<Users> list;
	list.readFile("Users.txt");
	cout << "������� ����� ������������ , ����� �������� ������ �������� : ";
	cin >> login;
	list.edit_by_login(login);
	list.writeFile("Users.txt");
}

void Users::menu_user() {
	cout << "������������ , ������������!" << endl;
	cout << "1 - ���������� ��������� ����� " << endl;
	cout << "2 - �������� ����� " << endl;
	cout << "3 - ���������� ���� ������ " << endl;
	cout << "4 - ������� ��� ����� " << endl;
	cout << "0 - ��������� ����� " << endl;
}
void Users::userwork(string login)
{
	bool flag = true;
	int choise = 0;
	while (flag == true) {
		this->menu_user();
		check(choise);
		switch (choise)
		{
		/*�����*/case 1: {
			system("cls");
			List<Order>list;
			list.readFileFlights("Flights.txt");
			list.show_flights();
			break;
		}
		/*�������� ������*/case 2: {
			this->make_order(login);
			break;
		}
		/*�������� �������*/case 3: {
			this->show_orders(login);
			break; 
		}
		case 4: {
			int ch = 0;
			bool fl = true;
			while (fl == true) {
				cout << "1 - ������ ������ ������ " << endl;
				cout << "2 - ������ ������ ������ " << endl;
				cout << "0 - ����� " << endl;
				check(ch);
				switch (ch)
				{
				case 1: {
					this->dell_EO(login);
					break;
				}
				case 2: {
					this->dell_BO(login);
					break;
				}
				case 0: {
					fl = false;
					break;
				}
				default: {
					cout << "������ �������� ���!" << endl;
					break;
				}
				}
			}
			break;
		}
		case 0: {
			flag = false;
			break;
		}
		default: {cout << "������ ������������ ������� ! ��������� ������� : " << endl;
			break;
		}
		}
	}
}

void Users::adminwork(string login)
{
	int choise = 0;
	bool flag = true;
	while (flag) {
		this->menu_admin();
		check(choise);
		switch (choise)
		{
		/*ready*/case 1: {
			this->edit_user_root();
			break;
		}
		case 2: {
			this->edit_flights();
			break;
		}
		/*ready*/case 3: {
			this->make_order(login);
			break;
		}
		/*TODO*/case 4: {
			this->show_orders(login);
			break;
		}
		/*ready*/case 5: {
			List<Users>list;
			list.readFile("Users.txt");
			list.show_users();
			break;
		}
		/*ready*/case 0: {
			flag = false;
			break;
		}
		default:{
			cout << "��� ������ ��������!" << endl;
			break;
		}
		}
	}
}