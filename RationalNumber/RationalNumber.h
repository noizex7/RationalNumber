#pragma once
#include<iostream>
using namespace std;
class RationalNumber;
ostream& operator << (ostream&, const RationalNumber&);
istream& operator >> (istream&, RationalNumber&);
class RationalNumber
{
private:
	int numerator;
	int denominator;
	void simplify();
public:
	RationalNumber();
	RationalNumber(const RationalNumber&);
	void setNumerator(int);
	void setDenominator(int);
	int getNumerator()const;
	int getDenominator()const;
	void displayData(const RationalNumber&)const;
	void operator=(const RationalNumber& right);
	RationalNumber operator + (const RationalNumber& right);
	RationalNumber operator - (const RationalNumber& right);
	RationalNumber operator * (const RationalNumber& right);
	RationalNumber operator / (const RationalNumber& right);
	bool operator<(const RationalNumber& right);
	bool operator>(const RationalNumber& right);
	bool operator==(const RationalNumber& right);
	bool operator!=(const RationalNumber& right);
	friend ostream& operator << (ostream&, const RationalNumber&);
	friend istream& operator >> (istream&, RationalNumber&);
	RationalNumber operator ++ (); // Prefix ++ 
	RationalNumber operator ++ (int); // Postfix ++ 
	RationalNumber operator -- (); // Prefix ++ 
	RationalNumber operator -- (int); // Postfix ++ 
};

