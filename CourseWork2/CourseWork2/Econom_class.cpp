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