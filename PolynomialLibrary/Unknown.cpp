#include "Unknown.h"

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