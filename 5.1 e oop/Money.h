#pragma once
#include <iostream>
#include <string>
#include <sstream>

#include "Exception.h"
#include "nException.h"
#include "Object.h"

using namespace std;
class Money :
    public Object
{
private:
	long grn;
	unsigned int kop;
public:
	Money();
	Money(long, unsigned int);
	Money(double);
	Money(const Money&);
	~Money();

	void setGrn(long grn);
	void setKop(unsigned int kop);
	long getGrn() const { return grn; }
	unsigned int getKop() const { return kop; }

	operator string() const;

	friend Money operator -(const Money&, const Money&);
	friend Money operator *(const Money&, const double);

	bool operator ==(const Money&);
	bool operator >(const Money&);
	bool operator <(const Money&);

	friend ostream& operator << (ostream&, const Money&);
	friend istream& operator >> (istream&, Money&);

	Money& operator ++();
	Money& operator --();
	Money operator ++(int);
	Money operator --(int);
};

