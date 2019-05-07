#ifndef DATE_H
#define DATE_H

class Date
{
public:
 Date();
 Date(int, int, int);
 void setYear(int);
 void setMonth(int);
 int getYear();
 int getMonth();
 int getDay();
 void print();
private:
 int year;
 int month;
 int day;
};

#endif

#include "Date.h"
#include <iostream>
using namespace std;
Date::Date() {
}
Date::Date(int m, int d, int y) {
 year = y;
 month = m;
 day = d;
}

void Date::setYear(int newYear) {
 year = newYear;
}
void Date::setMonth(int newMonth) {
 month = newMonth;
}
int Date::getYear() {
 return year;
}
int Date::getMonth() {
 return month;
}
int Date::getDay() {
 return day;
}

void Date::print() {
 cout << getMonth() << "/" << getDay() << "/" << getYear() << ", ";
}


#ifndef STUDENT_H
#define STUDENT_H
#include <string>
#include "Date.h"
using namespace std;
class StuCard
{
public:
 StuCard(string, bool, double,double,double, Date);
 void setName(string);
 void setSex(bool);
 void setScore(int, double);
 void setDate(int, int, int);
 void setDate(Date);
 string getName();
 bool getSex();
 double getScore(int);
 Date getDate();
 double average();
 int getAge(int);
 void printCard();
private:
 string name;
 bool sex;
 double scoreAry[3];
 Date birthDay;
};
#endif

#include "StuCard.h"
#include <iostream>
#include <iomanip>
using namespace std;
StuCard::StuCard(string n, bool s, double a, double b, double c, Date d) {
 name = n;
 sex = s;
 scoreAry[0] = a;
 scoreAry[1] = b;
 scoreAry[2] = c;
 birthDay = d;
}
void StuCard::setName(string newName) {
 name = newName;
}
void StuCard::setSex(bool newSex) {
 sex = newSex;
}
void StuCard::setScore(int i, double newScore) {
 scoreAry[i] = newScore;
}
void StuCard::setDate(int newMonth, int newDay, int newYear) {
 Date birthDay(newMonth, newDay, newYear);
}
void StuCard::setDate(Date newDate) {
 birthDay = newDate;
}
string StuCard::getName() {
 return name;
}
bool StuCard::getSex() {
 return sex;
}
double StuCard::getScore(int i) {
 return scoreAry[i];
}
Date StuCard::getDate() {
 return birthDay;
}
double StuCard::average() {
 double total=0, average=0;
 for (int i = 0; i<3; i++) {
  total += scoreAry[i];
 }
 average = total / 3;
 return average;
}
int StuCard::getAge(int y) {
 return 2018 - y;
}
void StuCard::printCard() {
 cout << fixed << setprecision(1) << name << ", " << sex << ", " << scoreAry[0] << ", " << scoreAry[1] << ", " << scoreAry[2] << ", ";
 getDate().print();
 cout << average() << ", " << getAge(getDate().getYear()) << endl;
}

#include "StuCard.h"
#include <iostream>
#include <iomanip>
void classAver(StuCard StuCard[], int size) {
 double total=0;
 for (int j = 0; j < 3; j++) {
  for (int i = 0; i < size; i++) {
   total += StuCard[i].getScore(j);
  }
  cout << fixed << setprecision(1) << total / 5 ;
  if(j!=2)
      cout << ", ";
  total = 0;
 }
}
int main() {
 string n;
 bool s;
 double a, b, c;
 int m, d, y;
 cin >> n >> s >> a >> b >> c >> m >> d >> y;
 StuCard s1("Jerry", 1, 80.0, 70.0, 90.0, Date(3, 20, 1997));
 StuCard s2("John", 1, 85.0, 77.0, 95.0,Date (5 , 20 , 1995));
 StuCard s3("Mary", 0, 83.0, 75.0, 70.0, Date(2 , 18 , 2007));
 StuCard s4("Tom", 1, 73.0, 95.0, 67.0, Date(11 , 8 , 2003));
 StuCard s5(n, s, a, b, c, Date(m, d, y));
 StuCard sAry[5] = { s1,s2,s3,s4,s5 };
 s1.printCard();
 s2.printCard();
 s3.printCard();
 s4.printCard();
 s5.printCard();
 cout << "Average:";
 classAver(sAry, 5);

}