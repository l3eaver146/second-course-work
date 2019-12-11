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
		cout << "1 - Заказать билет бизнесс класса " << endl;
		cout << "2 - Заказать билет эконом класса " << endl;
		cout << "0 - Назад" << endl;
		int cho = 0;
		check(cho);
		switch (cho)
		{
		case 1: {
			obj.make_bo(login);
			cout << "Ваш заказ успешно добавлен!" << endl;
			break;
		}
		case 2: {
			obj.make_eo(login);
			cout << "Ваш заказ успешно добавлен!" << endl;
			break;
		}
		case 0: {
			exit = false;
			break;
		}
		default:cout << "Такого варианта нет!" << endl;
			break;
		}
	}
}
void Users::enter_password()
{
	string s;
	int ch = 0;
	bool flag = true;
	while (flag == true) {
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
		if (s.length() < 8) {
			cout << "Ваш пароль слишком короткий!Длина должна быть не менее 8 символов." << endl;
			cout << " Повторите попытку ввода : " << endl;
		}
		else {
			flag = false;
		}
	}
	this->set_password(s);
}

void Users::dell_EO(string login)
{
	bool flag = true;
	while (flag == true) {
		List <Order> list;
		list.readFileEO("Econom_orders.txt");
		list.show_orders_by_login(login);
		cout << "Введите номер вашего билета : ";
		int number_of_ticket;
		check(number_of_ticket);
		string flight;
		cout << "Введите номер рейса : ";
		cin >> flight;
		int i = list.return_index_of_order(flight, login, number_of_ticket);
		if (i==-1) {
			cout << "Такого заказа не сущствует!" << endl;
			cout << "Повторите попытку ввода : " << endl;
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
		cout << "Введите номер вашего билета : ";
		int number_of_ticket;
		check(number_of_ticket);
		string flight;
		cout << "Введите номер рейса : ";
		cin >> flight;
		int i = list.return_index_of_order(flight, login, number_of_ticket);
		if (i == -1) {
			cout << "Такого заказа не сущствует!" << endl;
			cout << "Повторите попытку ввода : " << endl;
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
	cout << "\t\t\t\t" << "Имя учетной записи : " << get_login() << "  Пароль учетной записи : " << get_password() << " Права учетной записи : " << get_root() << endl;
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
	out << "Информация о пользователях : " << endl;
	out << "\t login : " << "\t root : " << endl;
	out << Users.login << "\t" << Users.root << endl;;
	return out;
}

std::istream& operator>>(std::istream& in, Users& Users)
{
	cout << "Введите логин : ";
	in >> Users.login;
	cout << "Введите пароль : ";
	in >> Users.password;
	return in;
}

std::ofstream& operator<<(std::ofstream& out, const Users& Users)
{
	out << Users.login << " " << Users.password << " " << Users.root << endl;
	return out;
}

void Users::authorization(bool& flag)
{
	List<Users> list_of_users;
	string File_of_users = "Users.txt";
	list_of_users.readFile(File_of_users);
	bool flag_exit_authorization = true;
	while (flag_exit_authorization == true) {
		Users temp_obj;
		cin >> temp_obj;
		bool result = list_of_users.check_user_data(temp_obj.get_login(), temp_obj.get_password());
		if (result == true) {
			cout << endl << "Успешная авторизация!";
			this->set_login(temp_obj.get_login());
			this->set_password(temp_obj.get_password());
			this->set_root(temp_obj.get_root());
			flag = false;
			flag_exit_authorization = false;
			system("cls");
		}
		else {
			cout << endl << "Повторите попытку авторизации!\nВведенные вами данные неверны!\n";
		}
	}
	if (this->get_root() == "admin")
		this->adminwork(this->get_login());
	else this->userwork(this->get_login());
}

void Users::registration(bool& flag)
{
	List<Users> list_of_users;
	string File_of_users = "Users.txt";
	list_of_users.readFile(File_of_users);
	Users temp;
	bool flag_exit_registration = true;
	cout << "Добро пожаловать в раздел регистрации пользователей! " << endl;
	while (flag_exit_registration == true) {
		cout << "введите ваш логин : ";
		cin >> temp.login;
		bool res = list_of_users.check_on_copy(temp.get_login());
		if (res == true) {
			cout << "Введите ваш пароль : ";
			temp.enter_password();
			temp.set_root("user");
			list_of_users.writeEndFileusers(File_of_users, temp);
			cout << endl << "Вы успешно зарегистрировались.Ваши права - user !" << endl;
			this->set_login(temp.get_login());
			this->set_password(temp.get_password());
			this->set_root("user");
			flag = false;
			flag_exit_registration = false;
		}
		else {
			cout << "Ваш логин не униклен! Повторите попытку ввода ! ";
		}
	}
	this->userwork(this->get_login());
}

void Users::make_bo(string login)
{
	List<Order>list;
	list.readFileFlights("Flights.txt");
	string temp_flight;
	cout << "Введите номер желаемого рейса :";
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
	cout << "Введите номер желаемого рейса :";
	cin >> temp_flight;
	Order obj = list.search_by_flight(temp_flight);
	/*((Passenger_data)obj).set_all();
	((Air_ticket)obj).set_all();
	((Econom_class)obj).set_all();*/
	obj.set_data();
	obj.set_login(login);
	list.writeEndFileEO("Econom_orders.txt",obj);
}
void Users:: menu_admin() {
	cout << "1 - Редактировать права пользователя !" << endl;
	cout << "2 - Изменить информацию о доступных рейсах " << endl;
	cout << "3 - Сделать заказ " << endl;
	cout << "4 - Посмотреть информацию о заказах " << endl;
	cout << "0 - Выход " << endl;
}
void Users::menu_user() {
	cout << "Здравствуйте , пользователь!" << endl;
	cout << "1 - Посмотреть доступные рейсы " << endl;
	cout << "2 - Оформить заказ " << endl;
	cout << "3 - Посмотреть ваши заказы " << endl;
	//cout << "4 - Удалить ваш заказ " << endl;
	cout << "0 - Вернуться назад " << endl;
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
		/*вывод*/case 1: {
			system("cls");
			List<Order>list;
			list.readFileFlights("Flights.txt");
			list.show_flights();
			break;
		}
		/*создание заказа*/case 2: {
			this->make_order(login);
			break;
		}
		/*просмотр заказов*/case 3: {
			int ch = 0;
			bool fl = true;
			while (fl == true) {
				cout << "1 - Заказы эконом класса " << endl;
				cout << "2 - Заказы бизнес класса " << endl;
				cout << "0 - Назад " << endl;
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
				default:cout << "Такого варианта нет!" << endl;
					break;
				}
			}
			break; 
		}
		/*case 4: {
			int ch = 0;
			bool fl = true;
			while (fl == true) {
				cout << "1 - Заказы эконом класса " << endl;
				cout << "2 - Заказы бизнес класса " << endl;
				cout << "0 - Назад " << endl;
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
					cout << "Такого варианта нет!" << endl;
					break;
				}
				}
			}
			break;
		}*/
		case 0: {
			flag = false;
			break;
		}
		default: {cout << "Введен некорректный вариант ! Повторите попытку : " << endl;
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
		case 1: {
			break;
		}
		case 2: {
			break;
		}
		case 3: {
			this->make_order(login);
			break;
		}
		case 4: {
			break;
		}
		case 0: {
			flag = false;
			break;
		}
		default:{
			cout << "Нет такого варианта!" << endl;
			break;
		}
		}
	}
}