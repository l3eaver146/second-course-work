#include "List.cpp"

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
	string file_of_orders="Orders.txt";
	List <Order> list_of_orders;
	list_of_orders.readFileOrder(file_of_orders);
	bool flag = true;
	while (flag == true) {
		menu_user();
		int choise;
		check(choise);
		switch (choise)
		{
		case 1:
		{
			list_of_orders.show_orders();
		}
		case 2:
		{
			cout << "� ������ ���������� !";
			system("cls");
			break;
		}
		case 3:
		{
			cout << "� ������ ���������� !";
			system("cls");
			break;
		}
		case 0:
		{
			flag = false;
			break;
		}
		default:
			cout << "������ �������� ���! ��������� ������� ����� ������ : ";
			break;
		}
	}
}