#ifndef CONVERTER_FUNCTION_H
#define CONVERTER_FUNCTION_H

#include <string>
#include <sstream>
#include <cmath>
#include <bitset>

using uint = unsigned int;

constexpr uint maxSize{ 9 };
constexpr uint tripletSize{ 3 };

std::string numToTxt(const int number);

void insertSign(std::stringstream& stream, const int number);
void insertDigit(std::stringstream& stream, const uint digit, const uint position, const bool isTeen);
void insertTripletName(std::stringstream& stream, const uint* digits, const uint position, const bool isTeen);
void insertNull(std::stringstream& stream, const int number);
void insertCurrency(std::stringstream& stream, const uint digit, const bool isTeen);

uint getDigitsCount(int number);
bool isTeen(const uint digit, const uint position);
bool isEndOfTriplet(const uint position);
bool tripletIsEmpty(const uint* digits, const uint position, const bool isTeen);
uint tripletPosition(const uint posInNumber);

void insertWithSpace(std::stringstream& stream, const char* word);

#endif // CONVERTER_FUNCTION_H
