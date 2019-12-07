#include "List.h"
/*—тандартный шабон с методами дл€ класса Users*/
template<class T>
inline List<T>::List()
{
	count = 0;
	begin = NULL;
	end = NULL;

}

template<class T>
inline void List<T>::push(const T& obj)
{
	count++;
	Line<T>* temp = new Line<T>;
	temp->next = NULL;
	Line<T>* current = nullptr;
	temp->obj = obj;
	if (begin != NULL)
	{
		temp->prev = end;
		end->next = temp;
		end = temp;
		current = end;
	}
	else
	{
		temp->prev = NULL;
		begin = end = temp;
	}
}

template<class T>
inline void List<T>::pushBack(const T& obj)
{
	Line<T>* current = nullptr;
	Line<T>* temp = new Line<T>;
	temp->prev = NULL;
	current = NULL;
	temp->obj = obj;
	count++;
	if (begin != NULL)
	{
		begin->prev = temp;
		temp->next = begin;
		begin = temp;
		current = begin;
	}
	else
	{
		temp->next = NULL;
		begin = end = temp;
	}
}

template<class T>
inline T List<T>::dellOne()
{
	if (end == begin)
	{
		count--;
		Line<T> data;
		data.obj = end->obj;
		delete end;
		end = begin = NULL;
		return data.obj;
	}
	else {
		Line<T>* current = nullptr;
		count--;
		Line<T> data;
		current = end->prev;
		current->next = NULL;
		data.obj = end->obj;
		delete end;
		end = current;
		return data.obj;
	}
}

template<class T>
inline T List<T>::dellOneBack()
{
	if (end == begin)
	{
		count--;
		Line<T> data;
		data.obj = end->obj;
		delete end;
		end = begin = NULL;
		return data.obj;
	}
	else {
		Line<T>* current = nullptr;
		Line<T> data;
		count--;
		current = begin->next;
		current->prev = NULL;
		data.obj = end->obj;
		delete begin;
		begin = current;
		return data.obj;
	}
}

template<class T>
inline void List<T>::dellAll()
{
	Line<T>* tmp = nullptr;
	if (begin != NULL)
	{
		while (begin != NULL)
		{
			tmp = begin->next;
			delete begin;
			begin = tmp;
		}
	}
}

template<class T>
inline int List<T>::getCount()
{
	return this->count;
}

template<class T>
inline T List<T>::dellPoint(Line<T>* obj)
{
	Line<T>* temp, * tempn, data;
	count--;
	if (obj == begin && obj != end)
	{
		tempn = obj->next;
		tempn->prev = NULL;
		begin = tempn;
		data.obj = obj->obj;
		delete obj;
	}
	else if (obj == end && obj != begin)
	{
		temp = obj->prev;
		temp->next = obj->next;
		end = temp;
		data.obj = obj->obj;
		delete obj;
	}
	else if (obj == end && obj == begin)
	{
		temp = obj;
		data.obj = obj->obj;
		delete end;
		end = begin = NULL;
	}
	else
	{
		temp = obj->prev;
		tempn = obj->next;
		temp->next = tempn;
		tempn->prev = temp;
		data.obj = obj->obj;
		delete obj;
	}
	return data.obj;
}

template<class T>
inline Line<T>* List<T>::operator[](int id)
{
	Line<T>* current = nullptr;
	current = end;
	int index = 1;
	while (id != index)
	{
		if (current->prev != NULL)
		{
			current = current->prev;
		}
		index++;
	}
	return current;
}

template<class T>
inline void List<T>::readFileusers(string fileName)
{
	ifstream fin(fileName, ios::in);
	T temp;
	string login, password, root;
	while (!fin.eof()) {
		fin >> login >> password >> root;
		temp.Users::set_login(login);
		temp.Users::set_password(password);
		temp.Users::set_root(root);
		this->push(temp);
	}
	fin.close();
}

template<class T>
inline void List<T>::writeFile(string fileName)
{
	ofstream fout(fileName, ios::out);
	Line<T>* current = nullptr;
	current = end;
	while (current != NULL)
	{
		fout << current->obj.Users::get_login() << " " <<
			current->obj.Users::get_password() << " " <<
			current->obj.Users::get_root() <<
			endl;
		current = current->prev;
	}
	fout.close();
}

template<class T>
inline bool List<T>::isEmpty()
{
	if (begin != NULL)
	{
		return true;
	}
	else {
		return false;
	}
}

template<class T>
inline bool List<T>::check_user_data(string login, string password)
{
	int steps = 0;
	bool res = false;
	Line<T>* current = nullptr;
	current = begin;
	while (current != NULL) {
		if ((current->obj.Users::get_login() == login) && (current->obj.Users::get_password() == password)) {
			res = true;
			break;
		}
		current = current->next;
	}
	return res;
}

template<class T>
inline bool List<T>::check_on_copy(string login)
{
	bool res = true;
	Line <T>* current = begin;
	while (current != NULL) {
		if (current->obj.Users::get_login() == login) {
			res = false;
			break;
		}
		else {
			current = current->next;
			res = true;
		}
	}
	return res;
}

template<class T>
inline void List<T>::writeEndFileusers(string filename, Users obj)
{
	fstream add(filename, ios::app);
	add << obj.get_login() << " " << obj.get_password() << " " << obj.get_root() << endl;
	add.close();
}

template<class T>
inline List<T>::~List()
{
	Line<T>* tmp = nullptr;
	if (begin != NULL)
	{
		while (begin != NULL)
		{
			tmp = begin->next;
			delete begin;
			begin = tmp;
		}
	}
}

template<class T>
inline void List<T>::show_users()
{
	Line<T>* current = nullptr;
	current = begin;
	current->obj.Users::show_data_users();
	while (current->next != NULL)
	{
		current = current->next;
		current->obj.Users::show_data_users();
	}
}

template<class T>
inline void List<T>::showBack()
{
	Line<T>* current = nullptr;
	current = end;
	cout << current->obj << endl;
	while (current->next != NULL)
	{
		current = current->next;
		cout << current->obj << endl;
	}
}
/* —пециализированный шаблон дл€ работы с классом Order*/
 inline void List<Order>::show_orders()
{
	Line<Order>* current = nullptr;
	current = begin;
	current->obj.Order::show_data_order();
	while (current->next != NULL)
	{
		current = current->next;
		current->obj.Order::show_data_order();
	}
}
 inline void List<Order>::pushOrder(const Order& obj)
{
	count++;
	Line<Order>* temp = new Line<Order>;
	temp->next = NULL;
	Line<Order>* current = nullptr;
	temp->obj = obj;
	if (begin != NULL)
	{
		temp->prev = end;
		end->next = temp;
		end = temp;
		current = end;
	}
	else
	{
		temp->prev = NULL;
		begin = end = temp;
	}
}
 inline void List<Order>::readFileOrder(string fileName)
{
	ifstream fin(fileName, ios::in);
	Order temp;
	int number_of_order, lenght, time, number_of_places, price, number_places, number_of_place, year_of_creating = 0;
	string date_of_arrival, date_of_shipping, name_of_class, status, name, speed,departs_contry,arrival_contry;
	while (!fin.eof()) {
		fin >> number_places >> name >> speed >> number_of_place
			>> name_of_class >> lenght >> time >> status >> date_of_arrival
			>> date_of_shipping >> price >> number_of_places >> number_of_order
			>> arrival_contry >> departs_contry;
		temp.Order::set_date_of_arrival(date_of_arrival);
		temp.Order::set_date_of_shipping(date_of_shipping);
		temp.Order::set_lenght(lenght);
		temp.Order::set_name(name);
		temp.Order::set_name_of_class(name_of_class);
		temp.Order::set_number_of_order(number_of_order);
		temp.Order::set_number_of_place(number_of_place);
		temp.Order::set_number_of_places(number_of_places);
		temp.Order::set_number_places(number_of_places);
		temp.Order::set_price(price);
		temp.Order::set_speed(speed);
		temp.Order::set_status(status);
		temp.Order::set_time(time);
		temp.Order::set_year_of_creating(year_of_creating);
		temp.Order::set_arrival_country(arrival_contry);
		temp.Order::set_departs_country(departs_contry);
		this->pushOrder(temp);
	}
	fin.close();
}
 inline void List<Order>::writeFileOrder(string fileName)
{
	ofstream fout(fileName, ios::out);
	Line<Order>* current = nullptr;
	current = end;
	while (current != NULL)
	{
		fout << current->obj.Order::get_date_of_arrival() << " " <<
			current->obj.Order::get_date_of_shipping() << " " <<
			current->obj.Order::get_lenght() << " " <<
			current->obj.Order::get_name() << " " <<
			current->obj.Order::get_name_of_class() << " " <<
			current->obj.Order::get_number_of_order() << " " <<
			current->obj.Order::get_number_of_places() << " " <<
			current->obj.Order::get_number_places() << " " <<
			current->obj.Order::get_numebr_of_place() << " " <<
			current->obj.Order::get_price() << " " <<
			current->obj.Order::get_speed() << " " <<
			current->obj.Order::get_status() << " " <<
			current->obj.Order::get_time() << " " <<
			current->obj.Order::get_year_of_creating() << " " <<
			current->obj.Order::get_arrival_country() << " " <<
			current->obj.Order::get_departs_country() << " " <<
			endl;
		current = current->prev;
	}
	fout.close();
}
 inline void List<Order>::writeEndFileOrder(string filename, Order obj)
{
	fstream add(filename, ios::app);
	add << obj.Order::get_date_of_arrival() << " " <<
		obj.Order::get_date_of_shipping() << " " <<
		obj.Order::get_lenght() << " " <<
		obj.Order::get_name() << " " <<
		obj.Order::get_name_of_class() << " " <<
		obj.Order::get_number_of_order() << " " <<
		obj.Order::get_number_of_places() << " " <<
		obj.Order::get_number_places() << " " <<
		obj.Order::get_numebr_of_place() << " " <<
		obj.Order::get_price() << " " <<
		obj.Order::get_speed() << " " <<
		obj.Order::get_status() << " " <<
		obj.Order::get_time() << " " <<
		obj.Order::get_year_of_creating() << " " <<
		obj.Order::get_arrival_country()<<" "<<
		obj.Order::get_departs_country()<<
		endl;
	add.close();
}
