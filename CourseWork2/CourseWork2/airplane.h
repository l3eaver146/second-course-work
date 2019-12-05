#pragma once

#include "Header.h"
class Airplane
{
protected:
	int number_places;
	string name;
	string speed;
	int year_of_creating;
public:
	Airplane() {}
	Airplane(int number_places, string name, string speed, int year_of_creating);
	int get_number_places();
	string get_name();
	string get_speed();
	int get_year_of_creating();
	void set_year_of_creating(int year_of_creating);
	void set_name(string name);
	void set_speed(string speed);
	void set_number_places(int number_places);
	~Airplane() {}
};

