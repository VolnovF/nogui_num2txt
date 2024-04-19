#include "converter_function.h"

#include "words.h"

constexpr uint maxSize{ 9 };

const WordGender digitsGender [maxSize]
    {
        Male,
        Male,
        Male,
        Female,
        Male,
        Male,
        Male,
        Male,
        Male
    };

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

std::string NumToTxt(int number)
{
    Digit digits [maxSize]
    {
        {0, 0, 0},
        {0, 0, 1},
        {0, 0, 2},
        {0, 1, 0},
        {0, 1, 1},
        {0, 1, 2},
        {0, 2, 0},
        {0, 2, 1},
        {0, 2, 2}
    };

    bool numberIsNegative{ number < 0 };
    number = std::abs(number);
    uint size{ getDigitsCount(number) + !number };

    for (int i = 0, tmpNumber = number; tmpNumber != 0; ++i)
    {
        if( i >= maxSize )
        {
            return "Число слишком большое";
        }
        digits[i].value = tmpNumber % 10;
        tmpNumber /= 10;
    }

    for (uint i = 0; i < size; ++i)
    {
        if( digits[i].isTeen() )
        {
            digits[i-1].order = 3;
            digits[i-1].mask = getMask(i-1, digits[i-1]);
            digits[i-1].isHidden = false;
        }
        else
        {
            digits[i].mask = getMask(i, digits[i]);
            digits[i].setHidden();
        }
    }
    if( !number )
    {
        digits[0].isHidden = false;
    }

    std::stringstream stream;
    stream << sign [numberIsNegative];
    for (int sector = biggestFilledSector(size); sector >= 0; --sector)
    {
        if( sectorIsHidden( &digits [sector*3] ) )
        {
            continue;
        }
        for (int order = 2; order >= 0; --order)
        {
            Digit& digit{ digits [id(sector, order)] };
            if( !digit.isHidden )
            {
                stream << digit.toChar() << ' ';
            }
        }
        stream << getSectorName( digits [sector*3] ) << ' ';
    }

    std::string text{ stream.str() };
    return text;
}

uint id(uint sector, uint order)
{
    return sector*3 + order;
}

uint getDigitsCount(int number)
{
    return static_cast<uint>(std::ceil(std::log10(number + 1)));
}

bool Digit::isTeen()
{
    return value == 1 && order == 1;
}

void Digit::setHidden()
{
    if( !mask )
    {
        isHidden = true;
    }
    else
    {
        isHidden = value == 0;
    }
}

const char *Digit::toChar()
{
    return (isHidden ? nullptr : *(mask + value));
}

const char **getMask(uint id, const Digit& digit)
{
    return *(digitsWords + digitsGender[id]*4 + digit.order);
}

uint biggestFilledSector(uint size)
{
    return std::ceil( size/3.0 ) - 1;
}

const char *getSectorName(const Digit &one)
{
    const char** nameMask{ *(sectorsNames + one.sector) };
    if( one.order > 0 )
    {
        return nameMask[2];
    }
    return *(nameMask + nameVariantByOne[one.value]);
}

bool sectorIsHidden(const Digit* one)
{
    const Digit* ten{ one+1 };
    const Digit* hundred{ one+2 };
    return one->isHidden + ten->isHidden + hundred->isHidden == 3 && one->sector != 0;
}


