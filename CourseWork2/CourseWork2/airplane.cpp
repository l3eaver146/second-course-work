#include "header.h"
#include "airplane.h"
airplane::airplane(int number_places, string name, string speed, int year_of_creating)
{
	this->set_number_places(number_places);
	this->set_name(name);
	this->set_year_of_creating(year_of_creating);
	this->set_speed(speed);
}

int airplane::get_number_places()
{
	return this->number_places;
}

string airplane::get_name()
{
	return this->name;
}

string airplane::get_speed()
{
	return this->speed;
}

int airplane::get_year_of_creating()
{
	return this->year_of_creating;
}

void airplane::set_year_of_creating(int year_of_creating)
{
	this->year_of_creating = year_of_creating;
}

void airplane::set_name(string name)
{
	this->name = name;
}

void airplane::set_speed(string speed)
{
	this->speed = speed;
}

void airplane::set_number_places(int number_places)
{
	this->number_places = number_places;
}
