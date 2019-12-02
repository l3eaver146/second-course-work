#pragma once
#include "header.h"
#include"airplane.h"
class place :public airplane {
protected:
	int number_of_place;
	string name_of_class;
public:
	place() {

	}
	void set_number_of_place(int number_of_place);
	void set_name_of_class(string name_of_class);
	int get_numebr_of_place();
	string get_name_of_class();
	~place() {

	}
};