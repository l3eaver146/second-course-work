#pragma once
#include "Header.h"
#include "Users.h"
#include "Order.h"

/*universal list template*/
template<class T>
struct Line
{
	T obj; //элемент
	Line<T>* next; //указатель на следующий элемент
	Line<T>* prev; //указатель на предыдующий элемент
};

template<class T>
class List
{
private:
	Line<T>* begin;
	Line<T>* end; //указатель на конец списка
	int count; //количество элементов
public:
	List(); //конструктор без параметров
	void push(const T&); //добавить элемент в начало
	void pushBack(const T&); //добавить элемент в конец
	T dellOne(); //удалить элемент с начала
	T dellOneBack(); //удалить элемент с конца
	void dellAll();  //удалить все элементы
	int getCount();  //метод, возвращающий поле count
	T dellPoint(Line<T>*);//удаление заданного элемента
	void showBack(); //метод, выводящий все элемента списка с конца
	void readFile(string fileName);
	Line<T>* operator [] (int); //перегрузка оператора []
	void writeFile(string); //запись данных в файл
	bool isEmpty(); //метод, проверяющий список на пустоту    
	~List(); //деструктор без параметров
};

/*specialized for Users*/
template<>
struct Line<Users>
{
	Users obj; //элемент
	Line<Users>* next; //указатель на следующий элемент
	Line<Users>* prev; //указатель на предыдующий элемент
};

template<>
class List<Users>
{
private:
	Line<Users>* begin;
	Line<Users>* end; //указатель на конец списка
	int count; //количество элементов
public:
	List(); //конструктор без параметров
	void push(const Users&); //добавить элемент в начало
	void pushBack(const Users&); //добавить элемент в конец
	int getCount();  //метод, возвращающий поле count
	void edit_by_login(string);
	Users dellPoint(Line<Users>*);//удаление заданного элемента
	void show_users(); //метод, выводящий все элемента списка с начала
	void readFile(string);  //чтение данных из файла
	void writeFile(string); //запись данных в файл    
	bool check_user_data(string, string,string&);
	bool check_on_copy(string);
	void writeEndFileusers(string filename, Users obj);
	~List(); //деструктор без параметров
};

/*for orders*/

template<>
struct Line<Order>
{
	Order obj; //элемент
	Line<Order>* next; //указатель на следующий элемент
	Line<Order>* prev; //указатель на предыдующий элемент
};

template<>
class List<Order>
{
private:
	Line<Order>* begin;
	Line<Order>* end; //указатель на конец списка
	int count; //количество элементов
public:
	void show_flights();
	List(); //конструктор без параметров
	void push(const Order&); //добавить элемент в начало
	void pushBack(const Order&); //добавить элемент в конец
	int getCount();  //метод, возвращающий поле count
	Order dellPoint(Line<Order>*);//удаление заданного элемента
	void readFileFlights(string);
	void writeFileFlights(string);
	void readFileBO(string);  //чтение данных из файла business
	void readFileEO(string); //econom
	void writeFileBO(string); //запись данных в файл    
	Line<Order>* operator [] (int);
	void writeFileEO(string);
	void writeEndFileBO(string,Order); //запись данных в файл    
	void writeEndFileEO(string, Order &);
	void writeEndFileFlights(string filename, Order obj);
	void edit_flight(string);
	Order search_by_flight(string);
	void show_orders_by_login(string);
	int return_index_of_order(string flight,string login,int number_of_ticket );
	//Order dell_by_ticketnumber_and_login(string login,int);
	~List(); //деструктор без параметров
};


/*Methods*/
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

template<class T>
inline void List<T>::readFile(string fileName)
{
	ifstream fin(fileName, ios::in);
	Users temp;
	while (!fin.eof()) {
		fin >> temp;
		this->push(temp);
	}
	fin.close();
}

/*for users*/
inline List<Users>::List()
{
	count = 0;
	begin = NULL;
	end = NULL;

}
inline void List<Users>::push(const Users& obj)
{
	count++;
	Line<Users>* temp = new Line<Users>;
	temp->next = NULL;
	Line<Users>* current = nullptr;
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
inline void List<Users>::readFile(string fileName)
{
	ifstream fin(fileName, ios::in);
	Users temp;
	while (!fin.eof()) {
		fin >> temp;
		this->push(temp);
	}
	fin.close();
}
inline bool List<Users>::check_user_data(string login, string password,string &root)
{
	int steps = 0;
	bool res = false;
	Line<Users>* current = nullptr;
	current = begin;
	while (current != NULL) {
		if ((current->obj.get_login() == login) && (current->obj.get_password() == password)) {
			root=current->obj.get_root();
			res = true;
			break;
		}
		current = current->next;
	}
	return res;
}
inline bool List<Users>::check_on_copy(string login)
{
	bool res = true;
	Line <Users>* current = begin;
	while (current != NULL) {
		if (current->obj.get_login() == login) {
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
inline void List<Users>::writeEndFileusers(string filename, Users obj)
{
	fstream add(filename, ios::app);
	add <<endl<< obj.get_login() << " " << obj.get_password() << " " << obj.get_root();
	add.close();
}
inline void List<Users>::show_users()
{
	Line<Users>* current = nullptr;
	current = begin;
	cout<<current->obj;
	while (current->next != NULL)
	{
		current = current->next;
		cout<<current->obj;
	}
}
inline void List<Users>::pushBack(const Users& obj)
{
	Line<Users>* current = nullptr;
	Line<Users>* temp = new Line<Users>;
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
inline Users List<Users>::dellPoint(Line<Users>* obj){
	Line<Users>* temp, * tempn, data;
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
inline int List<Users>::getCount()
{
	return this->count;
}
inline void List<Users>::edit_by_login(string login) {
	int steps = 0;
	Line<Users>* current = nullptr;
	current = begin;
	while (current != NULL) {
		if ((current->obj.get_login() == login)) {
			steps++;
			current->obj.set_root("admin");
			break;
		}
		current = current->next;
	}
	if (steps == 0) {
		cout << "Пользователя с таким логином не существует" << endl;
	}
	else cout << "Права успешно изменены!" << endl;
}
inline void List<Users>::writeFile(string fileName)
{
	ofstream fout(fileName, ios::out);
	Line<Users>* current = nullptr;
	current = begin;
	int i = 0;
	while (current != NULL)
	{
		fout << current->obj;
		if (i < count - 1) {
			fout << endl;
		}
		current = current->next;
		i++;
	}
	fout.close();
}
inline List<Users>::~List()
{
	Line<Users>* tmp = nullptr;
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

/*for orders*/
inline List<Order>::List()
{
	count = 0;
	begin = NULL;
	end = NULL;

}
inline void List<Order>::push(const Order& obj)
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
inline void List<Order>::pushBack(const Order&)
{
}
inline void List<Order>::readFileEO(string fileName)
{
	ifstream fin(fileName, ios::in);
	Order temp;
	int i,j;
	string t1,t2,t3,t4, t11, t12, t13, t14,t6,t16,t5,t15,t7,t8,t9,t10,t17;
	while (!fin.eof()) {
		fin >> t1>>t2>>t3>>t4>>t5>>t6>>t7>>t8>>t9>>t10>>t11>>t12>>t13>>t14>>t15>>i>>j>>t16>>t17;
		temp.set_flight(t1);
		temp.set_departs_contry(t2);
		temp.set_arrive_contry(t3);
		temp.set_departs_city(t4);
		temp.set_arrival_city(t5);
		temp.set_date_of_shipping(t6);
		temp.set_date_of_arrival(t7);
		temp.set_surname(t8);
		temp.set_name(t9);
		temp.set_patronimyc(t10);
		temp.set_passport_number(t11);
		temp.set_status(t12);
		temp.set_location(t13);
		temp.set_porthole(t14);
		temp.set_press(t15);
		temp.set_number_of_ticket(i);
		temp.set_price(t16);
		temp.set_login(t17);
		temp.set_number_of_place(j);
		this->push(temp);
	}
	fin.close();
}
inline Order List<Order>::dellPoint(Line<Order>* obj)
{
	Line<Order>* temp, * tempn, data;
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
void List<Order>::writeFileEO(string fileName)
{
	ofstream fout(fileName, ios::out);
	Line<Order>* current = nullptr;
	current = begin;
	int i = 0;
	while (current->next != NULL)
	{
		fout << current->obj;
		i++;
		current = current->next;
		if (i < count - 1) {
			fout << endl;
		}
	}
	fout.close();
}
void List<Order>::writeEndFileEO(string fileName, Order &obj)
{
	ofstream fout(fileName, ios::app);
	fout <<endl<< obj.get_flight() << " "
		<< obj.get_departs_contry() << " "
		<< obj.get_arrive_contry() << " "
		<< obj.get_departs_city() << " "
		<< obj.get_arrival_city() << " "
		<< obj.get_date_of_shipping() << " "
		<< obj.get_date_of_arrival() << " "
		<< obj.get_surname() << " "
		<< obj.get_name() << " "
		<< obj.get_patronimyc() << " "
		<< obj.get_passport_number() << " "
		<< obj.get_status() << " "
		<< obj.get_location() << " "
		<< obj.get_porthole() << " "
		<< obj.get_press() << " "
		<< obj.get_number_of_ticket()<<" "
		<<obj.get_number_of_place()<<" "
		<< obj.get_price() << " "
		<< obj.get_login();
	fout.close();
}
inline List<Order>::~List()
{
	Line<Order>* tmp = nullptr;
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
void List<Order>::readFileFlights(string fileName)
{
	ifstream fin(fileName, ios::in);
	Order temp;
	string ar_contry, ar_city, dep_contry, dep_city, number, date_a, date_d;
	while (!fin.eof()) {
		fin >> number >> dep_contry >> ar_contry >> dep_city >> ar_city >> date_d >> date_a;
		temp.set_arrival_city(ar_city);
		temp.set_departs_contry(dep_contry);
		temp.set_departs_city(dep_city);
		temp.set_flight(number);
		temp.set_arrive_contry(ar_contry);
		temp.set_date_of_shipping(date_d);
		temp.set_date_of_arrival(date_a);
		this->push(temp);
	}
	fin.close();
}
void List<Order>::writeEndFileFlights(string filename, Order obj)
{
	fstream add(filename, ios::app);
	add <<endl<< obj.get_flight() << " "
		<< obj.get_departs_contry() << " "
		<< obj.get_arrive_contry() << " "
		<< obj.get_departs_city() << " "
		<< obj.get_arrival_city() << " "
		<< obj.get_date_of_shipping() << " "
		<< obj.get_date_of_arrival();
}
inline void List<Order>::edit_flight(string flight)
{
	int index = 0;
	Line<Order>* current = nullptr;
	current = begin;
	while (current != NULL)
	{
		if (current->obj.get_flight() == flight)
		{
			index++;
			bool flag = true;
			int cho = 0;
			while (flag) {
				cout << "Что вы хотите изменить?" << endl;
				cout << "1 - Дату отправления " << endl;
				cout << "2 - Дату прибытия " << endl;
				cout << "0 - Назад " << endl;
				check(cho);
				switch (cho)
				{
				case 1: {
					string temp;
					cout << "Введите новую дату отправления : ";
					cin >> temp;
					current->obj.set_date_of_shipping(temp);
					break;
				}
				case 2: {
					string temp;
					cout << "Введите новую дату прибытия : ";
					cin >> temp;
					current->obj.set_date_of_arrival(temp);
					break;
				}
				case 0: {
					flag = false;
					break;
				}
				default: {
					cout << "Нет такого варианта!" << endl;
					break;
				}
				}
			}
		}
		current = current->next;
	}
	if (index == 0)
	{
		cout << "Нет рейса с таким номером!" << endl;
	}
}
inline Order List<Order>::search_by_flight(string flight)
{
	int index = 0;
	Line<Order>* current = nullptr;
	current = end;
	while (current != NULL)
	{
		if (current->obj.get_flight() == flight)
		{
			index++;
			return current->obj;
		}
		else {
			current = current->prev;
		}
	}
	if (index == 0)
	{
		cout << "Нет рейса с таким номером!" << endl;
	}
}
inline void List<Order>::show_orders_by_login(string login)
{
	int index = 0;
	Line<Order>* current = nullptr;
	current = begin;
	cout << "\t\tВаши заказы : " << endl;
	while (current!=NULL)
	{
		if (current->obj.get_login() == login)
		{
			current->obj.show_order_data();
			index++;
		}
		current = current->next;
	}
	if (index == 0)
	{
		cout << "У вас нет заказов ! " << endl;
	}
}
inline int List<Order>::return_index_of_order(string flight,string login, int number_of_ticket)
{
	int index = 0;
	Line<Order>* current = nullptr;
	current = begin;
	while (current->next != NULL)
	{
		if (current->obj.get_login() == login && current->obj.get_number_of_ticket()==number_of_ticket&&current->obj.get_flight()==flight)
		{
			return index;
		}
		current = current->next;
		index++;
	}
	return -1;
}
//inline Order List<Order>::dell_by_ticketnumber_and_login(string login,int number_of_ticket ){
	/*int index = 0;
	Line<Order>* current = nullptr;
	current = end;
	while (current != NULL)
	{
		if (current->obj.get_login() == login && current->obj.get_number_of_ticket== number_of_ticket)
		{
			index++;
			return current->obj;
		}
		else {
			current = current->prev;
		}
	}
	if (index == 0)
	{
		cout << "Нет заказа с такими параметрами!" << endl;
	}
}*/
void List<Order>::writeFileFlights(string fileName)
{
	ofstream fout(fileName, ios::out);
	int i = 0;
	Line<Order>* current = nullptr;
	current = begin;
	while (current!= NULL)
	{
		fout << current->obj.get_flight() << " "
			<< current->obj.get_departs_contry() << " "
			<< current->obj.get_arrive_contry() << " "
			<< current->obj.get_departs_city() << " "
			<< current->obj.get_arrival_city() << " "
			<< current->obj.get_date_of_shipping() << " "
			<< current->obj.get_date_of_arrival();
		if (i < count - 1) {
			fout << endl;
		}
		current = current->next;
		i++;
	}
	fout.close();
}
void List<Order>::show_flights()
{
	Line<Order>* current = nullptr;
	current = begin;
	cout << "Доступные рейсы : " << endl;
	current->obj.show_flight();
	while (current->next != NULL)
	{
		current = current->next;
		current->obj.show_flight();
	}
}
inline Line<Order>* List<Order>::operator[](int id)
{
	Line<Order>* current = nullptr;
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
void List<Order>::writeEndFileBO(string filename, Order obj)
{
	ofstream fout(filename, ios::app);
		fout << endl<<obj.get_flight() << " "
			<< obj.get_departs_contry() << " "
			<< obj.get_arrive_contry() << " "
			<< obj.get_departs_city() << " "
			<< obj.get_arrival_city() << " "
			<< obj.get_date_of_shipping() << " "
			<< obj.get_date_of_arrival() << " "
			<< obj.get_surname() << " "
			<< obj.get_name() << " "
			<< obj.get_patronimyc() << " "
			<< obj.get_passport_number() << " "
			<< obj.get_status() << " "
			<< obj.get_bar() << " "
			<< obj.get_staff() << " "
			<< obj.get_tv() << " "
			<< obj.get_food() << " "
			<< obj.get_air_conditioning() << " "
			<< obj.get_number_of_ticket() << " "
			<< obj.get_number_of_place() << " "
			<< obj.get_price() << " "
			<< obj.get_login();
	fout.close();
}
inline void List<Order>::readFileBO(string filename)
{
	ifstream fin(filename, ios::in);
	Order temp;
	int i, j;
	string t1, t2, t3, t4, t11, t12, t13, t14, t6, t16, t5, t18,t19,t15, t7, t8, t9, t10, t17;
	while (!fin.eof()) {
		fin >> t1 >> t2 >> t3 >> t4 >> t5 >> t6 >> t7 >> t8 >> t9 >> t10 >> t11 >> t12 >> t13 >> t14 >> t15>>t18>>t19 >> i >> j >> t16 >> t17;
		temp.set_flight(t1);
		temp.set_departs_contry(t2);
		temp.set_arrive_contry(t3);
		temp.set_departs_city(t4);
		temp.set_arrival_city(t5);
		temp.set_date_of_shipping(t6);
		temp.set_date_of_arrival(t7);
		temp.set_surname(t8);
		temp.set_name(t9);
		temp.set_patronimyc(t10);
		temp.set_passport_number(t11);
		temp.set_status(t12);
		temp.set_bar(t13);
		temp.set_staff(t14);
		temp.set_tv(t15);
		temp.set_food(t18);
		temp.set_air_conditioning(t19);
		temp.set_number_of_ticket(i);
		temp.set_price(t16);
		temp.set_login(t17);
		temp.set_number_of_place(j);
		this->push(temp);
	}
	fin.close();
}
inline void List<Order>::writeFileBO(string filename)
{
	int i = 0;
	ofstream fout(filename, ios::out);
	Line<Order>* current = nullptr;
	current = end;
	while (current->next != NULL)
	{
		fout << current->obj.get_flight() << " "
			<< current->obj.get_departs_contry() << " "
			<< current->obj.get_arrive_contry() << " "
			<< current->obj.get_departs_city() << " "
			<< current->obj.get_arrival_city() << " "
			<< current->obj.get_date_of_shipping() << " "
			<< current->obj.get_date_of_arrival() << " "
			<< current->obj.get_surname() << " "
			<< current->obj.get_name() << " "
			<< current->obj.get_patronimyc() << " "
			<< current->obj.get_passport_number() << " "
			<< current->obj.get_status() << " "
			<< current->obj.get_bar()<<" "
			<< current->obj.get_staff()<<" "
			<< current->obj.get_tv()<<" "
			<< current->obj.get_food()<<" "
			<< current->obj.get_air_conditioning()<<" "
			<<current->obj.get_number_of_ticket()<<" "
			<<current->obj.get_number_of_place()<<" "
			<< current->obj.get_price() << " "
			<< current->obj.get_login();
		if (i < count - 1) {
			fout << endl;
		}
		i++;
		current = current->prev;
	}
	fout.close();
}