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
				cout << " Повторите попытку ввода : "<<endl;
			}else{
				flag = false;
		}
	}
	this->set_password(s);
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
	out << "\t login :" << "\t root :" << endl;
	out << Users.login << "\t" << Users.root << endl;;
	return out;
}

std::istream& operator>>(std::istream& in, Users& Users)
{
	cout << "Введите логин :";
	in >> Users.login;
	cout << "Введите пароль :";
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
		bool result = list_of_users.check_user_data(temp_obj.get_login(),temp_obj.get_password());
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
		this->adminwork();
	else this->userwork();
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
		cout << "введите ваш логин :";
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
	this->userwork();
}

void Users::make_bo()
{

}

void Users::make_eo()
{
	List<Order>list;
	string temp_flight;
	cout << "Введите номер желаемого рейса :";
	cin >> temp_flight;
	Order obj=list.search_by_flight(temp_flight);
}
void Users::menu_user() {
	cout << "Здравствуйте , пользователь!" << endl;
	cout << "1 - Посмотреть доступные рейсы " << endl;
	cout << "2 - Оформить заказ " << endl;
	cout << "3 - Посмотреть ваши заказы " << endl;
	cout << "0 - Вернуться назад " << endl;
}
void Users::userwork()
{
	bool flag = true;
	int choise = 0;
	while (flag == true) {
		this->menu_user();
		check(choise);
		switch (choise)
		{
		case 1: {
			system("cls");
			List<Order>list;
			list.readFileFlights("Flights.txt");
			list.show_flights();
			break;
		}
		case 2: {
			Order obj;
			bool exit = true;
			while (!exit) {
				cout << "1 - Заказать билет бизнесс класса " << endl;
				cout << "2 - Заказать билет эконом класса " << endl;
				cout << "0 - Назад" << endl;
				int cho = 0;
				check(cho);
				switch (cho)
				{
				case 1: {
					obj.make_bo();
				}
				case 2: {
					obj.make_eo();
				}
				case 0: {
					flag = false;
					break;
				}
				default:
					break;
				}
			}
			break;
		}
		case 3:break;
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

void Users::adminwork()
{
}
