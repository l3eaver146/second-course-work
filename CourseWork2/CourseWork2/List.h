#pragma once
#include "Header.h"

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
	void show(); //�����, ��������� ��� �������� ������ � ������
	void showBack(); //�����, ��������� ��� �������� ������ � �����
	Line<T>* operator [] (int); //���������� ��������� []
	void readFile(string);  //������ ������ �� �����
	void writeFile(string); //������ ������ � ����
	bool isEmpty(); //�����, ����������� ������ �� �������    
	~List(); //���������� ��� ����������
};
