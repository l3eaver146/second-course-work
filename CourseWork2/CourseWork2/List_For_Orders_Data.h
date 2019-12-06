#pragma once
#include "Header.h"
#include "Order.h"
#include "List.h"
template<>
class List <Order>
{
private:
	Line<Order>* begin;
	Line<Order>* end; //указатель на конец списка
	int count; //количество элементов
public:
	List(); //конструктор без параметров
	void push(const Order&); //добавить элемент в начало
	void pushBack(const Order&); //добавить элемент в конец
	Order dellOne(); //удалить элемент с начала
	Order dellOneBack(); //удалить элемент с конца
	void dellAll();  //удалить все элементы
	int getCount();  //метод, возвращающий поле count
	Order dellPoint(Line<Order>*);//удаление заданного элемента
	void show_users(); //метод, вывод€щий все элемента списка с начала
	void showBack(); //метод, вывод€щий все элемента списка с конца
	Line<Order>* operator [] (int); //перегрузка оператора []
	void readFileOrder(string);  //чтение данных из файла
	void writeFileOrder(string); //запись данных в файл
	bool isEmpty(); //метод, провер€ющий список на пустоту    
	bool check_order_data(string, string);
	void writeEndFileOrder(string filename, Users obj);
	~List(); //деструктор без параметров
};



