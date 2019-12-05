#include "Header.h"
#include "List.h"

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
void List<T>::show()
{
	Line<T>* current = nullptr;
	current = end;
	cout << current->obj;
	while (current->prev != NULL)
	{
		current = current->prev;
		cout << current->obj;
	}
}
template<class T>
void List<T>::showBack()
{
	Line<T>* current = nullptr;
	current = begin;
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
void List<T>::readFile(string fileName)
{
	ifstream fin(fileName, ios::binary | ios::in);
	T temp;
	while (fin >> temp)
	{
		this->push(temp);
	}
	fin.close();
}
template<class T>
void List<T>::writeFile(string fileName)
{
	ofstream fout(fileName, ios::binary | ios_base::out);
	Line<T>* current = begin;
	while (current != NULL)
	{
		fout << current->obj;
		current = current->next;
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