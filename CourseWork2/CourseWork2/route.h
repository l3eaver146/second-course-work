#pragma once
#include "header.h"
#include"airplane.h"
class route:public airplane {
protected:
	int lenght;
	int time;
	string status;
	string date_of_shipping;
	string date_of_arrival;
public:
	route() {

}
	~route() {

	}
	void set_lenght(int lenght);
	void set_time(int time);
	void set_status(string status);
	void set_date_of_shipping(string date_of_shipping);
	void set_date_of_arrival(string date_of_arrival);
	int get_lenght();
	int get_time();
	string get_status();
	string get_date_of_shipping();
	string get_date_of_arrival();
};