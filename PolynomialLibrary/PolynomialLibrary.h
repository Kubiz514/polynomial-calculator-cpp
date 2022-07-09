#include <string>
#include <vector>
#include <string>
#pragma once

namespace PolynomialLibrary
{
	template<typename Type>
	class Monomial;

	class Unknown {
	private:
		char letter_;
		int exponent_;
	public:
		Unknown(char letter, int exponent);
		void SetLetter(char letter);
		char GetLetter();
		void SetExponent(char exponent);
		int GetExponent();
	};

	template <typename Type> 
	bool operator==(const Monomial<Type>& left, const Monomial<Type>& right);

	template <typename Type>
	class Monomial
	{
	private:
		friend bool operator==<Type>(const Monomial& left, const Monomial& right);
		Type coefficient_;
	public:
		std::vector<Unknown> variables_;

		Monomial(Type coefficient, std::vector<Unknown> variables);

		void SetCoefficient(Type coefficient);
		Type GetCoefficient();
		void PrintMonomial();

	};


	template <typename Type>
	class Polynomial
	{
	private:
		Type constant_;
	public:
		std::vector<Monomial<Type>> monomials_;

		Polynomial(std::vector<Monomial<Type>> monomials, Type *constant);
		Polynomial(Polynomial<Type>& polynomial);

		void SetConstant(Type constant);
		Type GetConstant();

		void CleanMonomials();
		void PrintPolynomial();
		void Invert();
	};

	template <typename Type>
	void Add(Polynomial<Type> poly1, Polynomial<Type> poly2);

	template <typename Type>
	void Substract(Polynomial<Type> poly1, Polynomial<Type> poly2);

}