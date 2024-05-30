#ifndef CONVERTER_FUNCTION_H
#define CONVERTER_FUNCTION_H

#include <string>
#include <sstream>
#include <cmath>
#include <bitset>

using uint = unsigned int;

constexpr uint maxSize{ 9 };

enum Order {
    one,
    ten,
    hundred,
    teen
};

std::string numToTxt(const int number);

uint getDigitsCount(int number);
bool isTeen(const uint digit, const Order order);
const char* toChar(const uint digit, const char** mask);
bool needTripletName(const Order order, const uint posInNumber, const std::bitset<maxSize>& visibility);
const char* getTripletName(const uint digit, const uint posInNumber, const Order order);
uint tripletNumber(const uint posInNumber);

#endif // CONVERTER_FUNCTION_H
