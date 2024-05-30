#include "converter_function.h"

#include "words.h"

constexpr uint maxSize{ 9 };

/*const char** defaultMask [maxSize]
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
};*/

std::string NumToTxt(int number)
{
    Digit digits [maxSize]
    {
        {0, ones, one, oneMaleWords},
        {0, ones, ten, tenMaleWords},
        {0, ones, hundred, hundredMaleWords},
        {0, thousands, one, oneFemaleWords},
        {0, thousands, ten, tenMaleWords},
        {0, thousands, hundred, hundredMaleWords},
        {0, millions, one, oneMaleWords},
        {0, millions, ten, tenMaleWords},
        {0, millions, hundred, hundredMaleWords}
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
            digits[i-1].order = teen;
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
    return value == 1 && order == ten;
}

const char *Digit::toChar()
{
    return *(mask + value);
}

const char *getSectorName(const Digit &digit)
{
    static const uint nameVariantByOne [10]
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
    const char** nameMask{ *(sectorsNames + digit.rank) };
    if( digit.order > one )
    {
        return nameMask[2];
    }
    return *(nameMask + nameVariantByOne[digit.value]);
}

bool needAddSectorName(const Digit *digit)
{
    if( digit->order && digit->order < teen )
    {
        return false;
    }
    const Digit* ten{ digit+1 };
    const Digit* hundred{ digit+2 };
    return digit->visibility + ten->visibility + hundred->visibility;
}
















