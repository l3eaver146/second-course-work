#include "Header.h"
#include "Airplane.h"
#include "List.h"
#include "Users.h"
int main() {
	setlocale(LC_ALL, "ru");
	List <Users> l;
	Users obj("GG", "wp", "admin");
	Users obj1("GGw", "wp", "admin");
	Users obj2("GGggg", "wpf", "user");
	l.push(obj);
	l.push(obj1);
	l.push(obj2);
	l.show_users();
	return 0;
}