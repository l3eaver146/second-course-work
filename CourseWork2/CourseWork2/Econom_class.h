#pragma once
#include "Header.h"
#include "Air_ticket.h"
class Econom_class : public virtual Air_ticket
{
protected:
	string location;
	string press;
	string porthole;
public:
	Econom_class();
	~Econom_class();
	Econom_class(string, string, string);
	void set_all();
	void set_location(string);
	void set_press(string);
	void set_porthole(string);
	string get_location();
	string get_press();
	string get_porthole();
	friend std::istream& operator>> (std::istream& in, Econom_class& obj);
	friend std::ostream& operator<< (std::ostream& out, const Econom_class& obj);
	friend std::ifstream& operator>> (std::ifstream& in, Econom_class& obj);
	friend std::ofstream& operator<< (std::ofstream& out, const Econom_class& obj);
};

