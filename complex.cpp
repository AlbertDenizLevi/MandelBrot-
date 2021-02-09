#include "complex.h"

complex::complex()
{
	num.i=0;
	num.r=0;
}

complex::complex(double i, double r)
{
	num.i=i;
	num.r=r;
}

complex::~complex()
{
}

complex complex::operator + (complex a)
{
	complex b;
	b.num.i=a.num.i+num.i;
	b.num.r=a.num.r+num.r;
	return b;
}

complex complex::operator * (complex a)
{
	complex b;
	b.num.i=this->num.i*a.num.r+this->num.r*a.num.i;
	b.num.r=num.r*a.num.r-num.i*a.num.i;
	return b;
}

complex complex::operator - (complex a)
{
	complex b;
	b.num.i=a.num.i-num.i;
	b.num.r=a.num.r-num.r;
	return b;
}

complex complex::operator / (complex a)
{
	complex b;
	b.num.i=this->num.i/a.num.r+this->num.r/a.num.i;
	b.num.r=num.r/a.num.r-num.i/a.num.i;
	return b;
}

	//accessors
	double complex::geti() const
	{
		return this->num.i;
	}
	double complex::getr() const
	{
		return this->num.r;
	}
	//mutators
	void complex::seti(double number)
	{
		this->num.i=number;
	}
	void complex::setr(double number)
	{
		this->num.r=number;
	}