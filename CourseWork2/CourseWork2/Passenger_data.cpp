#include "Passenger_data.h"

Passenger_data::Passenger_data()
{
	name = "";
	surname = "";
	patronimyc = "";
	passport_number = "";
}

Passenger_data::~Passenger_data()
{
}

void Passenger_data::set_all() {
	string temp;
	cout << " ¬ведите вашу ‘амилию : ";
	cin >> temp;
	this->set_surname(temp);
	cout << "¬ведите ваше »м€ : ";
	cin >> temp;
	this->set_name(temp);
	cout << "¬ведите ваше ќтчество : ";
	cin >> temp;
	this->set_patronimyc(temp);
	cout << "¬ведите номер вашего паспорта : ";
	cin >> temp;
	this->set_passport_number(temp);
}

Passenger_data::Passenger_data(string name, string surname, string patronimyc, string passport_number)
{
	this->set_name(name);
	this->set_surname(surname);
	this->set_patronimyc(patronimyc);
	this->set_passport_number(passport_number);
}

void Passenger_data::set_name(string name)
{
	this->name = name;
}

void Passenger_data::set_surname(string surname)
{
	this->surname = surname;
}

void Passenger_data::set_patronimyc(string patronimyc)
{
	this->patronimyc=patronimyc;
}

void Passenger_data::set_passport_number(string passport_number)
{
	this->passport_number = passport_number;
}

string Passenger_data::get_name()
{
	return this->name;
}

string Passenger_data::get_surname()
{
	return this->surname;
}

string Passenger_data::get_patronimyc()
{
	return this->patronimyc;
}

string Passenger_data::get_passport_number()
{
	return this->passport_number;
}

std::istream& operator>>(std::istream& in, Passenger_data& obj)
{
	return in;
}

std::ostream& operator<<(std::ostream& out, const Passenger_data& obj)
{
	return out;
}

std::ifstream& operator>>(std::ifstream& in, Passenger_data& obj)
{
	in >> obj.number_of_ticket;
	in >> obj.status;
	in >> obj.departs_contry;
	in >> obj.arrive_contry;
	in >> obj.name;
	in >> obj.surname;
	in >> obj.patronimyc;
	in >> obj.passport_number;
	return in;
}

std::ofstream& operator<<(std::ofstream& out, const Passenger_data& obj)
{
	return out;
}
