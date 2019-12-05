#pragma once
#include "Header.h"
#include "Airplane.h"
#include "Users.h"
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
	void show_users(); //метод, вывод€щий все элемента списка с начала
	void showBack(); //метод, вывод€щий все элемента списка с конца
	Line<T>* operator [] (int); //перегрузка оператора []
	void readFileusers(string);  //чтение данных из файла
	void writeFile(string); //запись данных в файл
	bool isEmpty(); //метод, провер€ющий список на пустоту    
	bool check_user_data(string, string);
	bool check_on_copy(string);
	void writeEndFileusers(string filename,Users obj);
	~List(); //деструктор без параметров
};

template<class T>
List<T>::List()
{
	count = 0;
	begin = NULL;
	end = NULL;
}

template<class T>
List<T>::~List()
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
void List<T>::push(const T& obj)
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
void List<T>::pushBack(const T& obj)
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
void List<T>::show_users()
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
void List<T>::showBack()
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
T List<T>::dellPoint(Line<T>* obj)
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
T List<T>::dellOne()
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
T List<T>::dellOneBack()
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
bool List<T>::isEmpty()
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
	int steps=0;
	bool res = false;
	Line<T>* current = nullptr;
	current = begin;
	while (current != NULL) {
		if ((current->obj.Users::get_login() == login) && (current->obj.Users::get_password() == password)) {
			res=true;
			break;
		}
		current = current->next;
	}
	return res;
}

template<class T>
inline bool List<T>::check_on_copy(string login)
{
	bool res=true;
	Line <T>* current=begin;
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
inline void List<T>::writeEndFileusers(string filename,Users obj)
{
	fstream add(filename, ios::app);
	add << obj.get_login() << " " << obj.get_password() << " "<<obj.get_root()<<endl;
	add.close();
} 

template<class T>
Line<T>* List<T>::operator[] (int id)
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
void List<T>::readFileusers(string fileName)
{
	ifstream fin(fileName,ios::in);
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
void List<T>::writeFile(string fileName)
{
	ofstream fout(fileName, ios::out);
	Line<T>* current = nullptr;
	current=end;
	while (current != NULL)
	{
		fout << current->obj.Users::get_login()<<" "<<
		current->obj.Users::get_password()<<" "<<
		current->obj.Users::get_root()<<
		endl;
		current = current->prev;
	}
	fout.close();
}

template<class T>
void List<T>::dellAll()
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
int List<T>::getCount()
{
	return this->count;
}
