#include "Header.h"
#include "Route.h"
Route::Route(int lenght, int time, string status, string date_of_shipping, string date_of_arrival, int number_places, string name, string speed, int year_of_creating) :
	Airplane(number_places, name, speed, year_of_creating)
{
	this->set_lenght(lenght);
	this->set_date_of_arrival(date_of_arrival);
	this->set_date_of_shipping(date_of_arrival);
	this->set_time(time);
	this->set_status(status);
}

void Route::set_lenght(int lenght)
{
	this->lenght = lenght;
}

void Route::set_time(int time)
{
	this->time = time;
}

void Route::set_status(string status)
{
	this->status = status;
}

void Route::set_date_of_shipping(string date_of_shipping)
{
	this->date_of_shipping = date_of_shipping;
}

void Route::set_date_of_arrival(string date_of_arrival)
{
	this->date_of_arrival = date_of_arrival;
}

int Route::get_lenght()
{
	return this->lenght;
}

int Route::get_time()
{
	return this->time;
}

string Route::get_status()
{
	return this->status;
}

string Route::get_date_of_shipping()
{
	return this->date_of_shipping;
}

string Route::get_date_of_arrival()
{
	return this->date_of_arrival;
}
