#pragma once
#include "Header.h"
#include "Order.h"
#include "List.h"
template<>
class List <Order>
{
private:
	Line<Order>* begin;
	Line<Order>* end; //��������� �� ����� ������
	int count; //���������� ���������
public:
	List(); //����������� ��� ����������
	void push(const Order&); //�������� ������� � ������
	void pushBack(const Order&); //�������� ������� � �����
	Order dellOne(); //������� ������� � ������
	Order dellOneBack(); //������� ������� � �����
	void dellAll();  //������� ��� ��������
	int getCount();  //�����, ������������ ���� count
	Order dellPoint(Line<Order>*);//�������� ��������� ��������
	void show_users(); //�����, ��������� ��� �������� ������ � ������
	void showBack(); //�����, ��������� ��� �������� ������ � �����
	Line<Order>* operator [] (int); //���������� ��������� []
	void readFileOrder(string);  //������ ������ �� �����
	void writeFileOrder(string); //������ ������ � ����
	bool isEmpty(); //�����, ����������� ������ �� �������    
	bool check_order_data(string, string);
	void writeEndFileOrder(string filename, Users obj);
	~List(); //���������� ��� ����������
};



