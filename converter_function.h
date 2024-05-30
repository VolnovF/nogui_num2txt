#ifndef CONVERTER_FUNCTION_H
#define CONVERTER_FUNCTION_H

#include <string>
#include <sstream>
#include <cmath>

using uint = unsigned int;

enum Rank {
    ones,
    thousands,
    millions
};

enum Order {
    one,
    ten,
    hundred,
    teen
};

struct Digit
{
    uint value {0};
    Rank rank;
    Order order;
    const char** mask {nullptr};
    bool visibility {false};

    bool isTeen();
    const char* toChar();
};

std::string NumToTxt(int number);

uint getDigitsCount(int number);
const char* getSectorName(const Digit& digit);
bool needAddSectorName(const Digit* digit);

#endif // CONVERTER_FUNCTION_H
