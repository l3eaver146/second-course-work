#pragma once
#include "Air_ticket.h"
#include "Econom_class.h"
#include "Business_class.h"
#include "Passenger_data.h"
#include "Users.h"
class Order:public Econom_class,public Passenger_data,public Business_class,public Users
{
protected:
	int number_of_place;
	string date_of_shipping;
	string date_of_arrival;
	string price;
	string flight;
	string departs_city;
	string arrival_city;
public:
	Order();
	~Order();
	Order(int, string, string, string, string, string, string, string, string, string, string, string, string,string,string,int,string,string,string,string,string,string,string);/*��� ������� ������*/
	Order(int, string, string , string, string, string, string , string, string, string , string, string, string, int, string, string, string, string, string, string, string);/*��� ������ ������*/
	void set_number_of_place(int);
	void set_date_of_shipping(string);
	void set_date_of_arrival(string);
	void set_price(string);
	void set_departs_city(string);
	void set_flight(string);
	void set_arrival_city(string);
	int get_number_of_place();
	string get_date_of_shipping();
	string get_date_of_arrival();
	string get_price();
	string get_departs_city();
	string get_flight();
	string get_arrival_city();
};

