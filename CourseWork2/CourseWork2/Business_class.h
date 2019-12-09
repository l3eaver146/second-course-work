#pragma once
#include "Header.h"
#include "Air_ticket.h"
class Business_class : public virtual Air_ticket
{
protected:
	string food;/*включено*/
	string air_conditioning;/*есть/нет*/
	string tv;/*есть*/
	string bar;
	string staff;
public:
	Business_class();
	~Business_class();
	Business_class(string,string,string,string,string);
	void set_tv(string);
	void set_food(string);
	void set_air_conditioning(string);
	void set_bar(string);
	void set_staff(string);	
	string get_tv();
	string get_food();
	string get_air_conditioning();
	string get_bar();
	string get_staff();
	friend std::istream& operator>> (std::istream& in, Business_class&obj);
	friend std::ostream& operator<< (std::ostream& out, const  Business_class& obj);
	friend std::ifstream& operator>> (std::ifstream& in, Business_class& obj);
	friend std::ofstream& operator<< (std::ofstream& out, const  Business_class& obj);
};

