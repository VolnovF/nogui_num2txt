#include "digit.h"

Digit::Digit()
{

}

bool Digit::valueFromChar(char symbol)
{
    if (isdigit(symbol))
    {
        value = symbol - '0';
        return true;
    }
    else
    {
        return false;
    }
}

const char *Digit::toChar() const
{
    if (!mask)
    {
        //return "";
        return nullptr;
    }
    return mask[value];
}

bool Digit::isTeen() const
{
    return (order == 1 && value == 1);
}

bool Digit::isFemale() const
{
    return (sector == 1 && order == 0 && value <= 2);
}

std::ostream &operator<<(std::ostream &stream, const Digit &digit)
{
    if (digit.toChar())
    {
        stream << digit.toChar();
    }
    return stream;
}
