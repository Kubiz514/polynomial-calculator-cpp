#pragma once
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

