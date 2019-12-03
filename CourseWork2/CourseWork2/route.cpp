#include "header.h"
#include "route.h"
route::route(int lenght, int time, string status, string date_of_shipping, string date_of_arrival, int number_places, string name, string speed, int year_of_creating):
airplane(number_places,name,speed,year_of_creating)
{
	this->set_lenght(lenght);
	this->set_date_of_arrival(date_of_arrival);
	this->set_date_of_shipping(date_of_arrival);
	this->set_time(time);
	this->set_status(status);
}

void route::set_lenght(int lenght)
{
	this->lenght = lenght;
}

void route::set_time(int time)
{
	this->time = time;
}

void route::set_status(string status)
{
	this->status = status;
}

void route::set_date_of_shipping(string date_of_shipping)
{
	this->date_of_shipping = date_of_shipping;
}

void route::set_date_of_arrival(string date_of_arrival)
{
	this->date_of_arrival = date_of_arrival;
}

int route::get_lenght()
{
	return this->lenght;
}

int route::get_time()
{
	return this->time;
}

string route::get_status()
{
	return this->status;
}

string route::get_date_of_shipping()
{
	return this->date_of_shipping;
}

string route::get_date_of_arrival()
{
	return this->date_of_arrival;
}
