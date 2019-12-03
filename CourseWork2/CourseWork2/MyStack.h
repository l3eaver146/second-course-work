#pragma once
#include<iostream>
#include<string>
#include<ctime>
#include <iomanip>

using namespace std;


template <typename T>
class Stack
{
private:
	T* stackPtr; // ��������� �� ����
	int size; // ������ �����
	T top; // ������� �����
public:
	Stack(int = 10);// �� ��������� ������ ����� ����� 10 ���������
	~Stack(); // ����������
	bool push(const T); // ��������� ������� � ����
	bool pop(); // ������� �� ����� �������
	void printStack();
};

// �����������
template <typename T>
Stack<T>::Stack(int s)
{
	size = s > 0 ? s : 10;   // ���������������� ������ �����
	stackPtr = new T[size]; // �������� ������ ��� ����
	top = -1; // �������� -1 ������� � ���, ��� ���� ����
}

// ����������
template <typename T>
Stack<T>::~Stack()
{
	delete[] stackPtr; // ������� ����
}

// ������� ������� ������  Stack ��� ��������� �������� � ����
// ������������ �������� - true, �������� ������� ���������
//                                    false, ������� � ���� �� ��������
template <typename T>
bool Stack<T>::push(const T value)
{
	if (top == size - 1)
		return false; // ���� �����

	top++;
	stackPtr[top] = value; // �������� ������� � ����

	return true; // �������� ���������� ��������
}

// ������� ������� ������  Stack ��� �������� �������� �� ����
// ������������ �������� - true, �������� ������� ���������
//                                    false, ���� ����
template <typename T>
bool Stack<T>::pop()
{
	if (top == -1)
		return false; // ���� ����

	stackPtr[top] = 0; // ������� ������� �� �����
	top--;

	return true; // �������� ���������� ��������
}

// ����� ����� �� �����
template <typename T>
void Stack<T>::printStack()
{
	for (int ix = size - 1; ix >= 0; ix--)
		cout << "|" << setw(4) << stackPtr[ix] << endl;
}