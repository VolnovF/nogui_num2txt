#include "converter_function.h"

#include "words.h"

static constexpr uint tripletNameByDigit[10]
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

std::string numToTxt(const int number)
{
    uint digits[maxSize] {0};
    std::bitset<maxSize> teens;
    uint size{ getDigitsCount(number)};
    if( size > maxSize )
    {
        return "Число слишком большое";
    }

    int tmpNumber = std::abs(number);
    for (uint i = 0; tmpNumber != 0; ++i)
    {
        digits[i] = tmpNumber % 10;
        if( isTeen(digits[i], i) )
        {
            teens.set(i-1);
            digits[i] = 0;
        }
        tmpNumber /= 10;
    }

    std::stringstream stream;
    insertSign(stream, number);
    for (int i = size-1; i >= 0; --i)
    {
        insertDigit(stream, digits[i], i, teens.test(i));
        if( isEndOfTriplet(i) )
        {
            insertTripletName(stream, digits, i, teens.test(i));
        }
    }
    insertNull(stream, number);
    insertCurrency(stream , digits[0], teens.test(0));

    return stream.str();
}

void insertWithSpace(std::stringstream &stream, const char *word)
{
    stream << word;
    if ( word != nullptr && *word != '\0' )
    {
        stream << ' ';
    }
}

void insertSign(std::stringstream &stream, const int number)
{
    insertWithSpace(stream, signWords[number >= 0]);
}

void insertDigit(std::stringstream& stream, const uint digit, const uint position, const bool isTeen)
{
    static const char** defaultDigits[maxSize]
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
    insertWithSpace(stream, *((isTeen ? teenMaleWords : defaultDigits[position]) + digit));
}

void insertTripletName(std::stringstream& stream, const uint* digits, const uint position, const bool isTeen)
{
    if( tripletIsEmpty(digits, position, isTeen) )
    {
        return;
    }
    static const char** defaultTriplets [3]
    {
        onesTriplet,
        thousandsTriplet,
        millionsTriplet
    };
    const char** thisTriplet{ *(defaultTriplets + tripletPosition(position)) };
    const char* tripletName{ *(thisTriplet + (isTeen ? 2 : tripletNameByDigit[digits[position]])) };
    insertWithSpace(stream, tripletName);
}

void insertNull(std::stringstream &stream, const int number)
{
    insertWithSpace(stream, nullWords[static_cast<bool>(number)]);
}

void insertCurrency(std::stringstream &stream, const uint digit, const bool isTeen)
{
    const char** currency{ rublesWords };
    stream << *(currency + (isTeen ? 2 : tripletNameByDigit[digit]));
}

uint getDigitsCount(int number)
{
    return static_cast<uint>(std::ceil(std::log10(std::abs(number) + 1)));
}

bool isTeen(const uint digit, const uint posInNumber)
{
    static constexpr std::bitset<maxSize> teensMask{ 0b010'010'010 };
    return digit == 1 && teensMask.test(posInNumber);
}

bool tripletIsEmpty(const uint *digits, const uint position, const bool isTeen)
{
    return !(digits[position] + digits[position+1] + digits[position+2] + isTeen);
}

uint tripletPosition(const uint position)
{
    return static_cast<uint>(position / tripletSize);
}

bool isEndOfTriplet(const uint position)
{
    return !(position % tripletSize);
}
