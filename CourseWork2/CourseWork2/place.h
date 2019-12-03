#pragma once
#include "header.h"
#include "airplane.h"
class place :public virtual airplane
{
protected:
	int number_of_place;
	string name_of_class;
public:
	place() {}
	place(int number_of_place, string name_of_class, int number_places, string name, string speed, int year_of_creating);
	void set_number_of_place(int number_of_place);
	void set_name_of_class(string name_of_class);
	int get_numebr_of_place();
	string get_name_of_class();
	~place() {}
};