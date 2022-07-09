#include <iostream>
#include "PolynomialLibrary.h"
#include <algorithm>
#include <vector>
#include <string>

using namespace std;

namespace PolynomialLibrary
{
	template <typename Type>
	class Monomial;

	Unknown::Unknown(char letter, int exponent) {
		letter_ = letter;
		exponent_ = exponent;
	};

	void Unknown::SetLetter(char letter) {
		letter_ = letter;
	};
	char Unknown::GetLetter() {
		return letter_;
	};
	void Unknown::SetExponent(char exponent) {
		exponent_ = exponent;
	};
	int Unknown::GetExponent() {
		return exponent_;
	};

	template <typename Type>
	Monomial<Type>::Monomial(Type coefficient, vector<Unknown> variables) {
		coefficient_ = coefficient;
		variables_ = variables;
	};

	template<typename Type>
	void Monomial<Type>::SetCoefficient(Type coefficient)
	{
		coefficient_ = coefficient;
	};

	template <typename Type>
	Type Monomial<Type>::GetCoefficient() {
		return coefficient_;
	}

	template<typename Type>
	void Monomial<Type>::PrintMonomial()
	{
		cout << coefficient_;
		for (auto& unknown : variables_) {
			cout << unknown.GetLetter() << "^" << unknown.GetExponent();
		}
	};

	template<typename Type>
	void Polynomial<Type>::Invert() {
		for (Monomial<Type>& mon : monomials_) {
			mon.SetCoefficient(-1* mon.GetCoefficient());
		}
		constant_ *= -1;
	}

	template <typename Type>
	bool operator==(const Monomial<Type>& left, const Monomial<Type>& right) {
		if (left.variables_.size() != right.variables_.size())
			return false;

		vector<Unknown> leftVariables = left.variables_;
		vector<Unknown> rightVariables = right.variables_;

		//Variables have to be sorted in alphabetical order
		for (int i = 0; i < left.variables_.size(); i++) {
			if (leftVariables[i].GetExponent() != rightVariables[i].GetExponent() || leftVariables[i].GetLetter() != rightVariables[i].GetLetter())
				return false;
		}

		return true;
	};

	template <typename Type>
	Polynomial<Type>::Polynomial(std::vector<Monomial<Type>> monomials, Type *constant) {
		monomials_ = monomials;
		constant_ = *constant;
	};

	template <typename Type>
	Polynomial<Type>::Polynomial(Polynomial<Type>& polynomial) {
		monomials_ = polynomial.monomials_;
		constant_ = polynomial.constant_;
	};

	template<typename Type>
	void Polynomial<Type>::SetConstant(Type constant)
	{
		constant_ = constant;
	};

	template<typename Type>
	Type Polynomial<Type>::GetConstant()
	{
		return constant_;
	};

	template<typename Type>
	void Polynomial<Type>::CleanMonomials()
	{
		monomials_.erase(
			remove_if(
				monomials_.begin(),
				monomials_.end(),
				[](Monomial<Type>& mon) { return mon.GetCoefficient() == 0; }
			),
			monomials_.end());
	}

	template<typename Type>
	void Polynomial<Type>::PrintPolynomial()
	{
		int i = 0;
		string operatorSign = "";

		for (Monomial<Type>& mon : monomials_) {
			if (i != 0 && mon.GetCoefficient() > 0) cout << "+";

			mon.PrintMonomial();
			i++;
		}
		if (constant_ != 0) {
			if (constant_ > 0) cout << "+";
			cout << constant_;
		}
	};

	template <typename Type>
	void Add(Polynomial<Type> poly1, Polynomial<Type> poly2) {
		Polynomial<Type> result(poly1);
		Type resultConstant;
		int i = 0, j = 0;

		if (poly1.monomials_.size() > poly2.monomials_.size()) {
			for (Monomial<Type>& mon1 : poly1.monomials_)
			{
				for (Monomial<Type>& mon2 : poly2.monomials_) {

					if (mon1 == mon2)
					{
						result.monomials_[i].SetCoefficient(mon2.GetCoefficient() + mon1.GetCoefficient());
						break;
					}
					j++;
				}
				if (j == poly2.monomials_.size())
					result.monomials_.push_back(mon1);
				j = 0;
				i++;
			}
		}
		else {
			for (Monomial<Type>& mon1 : poly2.monomials_)
			{
				for (Monomial<Type>& mon2 : poly1.monomials_) {

					if (mon1 == mon2)
					{
						result.monomials_[i].SetCoefficient(mon2.GetCoefficient() + mon1.GetCoefficient());
						break;
					}
					j++;
				}
				if (j == poly2.monomials_.size())
					result.monomials_.push_back(mon1);
				j = 0;
				i++;
			}
		}

		result.CleanMonomials();

		resultConstant = result.GetConstant() + poly1.GetConstant();
		result.SetConstant(resultConstant);
		result.PrintPolynomial();
	};


	template <typename Type>
	void Substract(Polynomial<Type> poly1, Polynomial<Type> poly2) {
		Polynomial<Type> subtrahend(poly2);
		Polynomial<Type> result(poly1);
		Type resultConstant;
		int i = 0, j = 0;

		subtrahend.Invert();

		for (Monomial<Type>& subtrahendMon : subtrahend.monomials_)
		{
			for (Monomial<Type>& minuendMon : poly1.monomials_) {

				if (minuendMon == subtrahendMon)
				{
					result.monomials_[i].SetCoefficient(minuendMon.GetCoefficient() + subtrahendMon.GetCoefficient());
					break;
				}
				j++;
			}
			if (j == subtrahend.monomials_.size())
				result.monomials_.push_back(subtrahendMon);
			j = 0;
			i++;

		}

		result.CleanMonomials();

		resultConstant = result.GetConstant() + subtrahend.GetConstant();
		result.SetConstant(resultConstant);
		result.PrintPolynomial();
	};



}