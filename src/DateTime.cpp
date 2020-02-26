#define _CRT_SECURE_NO_WARNINGS
#include "DateTime.h"
#include <ctime>
#include <string>

string wdays[7] = { "sunday", "monday", "tuesday", "wednesday", "thursday", "friday", "saturday" };
string months[12] = { "january", "february", "march", "april", "may", "june", "july", "august", "september", "october", "november", "december" };

DateTime::DateTime(int day, int month, int year)
{
	time_t seconds = time(NULL);
	date = *localtime(&seconds);
	date.tm_mday = day;
	date.tm_mon = month - 1;
	date.tm_year = year - 1900;
	mktime(&date);
}
DateTime::DateTime()
{
	time_t seconds = time(NULL);
	date = *localtime(&seconds);
}
DateTime::DateTime(DateTime& copyobj)
{
	this->date = copyobj.date;
}
string DateTime::getToday()
{
	return getT(date);
}
string DateTime::getT(struct tm& ntime)
{
	string strTime = "";
	if (ntime.tm_mday < 10)
	{
		strTime += "0";
	}
	strTime+=to_string(ntime.tm_mday)+" "+months[ntime.tm_mon]+" " + to_string(ntime.tm_year + 1900) + ", " + wdays[ntime.tm_wday];
	return strTime;
}
string DateTime::getFuture(unsigned int N)
{
	string future;
	tm fdate = date;
	fdate.tm_mday += N;
	mktime(&fdate);
	if (fdate.tm_mday < 10)
		future += "0";
	future += to_string(fdate.tm_mday) + " " + months[fdate.tm_mon] + " " + to_string(fdate.tm_year + 1900) + ", " + wdays[fdate.tm_wday];
	return future;
}
string DateTime::getPast(unsigned int N)
{
	string past = "";
	tm pdate = date;
	pdate.tm_mday -= N;
	mktime(&pdate);
	if (pdate.tm_mday < 10)
		past += "0";
	past += to_string(pdate.tm_mday) + " " + months[pdate.tm_mon] + " " + to_string(pdate.tm_year + 1900) + ", " + wdays[pdate.tm_wday];
	return past;
}
string DateTime::getTomorrow()
{
	return getFuture(1);
}

string DateTime::getYesterday()
{
	return getPast(1);
}

int DateTime::getDifference(DateTime& anotherDate)
{
	return abs(mktime(&date) - mktime(&anotherDate.date)) / 86400;
}