#ifndef CONVERTER_FUNCTION_H
#define CONVERTER_FUNCTION_H

#include <string>
#include <sstream>
#include <cmath>

using uint = unsigned int;

struct Digit
{
    uint value {0};
    uint sector {0};
    uint order {0};
    const char** mask {nullptr};
    bool isVisible {false};
    bool isTeen();
    const char* toChar();
};

std::string NumToTxt(int number);

uint getDigitsCount(int number);
const char* getSectorName(const Digit& one);
bool needAddSectorName(const Digit* digit);

#endif // CONVERTER_FUNCTION_H
