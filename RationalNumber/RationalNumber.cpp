#include "RationalNumber.h"

int RationalNumber::simplify(int a, int b)
{
	int temp;
	while (a != 0)
	{
		temp = a;
		a = b % a;
		b = temp;
	}
	return b;
}

RationalNumber::RationalNumber()
{
	numerator = 0;
	denominator = 1;
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
}

RationalNumber RationalNumber::operator+(const RationalNumber& right)
{
	RationalNumber temp;
	if (getDenominator() == right.getDenominator()) 
	{
		temp.setNumerator(numerator + right.getNumerator());
		temp.setDenominator(denominator);
	}
	else
	{
		temp.setNumerator(denominator * right.getNumerator() + right.getDenominator() * numerator);
		temp.setDenominator(getDenominator() * right.getDenominator());
		int mcd = temp.simplify(temp.numerator, temp.denominator);
		temp.setNumerator(temp.numerator / mcd);
		temp.setDenominator(temp.denominator / mcd);
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
	}
	else
	{
		temp.setNumerator(denominator * right.getNumerator() - right.getDenominator() * numerator);
		temp.setDenominator(denominator * right.getDenominator());
		int mcd = temp.simplify(temp.numerator, temp.denominator);
		temp.setNumerator(temp.numerator / mcd);
		temp.setDenominator(temp.denominator / mcd);
	}
	return temp;
}

RationalNumber RationalNumber::operator*(const RationalNumber& right)
{
	RationalNumber temp;
	
		temp.setNumerator(numerator * right.getNumerator());
		temp.setDenominator(denominator* right.getDenominator());
		int mcd = temp.simplify(temp.numerator, temp.denominator);
		temp.setNumerator(temp.numerator / mcd);
		temp.setDenominator(temp.denominator / mcd);
	return temp;
}

RationalNumber RationalNumber::operator/(const RationalNumber& right)
{
	RationalNumber temp;
	temp.setNumerator(numerator * right.getDenominator());
	temp.setDenominator(denominator * right.getNumerator());
	int mcd = temp.simplify(temp.numerator, temp.denominator);
	temp.setNumerator(temp.numerator / mcd);
	temp.setDenominator(temp.denominator / mcd);
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
	if (numerator * right.denominator > right.numerator * denominator)
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
	return *this;
}

RationalNumber RationalNumber::operator++(int)
{
	RationalNumber temp;
	temp = *this;
	numerator = numerator + denominator;
	return temp;
}

RationalNumber RationalNumber::operator--()
{
	numerator = numerator - denominator;
	return *this;
}

RationalNumber RationalNumber::operator--(int)
{
	RationalNumber temp;
	temp = *this;
	numerator = numerator - denominator;
	return temp;
}

ostream& operator<<(ostream& strm, const RationalNumber& right)
{
	strm << right.numerator << "/" << right.denominator;
	return strm;
}

istream& operator>>(istream& strm, RationalNumber& obj)
{
	cout << "Numerator: ";
	strm >> obj.numerator;

	// Prompt the user for the inches. 
	cout << "Denominator: ";
	strm >> obj.denominator;
	if (obj.denominator != 0)
	{
		// Normalize the values. 
		int temp = obj.simplify(obj.numerator, obj.denominator);
		obj.numerator = (obj.numerator / temp);
		obj.denominator = (obj.denominator / temp);
		return strm;
	}
	else
	{
		while (obj.denominator == 0)
		{
			cout << "Invalid denominator. Try again." << endl;
			// Prompt the user for the inches. 
			cout << "Denominator: ";
			strm >> obj.denominator;
		}
		return strm;
	}
}
