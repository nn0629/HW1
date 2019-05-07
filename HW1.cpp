#ifndef Rectangle_h
#define Recrangle_h

class Rectangle
{
public:

	Rectangle();
	Rectangle(double, double);
	double getArea()const;
	double getHeight()const;
	double getWidth()const;
	void setWidth(double);
	void setHeight(double);
	static int getNumOfRect();
private:
	double width;
	double height;
	static int numOfRect;
};

#endif

#include "Rectangle.h"
int Rectangle::numOfRect=0;
Rectangle::Rectangle() {
	width = 1;
	height = 1;
	numOfRect++;
}
Rectangle::Rectangle(double newWidth, double newHeight) {
	width = newWidth;
	height = newHeight;
	numOfRect++;
}
double Rectangle::getArea() const{
	return width * height;
}
double Rectangle::getHeight() const{
	return height;
}
double Rectangle::getWidth() const{
	return width;
}
void Rectangle::setWidth(double newWidth) {
	width = (newWidth > 0) ? newWidth : 0;
}
void Rectangle::setHeight(double newHeight) {
	height = (newHeight > 0) ? newHeight : 0;
}
int Rectangle::getNumOfRect() {
	return numOfRect;
}

#include <iostream>
#include <sstream>
#include <string>
#include "Rectangle.h"
using namespace std;
void sum(Rectangle rectArray[], int size) {
	double total = 0;
	for (int i = 0; i < size; i ++) {
		total += rectArray[i].getArea();
	}
	cout << "Area:" << total;
}
void printRectangleArray(Rectangle rectArray[], int size) {
	for (int i = 0; i < size; i++) {
		cout << rectArray[i].getArea() << " " ;
	}
	cout << endl;

}
int main()
{
    double a,b,c,d,e,f,g,h,i,j;
    cin >> a >> b >> c >> d >> e >> f >> g >> h >> i >>j;
    Rectangle rectArray[5]={Rectangle(a,b),Rectangle(c,d),Rectangle(e,f),Rectangle(g,h),Rectangle(i,j)};
    printRectangleArray(rectArray,5);
    cout << "Total: " << rectArray[0].getNumOfRect() << " rectangles " << endl;
    sum(rectArray,5);
}