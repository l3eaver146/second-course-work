#include "Header.h"
#include "Order.h"
#include "Airplane.h"
#include "Place.h"
#include "Route.h"
Order::Order(int price, int number_of_places, int number_of_order, int number_places, string name, string speed, int year_of_creating, int number_of_place, string name_of_class, int lenght, int time, string status, string date_of_shipping, string date_of_arrival,string departs_contry,string arrival_contry) :
	Airplane(number_places, name, speed, year_of_creating),
	Place(number_of_place, name_of_class, number_of_places, name, speed, year_of_creating),
	Route(lenght, time, status, date_of_shipping, date_of_arrival, number_places, name, speed, year_of_creating)
{
	this->set_price(price);
	this->set_number_of_places(number_of_places);
	this->set_number_of_order(number_of_order);
}

void Order::set_price(int price)
{
	this->price = price;
}

void Order::set_number_of_places(int number_of_places)
{
	this->number_of_places = number_of_places;
}

void Order::set_number_of_order(int number_of_order)
{
	this->number_of_order = number_of_order;
}

string Order::get_departs_country()
{
	return this->departs_contry;
}

string Order::get_arrival_country()
{
	return this->arrival_contry;
}

void Order::set_departs_country(string departs_country)
{
	this->departs_contry = departs_contry;
}

void Order::set_arrival_country(string arrival_country)
{
	this->arrival_contry = arrival_contry;
}

int Order::get_price()
{
	return this->price;
}

int Order::get_number_of_places()
{
	return this->number_of_places;
}

int Order::get_number_of_order()
{
	return this->number_of_order;
}

void Order::show_data_order()
{
	cout << "Краткая информация о вашем заказе :" << endl;
	cout << "Дата отправления : " << get_date_of_shipping()<<endl;
	cout << "Дата прибытия : " << get_date_of_arrival() << endl;
	cout << "Количество забронированных мест : " << get_number_of_places() << endl;
	cout << "Номер заказа : " << get_number_of_order() << endl;
	cout << "Страна отправления : " << get_departs_country() << endl;
	cout << "Страна прибытия : " << get_arrival_country()<< endl;
}
