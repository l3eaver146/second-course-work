#pragma once
#include "Header.h"
void check(int& n) {
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