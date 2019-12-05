#include "Header.h"
#include "Place.h"
int Place::get_numebr_of_place() {
	return this->number_of_place;
}
string Place::get_name_of_class() {
	return this->name_of_class;
}
void Place::set_name_of_class(string name_of_class) {
	this->name_of_class = name_of_class;
}
Place::Place(int number_of_place, string name_of_class, int number_places, string name, string speed, int year_of_creating) :
	Airplane(number_places, name, speed, year_of_creating)
{
	this->set_number_of_place(number_of_place);
	this->set_name_of_class(name_of_class);
}
void Place::set_number_of_place(int number_of_place) {
	this->number_of_place = number_of_place;
}