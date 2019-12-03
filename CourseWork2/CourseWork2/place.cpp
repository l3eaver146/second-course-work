#include "header.h"
#include "place.h"
int place:: get_numebr_of_place() {
	return this->number_of_place;
}
string place::get_name_of_class(){
	return this->name_of_class;
}
void place::set_name_of_class(string name_of_class) {
	this->name_of_class = name_of_class;
}
place::place(int number_of_place, string name_of_class, int number_places, string name, string speed, int year_of_creating):
	airplane(number_places,name,speed,year_of_creating)
{
	this->set_number_of_place(number_of_place);
	this->set_name_of_class(name_of_class);
}
void place::set_number_of_place(int number_of_place) {
	this->number_of_place = number_of_place;
}