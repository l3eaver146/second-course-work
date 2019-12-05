#include "Header.h"
#include "Airplane.h"
Airplane::Airplane(int number_places, string name, string speed, int year_of_creating)
{
	this->set_number_places(number_places);
	this->set_name(name);
	this->set_year_of_creating(year_of_creating);
	this->set_speed(speed);
}

int Airplane::get_number_places()
{
	return this->number_places;
}

string Airplane::get_name()
{
	return this->name;
}

string Airplane::get_speed()
{
	return this->speed;
}

int Airplane::get_year_of_creating()
{
	return this->year_of_creating;
}

void Airplane::set_year_of_creating(int year_of_creating)
{
	this->year_of_creating = year_of_creating;
}

void Airplane::set_name(string name)
{
	this->name = name;
}

void Airplane::set_speed(string speed)
{
	this->speed = speed;
}

void Airplane::set_number_places(int number_places)
{
	this->number_places = number_places;
}
