#ifndef WORDS_H
#define WORDS_H

#include <bitset>

constexpr int maxNumberSize{ 9 };
constexpr int tripletSize{ 3 };
constexpr int countDigitVariants{ 10 };
constexpr int countTripletVariants{ 3 };

constexpr char* signWords [2]
{
    "минус",
    ""
};

const char* nullWords [2]
{
    "ноль",
    ""
};

const char* oneMaleWords [countDigitVariants]
{
    ""      ,
    "один"  ,
    "два"   ,
    "три"   ,
    "четыре",
    "пять"  ,
    "шесть" ,
    "семь"  ,
    "восемь",
    "девять"
};
const char* tenMaleWords [countDigitVariants]
{
    ""           ,
    "десять"     ,
    "двадцать"   ,
    "тридцать"   ,
    "сорок"      ,
    "пятдесят"   ,
    "шестьдесят" ,
    "семьдесят"  ,
    "восемьдесят",
    "девяносто"
};
const char* hundredMaleWords [countDigitVariants]
{
    ""         ,
    "сто"      ,
    "двести"   ,
    "тристо"   ,
    "четыресто",
    "пятьсот"  ,
    "шестьсот" ,
    "семьсот"  ,
    "восемьсот",
    "девятьсот"
};
const char* teenMaleWords [countDigitVariants]
{
    "десять"        ,
    "одиннадцать"   ,
    "двенадцать"    ,
    "тринадцать"    ,
    "четырнадцать"  ,
    "пятнадцать"    ,
    "шестнадцать"   ,
    "семнадцать"    ,
    "восемнадцать"  ,
    "девятнадцать"
};
const char* oneFemaleWords [countDigitVariants]
{
    oneMaleWords[0],
    "одна"         ,
    "две"          ,
    oneMaleWords[3],
    oneMaleWords[4],
    oneMaleWords[5],
    oneMaleWords[6],
    oneMaleWords[7],
    oneMaleWords[8],
    oneMaleWords[9]
};

const char** defaultDigits [maxNumberSize]
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

constexpr std::bitset<maxNumberSize> teensPositions{ 0b010'010'010 };

const char* onesTriplet [countTripletVariants]
{
    "",
    "",
    ""
};
const char* thousandsTriplet [countTripletVariants]
{
    "тысяча",
    "тысячи",
    "тысяч"
};
const char* millionsTriplet [countTripletVariants]
{
    "миллион"  ,
    "миллиона" ,
    "миллионов"
};

const char* rublesWords [countTripletVariants]
{
    "рубль" ,
    "рубля" ,
    "рублей"
};

const char** defaultTriplets [tripletSize]
{
    onesTriplet,
    thousandsTriplet,
    millionsTriplet
};

constexpr int tripletNameByDigit [countDigitVariants]
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

#endif // WORDS_H
