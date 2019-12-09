#include "Header.h"
#include "IncludeClasses.h"
#include "InludeTemplates.h"


static void menu_user() {
	cout << "Здравствуйте , пользователь!" << endl;
	cout << "1 - Посмотреть доступные рейсы " << endl;
	cout << "2 - Оформить заказ " << endl;
	cout << "3 - Посмотреть ваши заказы " << endl;
	cout << "0 - Вернуться назад " << endl;
}
static void check(int& n) {
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
static void work_user() {
	
}