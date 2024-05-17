#include "converter_function.h"

#include "words.h"

constexpr uint maxSize{ 9 };

const uint nameVariantByOne [10]
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

const char** defaultMask [maxSize]
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

std::string NumToTxt(int number)
{
    Digit digits [maxSize]
    {
        {0, 0, 0, defaultMask[0]},
        {0, 0, 1, defaultMask[1]},
        {0, 0, 2, defaultMask[2]},
        {0, 1, 0, defaultMask[3]},
        {0, 1, 1, defaultMask[4]},
        {0, 1, 2, defaultMask[5]},
        {0, 2, 0, defaultMask[6]},
        {0, 2, 1, defaultMask[7]},
        {0, 2, 2, defaultMask[8]}
    };

    bool isNegative{ number < 0 };
    bool isNull{ !number };
    uint size{ getDigitsCount(number) + !number };
    int tmpNumber = std::abs(number);
    for (uint i = 0; tmpNumber != 0; ++i)
    {
        if( i >= maxSize )
        {
            return "Число слишком большое";
        }
        digits[i].value = tmpNumber % 10;
        digits[i].visibility = digits[i].value;
        if( digits[i].isTeen() )
        {
            digits[i-1].mask = teenMaleWords;
            digits[i-1].order = 3;
            digits[i-1].visibility = true;
            digits[i].visibility = false;
        }
        tmpNumber /= 10;
    }
    digits[0].visibility += isNull;

    std::stringstream stream;
    stream << sign[isNegative];
    for (int i = size-1; i >= 0; --i)
    {
        if( digits[i].visibility )
        {
            stream << digits[i].toChar() << ' ';
        }
        if( needAddSectorName(&digits[i]) )
        {
            stream << getSectorName(digits[i]) << ' ';
        }
    }

    return stream.str();
}

uint getDigitsCount(int number)
{
    return static_cast<uint>(std::ceil(std::log10(std::abs(number) + 1)));
}

bool Digit::isTeen()
{
    return value == 1 && order == 1;
}

const char *Digit::toChar()
{
    return *(mask + value);
}

const char *getSectorName(const Digit &one)
{
    const char** nameMask{ *(sectorsNames + one.rank) };
    if( one.order > 0 )
    {
        return nameMask[2];
    }
    return *(nameMask + nameVariantByOne[one.value]);
}

bool needAddSectorName(const Digit *one)
{
    if( one->order && one->order<3 )
    {
        return false;
    }
    const Digit* ten{ one+1 };
    const Digit* hundred{ one+2 };
    return one->visibility + ten->visibility + hundred->visibility;
}
















