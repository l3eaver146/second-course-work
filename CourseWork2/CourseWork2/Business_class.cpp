#include "Business_class.h"

Business_class::Business_class()
{
}

Business_class::~Business_class()
{
}

Business_class::Business_class(string food, string bar, string air_conditioning,string tv,string staff)
{
	this->set_food(food);
	this->set_bar(bar);
	this->set_air_conditioning(air_conditioning);
	this->set_tv(tv);
	this->set_staff(staff);
}

void Business_class::set_tv(string tv)
{
	this->tv = tv;
}

void Business_class::set_food(string food)
{
	this->food = food;
}

void Business_class::set_air_conditioning(string air_conditioning)
{
	this->air_conditioning = air_conditioning;
}

void Business_class::set_bar(string bar)
{
	this->bar = bar;
}

void Business_class::set_staff(string staff)
{
	this->staff = staff;
}

string Business_class::get_tv()
{
	return this->tv;
}

string Business_class::get_food()
{
	return this->food;
}

string Business_class::get_air_conditioning()
{
	return this->air_conditioning;
}

string Business_class::get_bar()
{
	return this->bar;
}

string Business_class::get_staff()
{
	return this->staff;
}

std::istream& operator>>(std::istream& in, Business_class& obj)
{
	return in;
}

std::ostream& operator<<(std::ostream& out, const Business_class& obj)
{
	return out;
}

std::ifstream& operator>>(std::ifstream& in, Business_class& obj)
{
	in >> obj.number_of_ticket;
	in >> obj.status;
	in >> obj.departs_contry;
	in >> obj.arrive_contry;
	in >> obj.food;
	in >> obj.air_conditioning;
	in >> obj.tv;
	in >> obj.bar;
	in >> obj.staff;
	return in;
}

std::ofstream& operator<<(std::ofstream& out, const Business_class& obj)
{
	return out;
}
