#include "Header.h"
#include "IncludeClasses.h"
#include "InludeTemplates.h"


static void menu_user() {
	cout << "������������ , ������������!" << endl;
	cout << "1 - ���������� ��������� ����� " << endl;
	cout << "2 - �������� ����� " << endl;
	cout << "3 - ���������� ���� ������ " << endl;
	cout << "0 - ��������� ����� " << endl;
}
static void check(int& n) {
	while (true) {
		cin >> n;
		if (cin.get() == '\n') {
			break;//�������� �� ������������ �������� ������
		}
		else {
			cin.clear();
			cin.ignore(256, '\n');//������������ ����������� ����� 
			cout << "������������ ����, ��������� ������� \n Enter parametr again ";
		}//���� ������ �� ������������� ����, �� �������� �� ������
	}
}
static void work_user() {
	
}