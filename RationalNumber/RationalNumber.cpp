#include "RationalNumber.h"

void RationalNumber::simplify()
{
	int restant = denominator%numerator;
	if (restant == 0)
	{
		int restant = numerator;
	}
	while (restant != 0)
	{
		restant = numerator;
		numerator = denominator % numerator;
		denominator = restant;
	}
	numerator = numerator / restant;
	denominator = denominator / restant;
}

RationalNumber::RationalNumber()
{
	numerator = 1;
	denominator = 1;
	simplify();
}

RationalNumber::RationalNumber(const RationalNumber& right)
{
	numerator = right.getNumerator();
	denominator = right.getDenominator();
}

void RationalNumber::setNumerator(int n)
{
	numerator = n;
}

void RationalNumber::setDenominator(int d)
{
	if (d > 0)
		denominator = d;
	else
		denominator = 1;
}

int RationalNumber::getNumerator() const
{
	return numerator;
}

int RationalNumber::getDenominator() const
{
	return denominator;
}

void RationalNumber::displayData(const RationalNumber& right) const
{
	cout << "The rational number is: " << right << endl;
}

void RationalNumber::operator=(const RationalNumber& right)
{
	numerator = right.getNumerator();
	denominator = right.getDenominator();
	simplify();
}

RationalNumber RationalNumber::operator+(const RationalNumber& right)
{
	RationalNumber temp;
	if (getDenominator() == right.getDenominator()) 
	{
		temp.setNumerator(numerator + right.getNumerator());
		temp.setDenominator(denominator);
		temp.simplify();
	}
	else
	{
		temp.setNumerator(denominator * right.getNumerator() + right.getDenominator() * numerator);
		temp.setDenominator(getDenominator() * right.getDenominator());
		temp.simplify();
	}
	return temp;
}

RationalNumber RationalNumber::operator-(const RationalNumber& right)
{
	RationalNumber temp;
	if (denominator == right.getDenominator())
	{
		temp.setNumerator(numerator - right.getNumerator());
		temp.setDenominator(denominator);
		temp.simplify();
	}
	else
	{
		temp.setNumerator(denominator * right.getNumerator() - right.getDenominator() * numerator);
		temp.setDenominator(denominator * right.getDenominator());
		temp.simplify();
	}
	return temp;
}

RationalNumber RationalNumber::operator*(const RationalNumber& right)
{
	RationalNumber temp;
	
		temp.setNumerator(numerator * right.getNumerator());
		temp.setDenominator(denominator* right.getDenominator());
		temp.simplify();
	
	return temp;
}

RationalNumber RationalNumber::operator/(const RationalNumber& right)
{
	RationalNumber temp;
	temp.setNumerator(numerator * right.getDenominator());
	temp.setDenominator(denominator * right.getNumerator());
	temp.simplify();
	return temp;
}

bool RationalNumber::operator<(const RationalNumber& right)
{
	if (numerator * right.getDenominator() < right.getNumerator() * denominator)
		return true;
	else
		return false;
}

bool RationalNumber::operator>(const RationalNumber& right)
{
	if (numerator * right.getDenominator() > right.getNumerator() * denominator)
		return true;
	else
		return false;
}

bool RationalNumber::operator==(const RationalNumber& right)
{
	if (numerator * right.getDenominator() == right.getNumerator() * denominator)
		return true;
	else
		return false;
}

bool RationalNumber::operator!=(const RationalNumber& right)
{
	if (numerator * right.getDenominator() != right.getNumerator() * denominator)
		return true;
	else
		return false;
}

RationalNumber RationalNumber::operator++()
{
	numerator = numerator + denominator;
	simplify();
	return *this;
}

RationalNumber RationalNumber::operator++(int)
{
	RationalNumber temp;
	temp = *this;
	numerator = numerator + denominator;
	simplify();
	return temp;
}

RationalNumber RationalNumber::operator--()
{
	numerator = numerator - denominator;
	simplify();
	return *this;
}

RationalNumber RationalNumber::operator--(int)
{
	RationalNumber temp;
	temp = *this;
	numerator = numerator - denominator;
	simplify();
	return temp;
}

ostream& operator<<(ostream& strm, const RationalNumber& right)
{
	strm << right.numerator << "/" << right.denominator;
	return strm;
}

istream& operator>>(istream& strm, RationalNumber& right)
{
	cout << "Numerator: ";
	strm >> right.numerator;
	cout << "Please enter the denominator: ";
	strm >> right.denominator;
	right.simplify();
	return strm;
}
