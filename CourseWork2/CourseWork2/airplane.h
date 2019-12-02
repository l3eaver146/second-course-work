#pragma once
#include "header.h"
class airplane
{
	protected:
	int number_places;
	string name;
	string speed;
	int year_of_creating;
public:
	airplane() {

	}
	int get_number_places();
	string get_name();
	string get_speed();
	int get_year_of_creating();
	void set_year_of_creating(int year_of_creating);
	void set_name(string name);
	void set_speed(string speed);
	void set_number_places(int number_places);
	~airplane() {

	}
};

