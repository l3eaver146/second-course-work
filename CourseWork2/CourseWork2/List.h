#pragma once
#include "Header.h"

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
	void show(); //метод, вывод€щий все элемента списка с начала
	void showBack(); //метод, вывод€щий все элемента списка с конца
	Line<T>* operator [] (int); //перегрузка оператора []
	void readFile(string);  //чтение данных из файла
	void writeFile(string); //запись данных в файл
	bool isEmpty(); //метод, провер€ющий список на пустоту    
	~List(); //деструктор без параметров
};
