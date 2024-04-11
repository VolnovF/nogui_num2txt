#include "numtotxt.h"

NumToTxt::NumToTxt()
{
    uint sector{ 0 };
    uint order{ 0 };

    for (uint i = 0; i < maxSize; ++i)
    {
        number[i].sector = sector;
        number[i].order = order;

        ++order;
        if (order == 3)
        {
            ++sector;
            order = 0;
        }
    }
}

NumToTxt::NumToTxt(const std::string& StrNumber)
    : NumToTxt()
{
    setNumber(StrNumber);
}

bool NumToTxt::setNumber(const std::string& StrNumber)
{
    clear();

    if (StrNumber[0] == '-')
    {
        numberIsNegative = true;
    }

    uint digitCounter{ 0 };
    bool result;
    for (int i = StrNumber.size() - 1; i >= (int)numberIsNegative; --i)
    {
        if (digitCounter > maxSize)
        {
            clear();
            return false;
        }

        result = number[digitCounter].valueFromChar(StrNumber[i]);
        if (!result)
        {
            clear();
            return false;
        }
        ++digitCounter;
    }
    size = digitCounter;
    return true;
}

void NumToTxt::setDigitMask(Digit &digit)
{
    if (digit.value == 0)
    {
        return;
    }

    switch ( digit.order ) {
    case 0:
        digit.mask = units; break;
    case 1:
        digit.mask = tens; break;
    case 2:
        digit.mask = hundreds; break;
    default:
        return;
    };

    if (digit.isTeen())
    {
        digit.mask = nullptr;
        Digit& unit = getUnit(digit.sector);
        unit.mask = teens;
    }
    if (digit.isFemale())
    {
        digit.mask = unitsFemale;
    }
}

std::string NumToTxt::toText()
{
    if ( numberIsNull() )
    {
        return "ноль рублей";
    }

    for (uint i = 0; i < size; ++i)
    {
        setDigitMask( number[i] );
    }

    std::stringstream stream;
    if (numberIsNegative)
    {
        stream << "минус" << ' ';
    }
    Digit digit;
    for (int sector = countActiveSectors() - 1; sector >= 0; --sector)
    {
        if ( !sectorIsNeeded(sector) )
        {
            continue;
        }
        for (int order = 2; order >= 0; --order)
        {
            digit = getDigit(sector, order);
            if (digit.toChar())
            {
                stream << digit << ' ';
            }
        }
        stream << getSectorName(sector) << ' ';
    }

    std::string text{ stream.str() };
    return text;
}

Digit &NumToTxt::getDigit(uint sector, uint order)
{
    uint index{ sector * 3 + order };
    return number[index];
}

Digit &NumToTxt::getUnit(uint sector)
{
    return getDigit(sector, 0);
}

Digit &NumToTxt::getTen(uint sector)
{
    return getDigit(sector, 1);
}

Digit &NumToTxt::getHundred(uint sector)
{
    return getDigit(sector, 2);
}

const char *NumToTxt::getSectorName(uint sector)
{
    const char** nameMask;
    switch (sector) {
    case 0:
        nameMask = rubel; break;
    case 1:
        nameMask = thousand; break;
    case 2:
        nameMask = million; break;
    default:
        return nullptr;
    }

    if ( getTen(sector).isTeen() )
    {
        return nameMask[2];
    }

    Digit unit{ getUnit(sector) };
    if ( unit.value > 4 || unit.value == 0 )
    {
        return nameMask[2];
    }
    if ( unit.value > 1 )
    {
        return nameMask[1];
    }
    return nameMask[0];
}

bool NumToTxt::sectorIsNull(uint sector)
{
    for (uint i = sector * 3; i < sector * 3 + 3; ++i)
    {
        if (number[i].value != 0)
        {
            return false;
        }
    }
    return true;
}

bool NumToTxt::sectorIsNeeded(uint sector)
{
    return (!sectorIsNull(sector) || sector == 0);
}

bool NumToTxt::numberIsNull()
{
    for (uint i = 0; i < size; ++i)
    {
        if (number[i].value != 0)
        {
            return false;
        }
    }
    return true;
}

uint NumToTxt::countActiveSectors()
{
    return std::ceil( size/3.0 );
}

void NumToTxt::clear()
{
    for (uint i = 0; i < maxSize; ++i)
    {
        number[i].value = 0;
        number[i].mask = nullptr;
    }
    size = 0;
    numberIsNegative = false;
}

uint NumToTxt::getSize() const
{
    return size;
}

