#include "Air_ticket.h"

Air_ticket::Air_ticket()
{
	this->number_of_ticket = 0;
	this->arrive_contry = "";
	this->departs_contry = "";
	this->status = "";
}

void Air_ticket::set_all() {
	this->set_number_of_ticket(rand() % (100 - 1 + 1) + 1);
}
Air_ticket::~Air_ticket()
{
}

Air_ticket::Air_ticket(int number_of_ticket, string status, string departs_contry, string arrive_contry)
{
	this->set_number_of_ticket(number_of_ticket);
	this->set_status(status);
	this->set_departs_contry(departs_contry);
	this->set_arrive_contry(arrive_contry);
}

void Air_ticket::set_number_of_ticket(int number_of_ticket)
{
	this->number_of_ticket = number_of_ticket;
}

void Air_ticket::set_status(string status)
{
	this->status = status;
}

void Air_ticket::set_departs_contry(string departs_contry)
{
	this->departs_contry = departs_contry;
}

void Air_ticket::set_arrive_contry(string arrive_contry)
{
	this->arrive_contry = arrive_contry;
}

string Air_ticket::get_status()
{
	return this->status;
}

string Air_ticket::get_departs_contry()
{
	return this->departs_contry;
}

string Air_ticket::get_arrive_contry()
{
	return this->arrive_contry;
}

int Air_ticket::get_number_of_ticket()
{
	return this->number_of_ticket;
}

std::istream& operator>>(std::istream& in, Air_ticket& obj)
{
	return in;
}

std::ostream& operator<<(std::ostream& out, const Air_ticket& obj)
{
	return out;
}

std::ifstream& operator>>(std::ifstream& in, Air_ticket& obj)
{
	in >> obj.number_of_ticket;
	in >> obj.status;
	in >> obj.departs_contry;
	in >> obj.arrive_contry;
	return in;
}

std::ofstream& operator<<(std::ofstream& out, const Air_ticket& obj)
{
	return out;
}
