#ifndef DIGIT_H
#define DIGIT_H

#include <iostream>
#include <cctype>

//#include "qtypes.h"
using uint = unsigned int;

class Digit
{
public:
    uint value {0};
    uint sector {0};
    uint order {0};
    const char** mask {nullptr};
public:
    Digit();
    bool valueFromChar(char symbol);
    const char* toChar() const;
    bool isTeen() const;
    bool isFemale() const;
};

std::ostream& operator<<(std::ostream& stream, const Digit& digit);

#endif // DIGIT_H
