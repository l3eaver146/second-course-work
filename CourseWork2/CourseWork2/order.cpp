#include "Order.h"

Order::Order()
{
}

Order::Order(int number_of_ticket, string status, string departs_contry, string arrive_contry, string food, string air_conditioning, string tv, string bar, string staff , string departs_city, string arrival_city, string flight,string price,string date_of_arrival,string date_of_shipping,int number_of_place, string login, string password, string root,string name, string surname, string patronimyc, string passport_number)
:Air_ticket(number_of_ticket,status,departs_contry,arrive_contry),Business_class(food,bar,air_conditioning,tv,staff),Passenger_data(name,surname,patronimyc,passport_number),Users(login, password, root)
{/*Для билетов business класса*/
	this->arrival_city = arrival_city;
	this->date_of_arrival = date_of_arrival;
	this->date_of_shipping = date_of_shipping;
	this->departs_city = departs_city;
	this->price = price;
	this->number_of_place = number_of_place;
	this->flight = flight;
}

Order::Order(int number_of_ticket, string status, string departs_contry, string arrive_contry, string location, string press, string porthole, string departs_city, string arrival_city, string flight, string price, string date_of_arrival, string date_of_shipping, int number_of_place, string login, string password, string root,string name,string surname, string patronimyc, string passport_number)
	:Air_ticket(number_of_ticket, status, departs_contry, arrive_contry),Econom_class(press,porthole,location),Passenger_data(name, surname, patronimyc, passport_number), Users(login, password, root)
{
	this->arrival_city = arrival_city;
	this->date_of_arrival = date_of_arrival;
	this->date_of_shipping = date_of_shipping;
	this->departs_city = departs_city;
	this->flight = flight;
	this->price = price;
	this->number_of_place = number_of_place;
}

void Order::set_number_of_place(int number_of_place)
{
	this->number_of_place = number_of_place;
}

void Order::set_date_of_shipping(string date_of_shipping)
{
	this->date_of_shipping = date_of_shipping;
}

void Order::set_date_of_arrival(string date_of_arrival)
{
	this->date_of_arrival = date_of_arrival;
}

void Order::set_price(string price)
{
	this->price=price;
}

void Order::set_departs_city(string departs_city)
{
	this->departs_city = departs_city;
}

void Order::set_flight(string flight)
{
	this->flight = flight;
}

void Order::set_arrival_city(string arrival_city)
{
	this->arrival_city = arrival_city;
}

int Order::get_number_of_place()
{
	return this->number_of_place;
}

string Order::get_date_of_shipping()
{
	return this->date_of_shipping;
}

string Order::get_date_of_arrival()
{
	return this->date_of_arrival;
}

string Order::get_price()
{
	return this->price;
}

string Order::get_departs_city()
{
	return this->departs_city;
}

string Order::get_flight()
{
	return this->flight;
}

string Order::get_arrival_city()
{
	return this->arrival_city;
}

Order::~Order()
{
}
