#pragma once
#include "Header.h"
void check(int& n) {
	while (true) {
		cin >> n;
		if (cin.get() == '\n') {
			break;//проверка на корректность вводимых данных
		}
		else {
			cin.clear();
			cin.ignore(256, '\n');//максимальное принимаемое число 
			cout << "некорректный ввод, повторите попытку \n Enter parametr again ";
		}//если данные не соответствуют типу, то сообщаем об ошибке
	}
}