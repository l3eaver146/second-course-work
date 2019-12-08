#pragma once
#include "Header.h"
#include "Airplane.h"
class Place :public virtual Airplane
{
protected:
	int number_of_place;
	string name_of_class;
public:
	Place() {}
	Place(int number_of_place, string name_of_class, int number_places, string name, string speed, int year_of_creating);
	void set_number_of_place(int number_of_place);
	void set_name_of_class(string name_of_class);
	int get_numebr_of_place();
	string get_name_of_class();
	friend std::ifstream& operator>> (std::ifstream& in, Place &Place);
	friend std::ostream& operator<< (std::ostream& out, const Place &Place);
	~Place() {}
};
