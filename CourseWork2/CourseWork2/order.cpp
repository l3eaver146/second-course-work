#include "Order.h"

Order::Order()
{
}

Order::Order(int number_of_ticket, string status, string departs_contry, string arrive_contry, string food, string air_conditioning, string tv, string bar, string staff, string departs_city, string arrival_city, string flight, string price, string date_of_arrival, string date_of_shipping, int number_of_place, string login, string password, string root, string name, string surname, string patronimyc, string passport_number)
	:Air_ticket(number_of_ticket, status, departs_contry, arrive_contry), Business_class(food, bar, air_conditioning, tv, staff), Passenger_data(name, surname, patronimyc, passport_number), Users(login, password, root)
{/*��� ������� business ������*/
	this->arrival_city = arrival_city;
	this->date_of_arrival = date_of_arrival;
	this->date_of_shipping = date_of_shipping;
	this->departs_city = departs_city;
	this->price = price;
	this->number_of_place = number_of_place;
	this->flight = flight;
}

Order::Order(int number_of_ticket, string status, string departs_contry, string arrive_contry, string location, string press, string porthole, string departs_city, string arrival_city, string flight, string price, string date_of_arrival, string date_of_shipping, int number_of_place, string login, string password, string root, string name, string surname, string patronimyc, string passport_number)
	:Air_ticket(number_of_ticket, status, departs_contry, arrive_contry), Econom_class(press, porthole, location), Passenger_data(name, surname, patronimyc, passport_number), Users(login, password, root)
{
	this->arrival_city = arrival_city;
	this->date_of_arrival = date_of_arrival;
	this->date_of_shipping = date_of_shipping;
	this->departs_city = departs_city;
	this->flight = flight;
	this->price = price;
	this->number_of_place = number_of_place;
}

void Order::set_number_of_place(int number_of_place)
{
	this->number_of_place = number_of_place;
}

void Order::set_date_of_shipping(string date_of_shipping)
{
	this->date_of_shipping = date_of_shipping;
}

void Order::set_date_of_arrival(string date_of_arrival)
{
	this->date_of_arrival = date_of_arrival;
}

void Order::set_price(string price)
{
	this->price = price;
}

void Order::set_departs_city(string departs_city)
{
	this->departs_city = departs_city;
}

void Order::set_flight(string flight)
{
	this->flight = flight;
}

void Order::set_data_flight()
{
	string temp;
	cout << "������� ����� ������ ����� : " << endl;
	cin >> temp;
	this->set_flight(temp);
	cout << "������� ������ ����������� : " << endl;
	cin >> temp;
	this->set_departs_contry(temp);
	cout << "������� ������ �������� :" << endl;
	cin >> temp;
	this->set_arrive_contry(temp);
	cout << "������� ����� ����������� : " << endl;
	cin >> temp;
	this->set_departs_city(temp);
	cout << "������� ����� �������� :" << endl;
	cin >> temp;
	this->set_arrival_city(temp);
	cout << "������� ���� ����������� : " << endl;
	cin >> temp;
	this->set_date_of_shipping(temp);
	cout << "������� ���� �������� :" << endl;
	cin >> temp;
	this->set_date_of_arrival(temp);
}

void Order::set_arrival_city(string arrival_city)
{
	this->arrival_city = arrival_city;
}

int Order::get_number_of_place()
{
	return this->number_of_place;
}

string Order::get_date_of_shipping()
{
	return this->date_of_shipping;
}

string Order::get_date_of_arrival()
{
	return this->date_of_arrival;
}

string Order::get_price()
{
	return this->price;
}

string Order::get_departs_city()
{
	return this->departs_city;
}

string Order::get_flight()
{
	return this->flight;
}

string Order::get_arrival_city()
{
	return this->arrival_city;
}

void Order::show_flight()
{
	cout << "________________________________________________________________" << endl;
	cout << "����� ����� : " << this->get_flight() << endl;
	cout << "������ ����������� : " << this->get_departs_contry() << endl;
	cout << "������ �������� : " << this->get_arrive_contry() << endl;
	cout << "����� ����������� : " << this->get_departs_city() << endl;
	cout << "����� �������� : " << this->get_arrival_city() << endl;
	cout << "���� ����������� : " << this->get_date_of_shipping() << endl;
	cout << "���� �������� : " << this->get_date_of_arrival() << endl;
	cout << "________________________________________________________________" << endl;
}

Order& Order::operator=(const Order& other)
{
	this->arrive_contry = other.arrive_contry;
	this->arrival_city = other.arrival_city;
	this->flight = other.flight;
	this->departs_city = other.departs_city;
	this->departs_contry = other.departs_contry;
	this->date_of_shipping = other.date_of_shipping;
	this->date_of_arrival = other.date_of_arrival;
	this->air_conditioning = other.air_conditioning;
	this->bar = other.bar;
	this->food = other.food;
	this->location = other.location;
	this->login = other.login;
	this->name = other.name;
	this->surname = other.surname;
	this->patronimyc = other.patronimyc;
	this->passport_number = other.passport_number;
	this->number_of_place = other.number_of_place;
	this->number_of_ticket = other.number_of_ticket;
	this->staff = other.staff;
	this->press = other.press;
	this->tv = other.tv;
	this->status = other.status;
	this->porthole = other.porthole;
	this->password = other.password;
	this->root = other.root;
	this->price = other.price;
	return *this;
}
void Order::set_data() {
	string temp;
	cout << " ������� ���� ������� : ";
	cin >> temp;
	this->set_surname(temp);
	cout << "������� ���� ��� : ";
	cin >> temp;
	this->set_name(temp);
	cout << "������� ���� �������� : ";
	cin >> temp;
	this->set_patronimyc(temp);
	cout << "������� ����� ������ �������� : ";
	cin >> temp;
	this->set_passport_number(temp);
	this->set_number_of_ticket(rand() % (100 - 1 + 1) + 1);
	this->set_number_of_place(rand() % (200 - 1 + 1) + 1);
	string cho;
	bool flag = true;
	while (flag == true) {
		cout << "������� �������� ������������ ������ ����� : " << endl;
		cout << "1 - ����� " << endl;
		cout << "2 - ������ " << endl;
		cout << "3 - ����� " << endl;
		cin >> cho;
		switch (cho[0]) {
		case '1': {
			this->set_location("�����");
			flag = false;
			break;
		}
		case '2': {
			this->set_location("������");
			flag = false;
			break;
		}
		case '3': {
			this->set_location("�����");
			flag = false;
			break;
		}
		default: {
			cout << "��� ������ ��������!" << endl;
		}
		}
	}
	flag = true;
	while (flag == true) {
		cout << "������� �������� ���������� : " << endl;
		cout << "1 - ������ " << endl;
		cout << "2 - ������� " << endl;
		cout << "3 - ����� " << endl;
		cin >> cho;
		switch (cho[0]) {
		case '1': {
			this->set_press("������");
			flag = false;
			break;
		}
		case '2': {
			this->set_press("�������");
			flag = false;
			break;
		}
		case '3': {
			this->set_press("�����");
			flag = false;
			break;
		}
		default: {
			cout << "��� ������ ��������!" << endl;
		}
		}
	}
	flag = true;
	while (flag == true) {
		cout << "������ �� ����� ������ �������� � ����������� : " << endl;
		cout << "1 - �� " << endl;
		cout << "2 - ��� " << endl;
		cin >> cho;
		switch (cho[0]) {
		case '1': {
			this->set_porthole("����");
			flag = false;
			break;
		}
		case '2': {
			this->set_porthole("���");
			flag = false;
			break;
		}
		default: {
			cout << "��� ������ ��������!" << endl;
		}
		}
	}
	this->set_price("450$");
	this->set_status("Econom");
}
void Order::set_data_bo() {
	string temp;
	cout << " ������� ���� ������� : ";
	cin >> temp;
	this->set_surname(temp);
	cout << "������� ���� ��� : ";
	cin >> temp;
	this->set_name(temp);
	cout << "������� ���� �������� : ";
	cin >> temp;
	this->set_patronimyc(temp);
	cout << "������� ����� ������ �������� : ";
	cin >> temp;
	this->set_passport_number(temp);
	this->set_number_of_ticket(rand() % (100 - 1 + 1) + 1);
	this->set_number_of_place(rand() % (10 - 1 + 1) + 1);
	string cho;
	bool flag = true;
	while (flag == true) {
		cout << "�������� �������� �������� : " << endl;
		cout << "1 - ������ " << endl;
		cout << "2 - ���������� " << endl;
		cin >> cho;
		switch (cho[0]) {
		case '1': {
			this->set_staff("������");
			flag = false;
			break;
		}
		case '2': {
			this->set_staff("����������");
			flag = false;
			break;
		}
		default: {
			cout << "��� ������ ��������!" << endl;
		}
		}
	}
	flag = true;
	while (flag == true) {
		cout << "��� ����� �����������? " << endl;
		cout << "1 - �� " << endl;
		cout << "2 - ��� " << endl;
		cin >> cho;
		switch (cho[0]) {
		case '1': {
			this->set_air_conditioning("����");
			flag = false;
			break;
		}
		case '2': {
			this->set_air_conditioning("���");
			flag = false;
			break;
		}
		default: {
			cout << "��� ������ ��������!" << endl;
		}
		}
	}
	flag = true;
	while (flag == true) {
		cout << "����� �� ��� ���������? " << endl;
		cout << "1 - �� " << endl;
		cout << "2 - ��� " << endl;
		cin >> cho;
		switch (cho[0]) {
		case '1': {
			this->set_tv("����");
			flag = false;
			break;
		}
		case '2': {
			this->set_tv("���");
			flag = false;
			break;
		}
		default: {
			cout << "��� ������ ��������!" << endl;
		}
		}
	}
	flag = true;
	while (flag == true) {
		cout << "����� �� ��� ���? " << endl;
		cout << "1 - �� " << endl;
		cout << "2 - ��� " << endl;
		cin >> cho;
		switch (cho[0]) {
		case '1': {
			this->set_bar("����");
			flag = false;
			break;
		}
		case '2': {
			this->set_bar("���");
			flag = false;
			break;
		}
		default: {
			cout << "��� ������ ��������!" << endl;
		}
		}
	}
	flag = true;
	while (flag == true) {
		cout << "����� ��� ������� ��� ����������? " << endl;
		cout << "1 - ����������� " << endl;
		cout << "2 - ����������� " << endl;
		cin >> cho;
		switch (cho[0]) {
		case '1': {
			this->set_food("3");
			flag = false;
			break;
		}
		case '2': {
			this->set_food("2");
			flag = false;
			break;
		}
		default: {
			cout << "��� ������ ��������!" << endl;
		}
		}
	}
	this->set_price("1000$");
	this->set_status("Business");
}
void Order::show_order_data() {
	cout << "_____________________________________________________" << endl;
	cout << "����� ������ ������ : " << this->get_number_of_ticket() << endl;
	cout << "����� ������ ����� : " << this->get_number_of_place() << endl;
	cout << "����� ����� : " << this->get_flight() << endl;
	cout << "���� ������ ������ : " << this->get_price() << endl;
	cout << "��� ����� " << get_status() << " ������ " << endl;
	cout << "������������ �� ������ : " << get_departs_contry() << endl;
	cout << "��������� � ������ : " << get_arrive_contry() << endl;
	cout << "���� ����������� : " << get_date_of_shipping() << endl;
	cout << "_____________________________________________________" << endl;
}
Order::~Order()
{
}

std::ifstream& operator>>(std::ifstream& in, Order& Order)
{
	in >> Order.flight;
	in >> Order.departs_contry;
	in >> Order.arrive_contry;
	in >> Order.departs_city;
	in >> Order.arrival_city;
	in >> Order.date_of_shipping;
	in >> Order.date_of_arrival;
	in >> Order.surname;
	in >> Order.name;
	in >> Order.patronimyc;
	in >> Order.passport_number;
	in >> Order.status;
	in >> Order.location;
	in >> Order.porthole;
	in >> Order.press;
	in >> Order.number_of_ticket;
	in >> Order.price;
	in >> Order.login;
	in >> Order.number_of_place;
	return in;
}

std::ofstream& operator<<(std::ofstream& out, const Order& obj)
{
	out << obj.flight << " "
		<< obj.departs_contry << " "
		<< obj.arrive_contry << " "
		<< obj.departs_city << " "
		<< obj.arrival_city << " "
		<< obj.date_of_shipping << " "
		<< obj.date_of_arrival << " "
		<< obj.surname << " "
		<< obj.name << " "
		<< obj.patronimyc << " "
		<< obj.passport_number << " "
		<< obj.status << " "
		<< obj.location << " "
		<< obj.porthole << " "
		<< obj.press << " "
		<< obj.price << " "
		<< obj.login;
	return out;
}
