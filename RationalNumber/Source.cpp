#include"RationalNumber.h"
void displayMenu();
void services(int);
int main()
{
	int choice;
	do
	{
		displayMenu();
		cin >> choice;
		services(choice);
	} while (choice != 14);
	return 0;
}
void displayMenu()
{
	cout << endl << "This is the rational number class" << endl
		<< "Choose what you want to do with rational numbers:" << endl
		<< "(1) Simplify a rational number" << endl
		<< "(2) Sum two rational numbers" << endl
		<< "(3) Difference of two rational numbers" << endl
		<< "(4) Multiply two rational numbers" << endl
		<< "(5) Divide two rational numbers" << endl
		<< "(6) Compare if a rational number is lesser than other" << endl
		<< "(7) Compare if a rational number is greater than other" << endl
		<< "(8) Compare if a rational number is equal of other" << endl
		<< "(9) Compare if a rational number is not equal of other" << endl
		<< "(10) Sum 1 integer to the fraction when choosing this option" << endl
		<< "(11) Sum 1 integer to the fraction after choosing this option" << endl
		<< "(12) Substract 1 integer to the fraction when choosing this option" << endl
		<< "(13) Substract 1 integer to the fraction after choosing this option" << endl
		<< "(14) Exit" << endl;
}

void services(int choice)
{
	RationalNumber rN1, rN2;
	switch (choice)
	{
	case 1:
		cin >> rN1;
		cout << rN1 << endl;
		break;
	
	case 2:
		cout << "Please enter the two rational numbers" << endl;
		cin >> rN1;
		cin >> rN2;
		cout << "The sum of the two rational numbers is: " << rN1.operator+(rN2) << endl;
		break;
	case 3:
		cout << "Please enter the two rational numbers" << endl;
		cin >> rN1;
		cin >> rN2;
			cout << "The difference of the two rational numbers is: " << rN1 - rN2 << endl;
		break;
	case 4:
		cout << "Please enter the two rational numbers" << endl;
		cin >> rN1;
		cin >> rN2;
		cout << "The multiplication of the two rational numbers is: " << rN1*rN2 << endl;
		break;
	case 5:
		cout << "Please enter the two rational numbers" << endl;
		cin >> rN1;
		cin >> rN2;
		cout << "The division of the two rational numbers is: " << rN1/rN2 << endl;
		break;
	case 6:
		cout << "Please enter the two rational numbers" << endl;
		cin >> rN1;
		cin >> rN2;
		if(1==rN1.operator<(rN2))
			cout << "The comparison of the two rational number is true " << endl;
		else
			cout << "The comparison of the two rational number is false " << endl;
		break;
	case 7:
		cout << "Please enter the two rational numbers" << endl;
		cin >> rN1;
		cin >> rN2;
		if (1 == rN1.operator>(rN2))
			cout << "The comparison of the two rational number is true " << endl;
		else
			cout << "The comparison of the two rational number is false " << endl;
		break;
	case 8:
		cout << "Please enter the two rational numbers" << endl;
		cin >> rN1;
		cin >> rN2;
		if (1 == rN1.operator==(rN2))
			cout << "The comparison of the two rational number is true " << endl;
		else
			cout << "The comparison of the two rational number is false " << endl;
		break;
	case 9:
		cout << "Please enter the two rational numbers" << endl;
		cin >> rN1;
		cin >> rN2;
		if (1 == rN1.operator!=(rN2))
			cout << "The comparison of the two rational number is true " << endl;
		else
			cout << "The comparison of the two rational number is false " << endl;
		break;
	case 10:
		cin >> rN1;
		cout << "The rational number + 1 integer is " << rN1.operator++() << endl;
		break;
	case 11:
		cin >> rN1;
		cout << "The rational number is " << rN1.operator++(1) << endl
			<< rN1;
		break;
	case 12:
		cin >> rN1;
		cout << "The rational number + 1 integer is " << rN1.operator--() << endl;
		break;
	case 13:
		cin >> rN1;
		cout << "The rational number is " << rN1.operator--(1) << endl
			<< rN1;
		break;
	case 14:
		cout << "Goodbye!!!" << endl;
		break;
	default:
		cout << "Invalid input, try again" << endl;
		break;
	}
}

