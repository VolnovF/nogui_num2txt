#ifndef WORDS_H
#define WORDS_H

const char* sign [2]
{
    "",
    "минус "
};

const char* oneMaleWords [10]
    {
         "ноль"  ,
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
         "ноль"       ,
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
         "ноль"     ,
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

const char* sectorsNames [3] [3]
{
    {
     "рубль" ,
     "рубля" ,
     "рублей"
    },
    {
     "тысяча",
     "тысячи",
     "тысяч"
    },
    {
     "миллион"  ,
     "миллиона" ,
     "миллионов"
    }
};

#endif // WORDS_H
