#include "Business_class.h"

Business_class::Business_class()
{
	food = "";
	baggage = "";
	air_conditioning = "";
	tv = "";
}

Business_class::~Business_class()
{
}

Business_class::Business_class(string food, string baggage, string air_conditioning,string tv)
{
	this->set_food(food);
	this->set_baggage(baggage);
	this->set_air_conditioning(air_conditioning);
	this->set_tv(tv);
}

void Business_class::set_tv(string tv)
{
	this->tv = tv;
}

void Business_class::set_food(string food)
{
	this->food = food;
}

void Business_class::set_baggage(string baggage)
{
	this->baggage = baggage;
}

void Business_class::set_air_conditioning(string air_conditioning)
{
	this->air_conditioning = air_conditioning;
}

string Business_class::get_tv()
{
	return this->tv;
}

string Business_class::get_food()
{
	return this->food;
}

string Business_class::get_baggage()
{
	return this->baggage;
}

string Business_class::get_air_conditioning()
{
	return this->air_conditioning;
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
	in >> obj.baggage;
	in >> obj.air_conditioning;
	in >> obj.tv;
	return in;
}

std::ofstream& operator<<(std::ofstream& out, const Business_class& obj)
{
	return out;
}
