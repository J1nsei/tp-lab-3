#include "DateTime.h"
#include <iostream>

using namespace std;

int main() {
	DateTime fisrtDate;
	DateTime secondDate(22, 9, 2019);
	cout << fisrtDate.getDifference(secondDate) << endl;
	cout << fisrtDate.getToday() << endl;
	cout << fisrtDate.getPast(100) << endl;
	cout << secondDate.getFuture(150) << endl;
	return 0;
}
