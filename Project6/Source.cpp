#include <iostream>
#include <math.h>
#include <stdlib.h>
using namespace std;
template<class T>
T maxim( T& a,  T& b)
{
	if (a > b)
		return a;
	return b;
}

class rectangle
{
protected:
	int x1, y1, x2, y2;
	void normalize();

public:
	rectangle(int = 0, int = 0, int = 1, int = 1);
	int area() const
	{
		return abs((x1 - x2) * (y1 - y2));
	}
	bool operator>(const rectangle) const;
	friend istream& operator>>(istream&, rectangle&);
	friend ostream& operator<<(ostream&, const rectangle&);
};
rectangle::rectangle(int a, int b, int c, int d)
{
	x1 = a;
	y1 = b;
	x2 = c;
	y2 = d;
	this->normalize();
}
void rectangle::normalize()
{
	if (x1 < 1) x1 = 1;
	if (x1 > 80) x1 = 80;
	if (x2 < 1) x2 = 1;
	if (x2 > 80) x2 = 80;
	if (y1 < 1) y1 = 1;
	if (y1 > 24) y1 = 24;
	if (y2 < 1) y2 = 1;
	if (y2 > 24) y2 = 24;
}
bool rectangle::operator>(const rectangle r) const
{
	if (this->area() > r.area())
		return true;
	return false;
}
istream& operator>>(istream& str, rectangle& r)
{
	cout << "x1 = ";
	str >> r.x1;
	cout << "y1 = ";
	str >> r.y1;
	cout << "x2 = ";
	str >> r.x2;
	cout << "y2 = ";
	str >> r.y2;
	r.normalize();
	return str;
}
ostream& operator<<(ostream& str, const rectangle& r)
{
	str << "(x1=" << r.x1 << ", y1=" << r.y1 << ") , (x2=" << r.x2 << ", y2=" << r.y2 << ") - area =" <<
		r.area();
	return str;
}
class para :public rectangle
{
private:
	int h;
public:
	para(int h = 1, int a = 0, int b = 0, int c = 1, int d = 1) :rectangle(a, b, c, d)
	{
		this->h = h;
	}
	int volume()const;
	bool operator>(const para&);
	friend istream& operator>>(istream&, para&);
	friend ostream& operator<<(ostream&, para&);
};
int para::volume()const {
	cout << "h=" << h << endl;
	cout << "Aria=" << this->area();
	return h * this->area();
}

bool para::operator>(const para& p)
{
	if (this->volume() > p.volume())
		return true;
	else
		return false;
}
istream& operator>>(istream& str, para& p) {
	cout << "x1 = ";
	str >> p.x1;
	cout << "y1 = ";
	str >> p.y1;
	cout << "x2 = ";
	str >> p.x2;
	cout << "y2 = ";
	str >> p.y2;
	p.normalize();
	return str;
}
ostream& operator<<(ostream& str, para& p) {
	str << rectangle(p);
	str << "h=" << p.h << endl;
	str << "volume=" << p.volume() << endl;
	return str;
}

int main()
{
	//All The work with rectangles
	rectangle r[1000];
	for (int i = 1; i <= 5; i++)
	{
		cout << "r[" << i << "]" << endl;
		cin >> r[i];
		cout << endl;
	}
	cout << "Rectangles are : " << endl;
	for (int i = 1; i <= 5; i++)
		cout << endl << "Rectangle[" << i << "] : " << r[i];
	cout << endl;
	rectangle maxr = r[0];
	for (int i = 0; i < 5; i++)
	{
		maxr = maxim(maxr, r[i]);
	}
	cout << "The max rectangle is: " << maxr << endl;
	//All the work with paralelipipeds;
	para* p = new para[5]; // Dynamic allocation

	for (int i = 1; i <= 5; i++)
	{
		cout << "p[" << i << "]" << endl;
		cin >> p[i];
		cout << endl;
	}
	cout << "Parallelipipeds are : " << endl;
	for (int i = 1; i <= 5; i++)
		cout << endl << "Parallelipiped[" << i << "] : " << p[i];

	para maxp = p[0];
	for (int i = 0; i < 5; i++)
		maxp = maxim(maxp, p[i]);
	cout << "\nThe maximum rectangle is: " << maxp;
    delete[] p; // Deallocation of dynamic p
	return 0;
}