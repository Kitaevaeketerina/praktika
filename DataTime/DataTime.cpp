#include "DataTime.h"
#include <iostream>
#include <ctime>
#include <time.h>
using namespace std;

DataTime::DataTime(int day1, int month1, int year1)
	{
		day = day1;
		month = month1;
		year = year1;
	}

DataTime::DataTime()
	{
		
		rawtime = time(NULL);
		timeinfo = gmtime(&rawtime);
		day = timeinfo->tm_mday;
		month = timeinfo->tm_mon + 1;
		year = timeinfo->tm_year + 1900;
		//cout << day << "." << month << "." << year << endl;
	}

void DataTime::printToday()
	{
		days[0]="Sunday";
		days[1]="Monday";
		days[3]="Tuesday";
		days[4]="Wednesday";
		days[5]="Thursday";
		days[6]="Saturday";

		months[0]="January";
		months[1]="February";
		months[2]="March";
		months[3]="April";
		months[4]="May";
		months[5]="June";
		months[6]="Jule";
		months[7]="August";
		months[8]="september";
		months[9]="october";
		months[10]="november";
		months[11]="december";
		DataTime();
		cout << "Today " << day << "." << months[month-1] << "." << year << "\n"  << endl;
	}

void DataTime::printTomorrow()
	{
		char buffer[80];
		tm t = {};
		t.tm_mday = day;
		t.tm_mon = month - 1;
		t.tm_year= year - 1900;
		t.tm_mday += 1;
		mktime(&t);
		strftime(buffer, 80, "%d %B %Y %A\n", &t); 
		cout << "Tomorrow will be " << buffer << endl;
	}

void DataTime::printFuture(int N)
	{
		count = N;
		char buffer[80];
		tm t = {};
		t.tm_mday = day;
		t.tm_mon = month - 1;
		t.tm_year= year - 1900;
		t.tm_mday += N;
		mktime(&t);
		strftime(buffer, 80, "%d %B %Y %A\n", &t); 
		cout << "After " << N << " days will be " << buffer << endl;
	}

void DataTime::printYesterday()
	{
		char buffer[80];
		tm t = {};
		t.tm_mday = day;
		t.tm_mon = month - 1;
		t.tm_year= year - 1900;
		t.tm_mday -= 1;
		mktime(&t);
		strftime(buffer, 80, "%d %B %Y %A\n", &t); 
		cout << "Yesterday was " << buffer << endl;
	}

void DataTime::printPast(int N)
	{
		count = N;
		char buffer[80];
		tm t = {};
		t.tm_mday = day;
		t.tm_mon = month - 1;
		t.tm_year= year - 1900;
		t.tm_mday -= N;
		mktime(&t);
		strftime(buffer, 80, "%d %B %Y %A\n", &t); 
		cout << N << " days ago was " << buffer << endl;
	}

void DataTime::printMonth()
	{
		DataTime();
		cout << "Now is the month of " << months[month-1] << "\n"  << endl;
	}

void DataTime::printWeekDay()
	{
		char buffer[80];
		tm t = {};
		t.tm_mday = day;
		t.tm_mon = month - 1;
		t.tm_year= year - 1900;
		mktime(&t);
		strftime(buffer, 80, " %A\n", &t); 
		cout << "Today " << buffer << endl;
	}

void DataTime::calcDifference(DataTime d1, DataTime d2)
	{
		int day1, month1, year1;
		int day2, month2, year2;
		const int oneday = 0x15180;
		day1 = d1.day;
		month1 = d1.month;
		year1 = d1.year;

		day2 = d2.day;
		month2 = d2.month;
		year2 = d2.year;

		tm FirstDate = {0, 0, 0, day1, month1 - 1, year1 - 0x76C, 0, 0, 0};
		tm SecondDate = {0, 0, 0, day2, month2 - 1, year2 - 0x76C, 0, 0, 0};
		time_t t1 = mktime(&FirstDate);
		time_t t2 = mktime(&SecondDate);
		time_t diff = ((t1 > t2) ? t1 - t2 : t2 - t1) / oneday;
		cout << "Difference in days " << diff << endl;
	}