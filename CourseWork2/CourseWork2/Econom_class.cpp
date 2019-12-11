#include "Econom_class.h"

Econom_class::Econom_class()
{
	press = "";
	porthole = "";
	location = "";
}

Econom_class::~Econom_class()
{
}

Econom_class::Econom_class(string press, string porthole, string location)
{
	this->set_press(press);
	this->set_porthole(porthole);
	this->set_location(location);
}

void Econom_class::set_all()
{
	string cho;
	bool flag = true;
	while (flag == true) {
		cout << "Введите желаемое расположение вашего места : " << endl;
		cout << "1 - Центр " << endl;
		cout << "2 - Голова " << endl;
		cout << "3 - Хвост " << endl;
		cin >> cho;
		switch (cho[0]) {
		case '1': {
			this->set_location("Центр");
			flag = false;
			break;
		}
		case '2': {
			this->set_location("Голова");
			flag = false;
			break;
		}
		case '3': {
			this->set_location("Хвост");
			flag = false;
			break;
		}
		default: {
			cout << "Нет такого варианта!" << endl;
		}
		}
	}
	flag = true;
	while (flag == true) {
		cout << "Введите желаемую литературу : " << endl;
		cout << "1 - Газеты " << endl;
		cout << "2 - Журналы " << endl;
		cout << "3 - Книги " << endl;
		cin >> cho;
		switch (cho[0]) {
		case '1': {
			this->set_press("Газеты");
			flag = false;
			break;
		}
		case '2': {
			this->set_press("Журналы");
			flag = false;
			break;
		}
		case '3': {
			this->set_press("Книги");
			flag = false;
			break;
		}
		default: {
			cout << "Нет такого варианта!" << endl;
		}
		}
	}
	flag = true;
	while (flag == true) {
		cout << "Хотите во время полета смотреть в иллюминатор : " << endl;
		cout << "1 - Да " << endl;
		cout << "2 - Нет " << endl;
		cin >> cho;
		switch (cho[0]) {
		case '1': {
			this->set_porthole("Есть");
			flag = false;
			break;
		}
		case '2': {
			this->set_porthole("Нет");
			flag = false;
			break;
		}
		default: {
			cout << "Нет такого варианта!" << endl;
		}
		}
	}
}

void Econom_class::set_location(string location)
{
	this->location = location;
}

void Econom_class::set_press(string press)
{
	this->press = press;
}

void Econom_class::set_porthole(string porthole)
{
	this->porthole = porthole;
}

string Econom_class::get_location()
{
	return this->location;
}

string Econom_class::get_press()
{
	return this->press;
}

string Econom_class::get_porthole()
{
	return this->porthole;
}

std::istream& operator>>(std::istream& in, Econom_class& obj)
{
	return in;
}

std::ostream& operator<<(std::ostream& out, const Econom_class& obj)
{
	return out;
}

std::ifstream& operator>>(std::ifstream& in, Econom_class& obj)
{
	in >> obj.number_of_ticket;
	in >> obj.status;
	in >> obj.departs_contry;
	in >> obj.arrive_contry;
	in >> obj.location;
	in >> obj.press;
	in >> obj.porthole;
	return in;
}

std::ofstream& operator<<(std::ofstream& out, const Econom_class& obj)
{
	return out;
}