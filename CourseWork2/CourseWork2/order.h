#pragma once
#include "header.h"
#include "place.h"
#include "route.h"
#include "airplane.h"

class order : public place, public route
{
protected:
	int price;
	int number_of_places;
	int number_of_order;
public:
	order() {}
	order(int price, int number_of_places, int number_of_order, int number_places, string name, string speed, int year_of_creating, int number_of_place, string name_of_class, int lenght, int time, string status, string date_of_shipping, string date_of_arrival);
	void set_price(int price);
	void set_number_of_places(int number_of_places);
	void set_number_of_order(int number_of_order);
	int get_price();
	int get_number_of_places();
	int get_number_of_order();
	~order() {}
};