#include <iostream>
#include <cmath>
#include <iomanip>
using namespace std;

class Fraction {
private:
	int top;
	int bottom;

public:
	//Initialize the variables, top and bottom
	Fraction() {
		top = 0;
		bottom = 1;
	}
	
	Fraction(int a, int b) {
		top = a;
		bottom = b;
	  }

	// define the function
	Fraction(int a) {
		top = a;
		bottom = 1;
	  }
	Fraction add(Fraction a);
	Fraction sub(Fraction a);
	Fraction mul(Fraction a);		
	Fraction div(Fraction a);
	Fraction com(Fraction a);
	void input();
	void output();
	void fraToDec();
	void decToFra(double a);
	void simiplify();
	void sign();
};

Fraction Fraction:: add(Fraction a) {
	Fraction output;
	output.top = top * a.bottom + bottom * a.top;
	output.bottom = bottom * a.bottom;

	output.simiplify();
	output.sign();
	return output;
}

Fraction Fraction::sub(Fraction a) {
	Fraction output;
	output.top = top * a.bottom - bottom * a.top;
	output.bottom = bottom * a.bottom;

	output.simiplify();
	output.sign();
	return output;
}

Fraction Fraction::mul(Fraction a) {
	Fraction output;
	output.top = top * a.top;
	output.bottom = bottom * a.bottom;

	output.simiplify();
	output.sign();
	return output;
}

Fraction Fraction::div(Fraction a) {
	Fraction output;
	output.top = top * a.bottom;
	output.bottom = bottom * a.top;

	output.simiplify();
	output.sign();
	return output;
}

Fraction Fraction::com(Fraction a) {
	// Let these two fractions subtract with each other and compare the result with 0
	Fraction output;
	output.top = top * a.bottom - bottom * a.top;
	output.bottom = bottom * a.bottom;
	if (output.top == 0) {
		cout << "These two fractions are the same." << endl;
	}
	if ((output.top * output.bottom < 0)) {
		cout << "The second one is greater." << endl;
	}
	if ((output.top * output.bottom > 0)) {
		cout << "The first one is greater." << endl;
	}
	return output;
}

void Fraction:: simiplify() {
	// Temporarily store 
	int temp1 = abs(top);
	int temp2 = abs(bottom);
	int x = 1; // Initialize the greatest common divisor

	// the way to get the greatest common divisor
	while (temp1 != temp2)
	{
		if (temp1 > temp2)temp1 = temp1 - temp2;
		else temp2 = temp2 - temp1;
		if (temp1 == 0) break;
	}
	x = temp2;
	top = top / x;
	bottom = bottom / x;
}

void Fraction:: sign() {
	// judge the top and the bottom whether they have the same sign
	if (top>=0 &&bottom<0) {
		top = top * -1;
		bottom = bottom * -1;
	}
	if (top <= 0 && bottom < 0) {
		top = top * -1;
		bottom = bottom * -1;
	}
}

void Fraction::fraToDec() {
	cout << setiosflags(ios::fixed) << setprecision(10); // set the number of decimal places
	cout << "It is inverted into: " << (double)top / bottom << endl;
}

void Fraction::decToFra(double a) {
	top = a * 1000000;
	bottom = 1000000;
	simiplify();
	sign();
	cout << "It is inverted into: " << top << "/" << bottom << endl;
}

void Fraction:: input() {
	// input the top and the bottom from the keyboard
	cout << "Please input the numerator: ";
	cin >> top;
	cout << "Please input the denominator: ";
	cin >> bottom;

	simiplify();
	sign();
}

void Fraction:: output() {
	simiplify();
	sign();
	// show the result 
	cout << top << "/" << bottom << endl;
	
}





int main() {
	// Part 1
	// Input and output
	Fraction a;
	a.input();
	a.output();
	cout << endl << endl;

	// show the first kind of input 
	Fraction b;
	b.output();
	cout << endl << endl;

	// show the second kind of input
	Fraction f1(2, 3);
	f1.output();
	cout << endl << endl;

	// show the third kind of input
	Fraction f2(5);
	f2.output();
	cout << endl << endl;

	//Add
	Fraction f3(2, 3);
	Fraction f4(2, -5);
	(f3.add(f4)).output();
	cout << endl << endl;

	//Subtract
	Fraction f5(4,7);
	Fraction f6(3,8);
	(f5.sub(f6)).output();
	cout << endl << endl;

	//Multiple
	Fraction f7(4, 7);
	Fraction f8(3, -8);
	(f7.mul(f8)).output();
	cout << endl << endl;

	//Divide
	Fraction f9(4, 7);
	Fraction f10(3, -8);
	(f9.div(f10)).output();
	cout << endl << endl;

	// Comparison
	Fraction f11(4, 7);
	Fraction f12(3, -8);
	f11.com(f12);
	cout << endl << endl;

	Fraction f13(4, 8);
	Fraction f14(1, 2);
	f13.com(f14);
	cout << endl << endl;


	//Part 2	
	// Simplification of the fraction
	Fraction j(12, 24);
	j.output();
	cout << endl << endl;

	// Reassign the negative sign
	Fraction k(2,-3);
	k.output();	
	cout << endl << endl;

	//convert between fraction and decimal
	Fraction f15(1, 3);
	f15.fraToDec();
	cout << endl << endl;

	Fraction f16;
	f16.decToFra(0.23);
	cout << endl << endl;

	return 0;
}