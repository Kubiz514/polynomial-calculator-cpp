#include <iostream>
#include "PolynomialLibrary.h"
#include "PolynomialLibrary.cpp"

using namespace PolynomialLibrary;
using namespace std;

int main()
{
	//Niewiadome i jednomiany
	vector<Unknown> unknowns1{ Unknown('x', 2), Unknown('y', 2), Unknown('z', 2) };
	Monomial<double> mon1(-2, unknowns1);
	vector<Unknown> unknowns2 { Unknown('x', 2), Unknown('y', 2), Unknown('z', 2) };
	Monomial<double> mon2(-2, unknowns2);
	vector<Unknown> unknowns3{ Unknown('y', 3)};
	Monomial<double> mon3(3, unknowns3);
	vector<Unknown> unknowns4{ Unknown('y', 3)};
	Monomial<double> mon4(2, unknowns4);
	vector<Monomial<double>> monomials_client1{ mon1, mon3 };
	vector<Monomial<double>> monomials_client2{ mon2, mon4 };

	//Wielomiany
	double constant1 = -1, constant2 = 1;
	Polynomial<double> poly1(monomials_client1, &constant1);
	Polynomial<double> poly2(monomials_client2, &constant2);


	cout << "Addition example: " << endl;
	poly1.PrintPolynomial();
	cout << " + ";
	poly2.PrintPolynomial();
	cout << endl;
	Add<double>(poly1, poly2);

	cout << endl << "Substraction example: " << endl;
	poly1.PrintPolynomial();
	cout << " - (";
	poly2.PrintPolynomial();
	cout << ")" << endl;
	Substract<double>(poly1, poly2);

	return 0;
}

