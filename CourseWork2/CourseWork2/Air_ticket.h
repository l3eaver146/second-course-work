#pragma once
#include "Header.h"
class Air_ticket
{
protected:
	int number_of_ticket;
	string status;
	string departs_contry;
	string arrive_contry;
public:
	Air_ticket();
	~Air_ticket();
	Air_ticket(int, string, string, string);
	void set_number_of_ticket(int);
	void set_status(string);
	void set_departs_contry(string);
	void set_arrive_contry(string);
	string get_status();
	string get_departs_contry();
	string set_arrive_contry();
	int get_number_of_ticket();
	friend std::istream& operator>> (std::istream& in, Air_ticket & obj);
	friend std::ostream& operator<< (std::ostream& out, const  Air_ticket& obj);
	friend std::ifstream& operator>> (std::ifstream& in, Air_ticket& obj);
	friend std::ofstream& operator<< (std::ofstream& out, const  Air_ticket& obj);
};

