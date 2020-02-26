#include <iostream>
#include <ctime>
#include <string>

using namespace std;

class DateTime
{
	tm date;
public:
	DateTime(int, int, int);
	DateTime();
	DateTime(DateTime& copyobj);
	string getToday();
	string getYesterday();
	string getTomorrow();
	string getFuture(unsigned int N);
	string getPast(unsigned int N);
	int getDifference(DateTime&);
	string getT(struct tm&);
};