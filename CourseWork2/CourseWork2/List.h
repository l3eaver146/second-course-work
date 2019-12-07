#pragma once
#include "Header.h"
#include "Users.h"
#include "Order.h"
template<class T>
struct Line
{
	T obj; //элемент
	Line<T>* next; //указатель на следующий элемент
	Line<T>* prev; //указатель на предыдующий элемент
};

template<class T>/*universal list template*/
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
	void show_users(); //метод, вывод€щий все элемента списка с начала
	void showBack(); //метод, вывод€щий все элемента списка с конца
	Line<T>* operator [] (int); //перегрузка оператора []
	void readFileusers(string);  //чтение данных из файла
	void writeFile(string); //запись данных в файл
	bool isEmpty(); //метод, провер€ющий список на пустоту    
	bool check_user_data(string, string);
	bool check_on_copy(string);
	void writeEndFileusers(string filename, Users obj);
	~List(); //деструктор без параметров
};

template<>/*for class order*/
class List<Order> {
private:
	Line<Order>* begin;
	Line<Order>* end; //указатель на конец списка
	int count; //количество элементов
public:
	void pushOrder(const Order&); //добавить элемент в начало
	void dellAll();  //удалить все элементы
	int getCount();  //метод, возвращающий поле count
	//Order dellPoint(Line<Order>*);//удаление заданного элемента
	void show_orders(); //метод, вывод€щий все элемента списка с начала
	void readFileOrder(string);  //чтение данных из файла
	void writeFileOrder(string); //запись данных в файл
	bool isEmpty(); //метод, провер€ющий список на пустоту    
	void writeEndFileOrder(string filename, Order obj);
};