#include "Money.h"

void Money::setGrn(long value)
{
	if (value < 0)
		throw Exception("\nGrn must be bigger than 0\n");
	grn = value;
}
void Money::setKop(unsigned int value)
{
	if (value < 0)
		throw Exception("\nKop must be bigger than 0\n");
	kop = value;
}
Money::Money() : grn(0), kop(0)
{
}
Money::Money(const long grn, const unsigned int kop)
{
	if (grn < 0 || kop< 0)
		throw Exception("\nGrn and kop must be bigger than 0\n");
	long ngrn = grn;
	unsigned int nkop = kop;
	
	while (nkop > 99)
	{
		ngrn++;
		nkop -= 100;
	}
	
	setGrn(ngrn);
	setKop(nkop);
}

Money::Money(double x)
{
	long ngrn = (long)x;
	x -= ngrn;
	x *= 100;
	unsigned int nkop = (unsigned int)x;
	
	while (nkop > 99)
	{
		nkop -= 100;
		ngrn++;
	}
	while (nkop < -99)
	{
		nkop += 100;
		ngrn--;
	}
	
	setGrn(ngrn);
	setKop(nkop);
}


Money::Money(const Money& x)
{
	int ngrn = x.grn;
	int nkop = x.kop;

	while (nkop > 99)
	{
		ngrn++;
		nkop -= 100;
	}
	while (nkop < -99)
	{
		nkop += 100;
		ngrn--;
	}

	setGrn(ngrn);
	setKop(nkop);
}
Money::~Money(void)
{}
Money::operator string() const
{
	stringstream ss;
	ss << grn << ". " << kop;
	return ss.str();
}
ostream& operator << (ostream& out, const Money& x)
{

	return out << (string)x;
}
istream& operator >> (istream& in, Money& r)
{
	long hrn;
	unsigned long kop;

	cout << "a = "; in >> hrn;
	cout << "b = "; in >> kop;

	if (hrn < 0 || kop < 0)
	{
		throw nException("Grn and Kop must be > 0");
	}
	else
	{
		r.setGrn(hrn);
		r.setKop(kop);
	}

	return in;
}
Money operator -(const Money& first, const Money& second)
{

	long a;
	unsigned long b;
	Money t;
	if (first.getGrn() < second.getGrn())
	{
		a = 0;
		b = 0;
	}
	if ((first.getGrn() > second.getGrn()) && (first.getKop() < second.getKop()))
	{
		a = (first.getGrn() - 1) - second.getGrn();
		b = (100 - (second.getKop() - first.getKop()));
	}
	else
	{
		a = (first.getGrn() - second.getGrn());
		b = (first.getKop() - second.getKop());
	}
	t.setGrn(a);
	t.setKop(b);
	return t;
}
Money operator *(const Money& value, const double n)
{
	Money t;
	long a = (value.getGrn() * n);
	unsigned long b = (value.getKop() * n);
	while (b > 99)
	{
		b -= 100;
		a++;
	}
	t.setGrn(a);
	t.setKop(b);
	return t;
}
bool Money::operator ==(const Money& x)
{
	return(this->getGrn() == x.getGrn() && this->getKop() == x.getKop());
}
bool Money::operator > (const Money& x)
{
	return  ((this->getGrn() > x.getGrn()) || ((this->getGrn() == x.getGrn()) && (this->getKop() > x.getKop())));
}
bool Money::operator < (const Money& x)
{
	return ((this->getGrn() < x.getGrn()) || ((this->getGrn() == x.getGrn()) && (this->getKop() < x.getKop())));
}
Money& Money::operator ++()
{
	long a = this->getGrn();
	unsigned long b = this->getKop();

	a++;
	b++;

	this->setGrn(a);
	this->setKop(b);

	return *this;
}
Money& Money::operator --()
{
	long a = this->getGrn();
	unsigned long b = this->getKop();

	a--;
	b--;

	this->setGrn(a);
	this->setKop(b);

	return *this;

}
Money Money::operator ++(int)
{
	Money t(*this);

	long a = this->getGrn();
	unsigned long b = this->getKop();

	a++;
	b++;

	this->setGrn(a);
	this->setKop(b);

	return t;
}
Money Money::operator --(int)
{
	Money t(*this);

	long a = this->getGrn();
	unsigned long b = this->getKop();

	a--;
	b--;

	this->setGrn(a);
	this->setKop(b);

	return t;
}