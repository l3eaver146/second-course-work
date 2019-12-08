#pragma once

#include "Header.h"
#include "Place.h"
#include "Route.h"
#include "Airplane.h"

class Order : public Place, public Route
{
protected:
	string departs_contry;
	string arrival_contry;
	int price;
	int number_of_places;
	int number_of_order;
public:
	Order() {}
	Order(int price, int number_of_places, int number_of_order, int number_places, string name, string speed, int year_of_creating, int number_of_place, string name_of_class, int lenght, int time, string status, string date_of_shipping, string date_of_arrivalstring ,string departs_contry ,string arrival_contry);
	void set_price(int price);
	void set_number_of_places(int number_of_places);
	void set_number_of_order(int number_of_order);
	string get_departs_country();
	string get_arrival_country();
	void set_departs_country(string departs_country);
	void set_arrival_country(string arrival_country);
	int get_price();
	int get_number_of_places();
	int get_number_of_order();
	friend std::ifstream& operator>> (std::ifstream& in, Order& Order);
	friend std::ostream& operator<< (std::ostream& out, const Order& Order);
	~Order() {}
};