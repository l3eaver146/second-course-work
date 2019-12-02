#pragma once
#include"place.h"
#include"route.h"
class order :public virtual place, public virtual route {
	int price;
	int number_of_places;
	int number_of_order;
public:
	order() {

	}
	void set_price(int price);
	void set_number_of_places(int number_of_places);
	void set_number_of_order(int number_of_order);
	int get_price();
	int get_numebr_of_places();
	int get_numebr_of_order();
	~order() {

}
}