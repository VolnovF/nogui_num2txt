#ifndef WORDS_H
#define WORDS_H

static constexpr char* signWords [2]
{
    "минус",
    ""
};

const char* nullWords [2]
{
    "ноль",
    ""
};

const char* oneMaleWords [10]
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
const char* tenMaleWords [10]
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
const char* hundredMaleWords [10]
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
const char* teenMaleWords [10]
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
const char* oneFemaleWords [10]
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

const char* onesTriplet [3]
{
    "",
    "",
    ""
};
const char* thousandsTriplet [3]
{
    "тысяча",
    "тысячи",
    "тысяч"
};
const char* millionsTriplet [3]
{
    "миллион"  ,
    "миллиона" ,
    "миллионов"
};

const char* rublesWords [3]
{
    "рубль" ,
    "рубля" ,
    "рублей"
};

#endif // WORDS_H
