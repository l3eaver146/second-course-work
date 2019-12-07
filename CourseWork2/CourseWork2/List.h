#pragma once
#include "Header.h"
#include "Users.h"
#include "Order.h"
template<class T>
struct Line
{
	T obj; //�������
	Line<T>* next; //��������� �� ��������� �������
	Line<T>* prev; //��������� �� ����������� �������
};

template<class T>/*universal list template*/
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

template<>/*for class order*/
class List<Order> {
private:
	Line<Order>* begin;
	Line<Order>* end; //��������� �� ����� ������
	int count; //���������� ���������
public:
	void pushOrder(const Order&); //�������� ������� � ������
	void dellAll();  //������� ��� ��������
	int getCount();  //�����, ������������ ���� count
	//Order dellPoint(Line<Order>*);//�������� ��������� ��������
	void show_orders(); //�����, ��������� ��� �������� ������ � ������
	void readFileOrder(string);  //������ ������ �� �����
	void writeFileOrder(string); //������ ������ � ����
	bool isEmpty(); //�����, ����������� ������ �� �������    
	void writeEndFileOrder(string filename, Order obj);
};