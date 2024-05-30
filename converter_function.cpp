#include "converter_function.h"

#include "words.h"

std::string numToTxt(const int number)
{
    uint digits[maxSize] {0};
    Order orders[maxSize]
    {
        one,
        ten,
        hundred,
        one,
        ten,
        hundred,
        one,
        ten,
        hundred
    };
    const char** masks[maxSize]
    {
        oneMaleWords,
        tenMaleWords,
        hundredMaleWords,
        oneFemaleWords,
        tenMaleWords,
        hundredMaleWords,
        oneMaleWords,
        tenMaleWords,
        hundredMaleWords
    };
    std::bitset<maxSize> visibility;
    bool isNegative{ number < 0 };
    bool isNull{ !number };

    uint size{ getDigitsCount(number) + !number };
    if( size > maxSize )
    {
        return "Число слишком большое";
    }

    int tmpNumber = std::abs(number);
    for (uint i = 0; tmpNumber != 0; ++i)
    {
        digits[i] = tmpNumber % 10;
        visibility[i] = digits[i];
        if( isTeen(digits[i], orders[i]) )
        {
            masks[i-1] = teenMaleWords;
            orders[i-1] = teen;
            visibility[i-1] = true;
            visibility[i] = false;
        }
        tmpNumber /= 10;
    }
    visibility[0] = visibility[0] || isNull;

    std::stringstream stream;
    stream << sign[isNegative];
    for (int i = size-1; i >= 0; --i)
    {
        if( visibility[i] )
        {
            stream << toChar(digits[i], masks[i]) << ' ';
        }
        if( needAddSectorName(orders[i], i, visibility) )
        {
            stream << getSectorName(digits[i], i, orders[i]) << ' ';
        }
    }

    return stream.str();
}

uint getDigitsCount(int number)
{
    return static_cast<uint>(std::ceil(std::log10(std::abs(number) + 1)));
}

bool isTeen(const uint digit, const Order order)
{
    return digit == 1 && order == ten;
}

const char* toChar(const uint digit, const char** mask)
{
    return *(mask + digit);
}

bool needAddSectorName(const Order order, const uint posInNumber, const std::bitset<maxSize>& visibility)
{
    if( order && order != teen )
    {
        return false;
    }
    return visibility[posInNumber] || visibility[posInNumber+1] || visibility[posInNumber+2];
}

const char* getSectorName(const uint digit, const uint posInNumber, const Order order)
{
    static const uint tripletNameByDigit[10]
    {
        2,
        0,
        1,
        1,
        1,
        2,
        2,
        2,
        2,
        2
    };
    const char** nameMask{ *(tripletNames + tripletNumber(posInNumber)) };
    if( order )
    {
        return nameMask[2];
    }
    return *(nameMask + tripletNameByDigit[digit]);
}

uint tripletNumber(const uint posInNumber)
{
    return static_cast<uint>(posInNumber/3);
}
