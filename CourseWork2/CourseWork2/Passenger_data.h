#pragma once
#include "Header.h"
#include "Air_ticket.h"
class Passenger_data : public virtual Air_ticket
{
protected:
	string name;
	string surname;
	string patronimyc;
	string passport_number;
public :
	Passenger_data();
	~Passenger_data();
	Passenger_data(string, string, string, string);
	void set_name(string);
	void set_surname(string);
	void set_patronimyc(string);
	void set_passport_number(string);
	string get_name();
	string get_surname();
	string get_patronimyc();
	string get_passport_number();
	friend std::istream& operator>> (std::istream& in, Passenger_data& obj);
	friend std::ostream& operator<< (std::ostream& out, const  Passenger_data& obj);
	friend std::ifstream& operator>> (std::ifstream& in, Passenger_data& obj);
	friend std::ofstream& operator<< (std::ofstream& out, const  Passenger_data& obj);
};

