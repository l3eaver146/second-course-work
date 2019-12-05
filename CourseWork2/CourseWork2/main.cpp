#include "Header.h"
#include "Airplane.h"
#include "List.h"
int main() {
	List <Airplane> l;
	Airplane obj(250, "boing747", "230km/h", 2000);
	l.push(obj);
	l.show();
	cout << obj.get_name() << endl;
	return 0;
}