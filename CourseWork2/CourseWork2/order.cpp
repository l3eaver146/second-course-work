#include "order.h"

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

int order::get_numebr_of_places()
{
	return this->number_of_places;
}

int order::get_numebr_of_order()
{
	return this->number_of_order;
}
