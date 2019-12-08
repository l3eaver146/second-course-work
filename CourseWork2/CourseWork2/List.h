#pragma once
#include "Header.h"
#include "IncludeClasses.h"

/*universal list template*/
template<class T>
struct Line
{
	T obj; //�������
	Line<T>* next; //��������� �� ��������� �������
	Line<T>* prev; //��������� �� ����������� �������
};

template<class T>
class List
{
private:
	Line<T>* begin;
	Line<T>* end; //��������� �� ����� ������
	int count; //���������� ���������
public:
	List(); //����������� ��� ����������
	void push(const T&); //�������� ������� � ������
	void pushBack(const T&); //�������� ������� � �����
	T dellOne(); //������� ������� � ������
	T dellOneBack(); //������� ������� � �����
	void dellAll();  //������� ��� ��������
	int getCount();  //�����, ������������ ���� count
	T dellPoint(Line<T>*);//�������� ��������� ��������
	void show_users(); //�����, ��������� ��� �������� ������ � ������
	void showBack(); //�����, ��������� ��� �������� ������ � �����
	Line<T>* operator [] (int); //���������� ��������� []
	void readFileusers(string);  //������ ������ �� �����
	void writeFile(string); //������ ������ � ����
	bool isEmpty(); //�����, ����������� ������ �� �������    
	bool check_user_data(string, string);
	bool check_on_copy(string);
	void writeEndFileusers(string filename, Users obj);
	~List(); //���������� ��� ����������
};

/*for class order*/
template<>
struct Line<Order>
{
	Order obj; //�������
	Line<Order>* next; //��������� �� ��������� �������
	Line<Order>* prev; //��������� �� ����������� �������
};
template<>
class List<Order> {
private:
	Line<Order>* begin;
	Line<Order>* end; //��������� �� ����� ������
	int count; //���������� ���������
public:
	List();
	~List();
	void push(const Order&); //�������� ������� � ������
	void dellAll();  //������� ��� ��������
	int getCount();  //�����, ������������ ���� count
	//Order dellPoint(Line<Order>*);//�������� ��������� ��������
	void show_orders(); //�����, ��������� ��� �������� ������ � ������
	void readFile(string);  //������ ������ �� �����
	void writeFileOrder(string); //������ ������ � ����
	bool isEmpty(); //�����, ����������� ������ �� �������    
	void writeEndFileOrder(string filename, Order obj);
};
