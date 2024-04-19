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
    bool isHidden {true};
    bool isTeen();
    void setHidden();
    const char* toChar();
};

enum WordGender
{
    Male = 0,
    Female = 1
};

std::string NumToTxt(int number);

uint id(uint sector, uint order);
uint getDigitsCount(int number);
const char** getMask(uint id, const Digit& digit);
const char* getSectorName(const Digit& one);
bool sectorIsHidden(const Digit* one);

uint biggestFilledSector(uint size);

#endif // CONVERTER_FUNCTION_H
