#include "header.h"
#include "order.h"
#include "airplane.h"
#include "place.h"
#include "route.h"
order::order(int price, int number_of_places, int number_of_order, int number_places, string name, string speed, int year_of_creating, int number_of_place, string name_of_class, int lenght, int time, string status, string date_of_shipping, string date_of_arrival) :
	airplane(number_places, name, speed, year_of_creating),
	place(number_of_place, name_of_class, number_of_places, name, speed, year_of_creating),
	route(lenght, time, status, date_of_shipping, date_of_arrival, number_places, name, speed, year_of_creating)
 {
	this->set_price(price);
	this->set_number_of_places(number_of_places);
	this->set_number_of_order(number_of_order);
}

void order::set_price(int price)
{
	this->price = price;
}

void order::set_number_of_places(int number_of_places)
{
	this->number_of_places = number_of_places;
}

void order::set_number_of_order(int number_of_order)
{
	this->number_of_order = number_of_order;
}

int order::get_price()
{
	return this->price;
}

int order::get_number_of_places()
{
	return this->number_of_places;
}

int order::get_number_of_order()
{
	return this->number_of_order;
}
