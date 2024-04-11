#ifndef NUMTOTXT_H
#define NUMTOTXT_H

#include <string>
#include <sstream>
#include <math.h>

#include "digit.h"

//#include "qtypes.h"
using uint = unsigned int;

class NumToTxt
{
private:
    static constexpr uint maxSize {9};
    Digit number [maxSize];
    uint size {0};
    bool numberIsNegative {false};
public:
    NumToTxt();
    NumToTxt(const std::string& StrNumber);
    uint getSize() const;
    bool setNumber(const std::string& StrNumber);
    std::string toText();
    void clear();
private:
    void setDigitMask(Digit& digit);
    Digit& getDigit(uint sector, uint order);
    Digit& getUnit(uint sector);
    Digit& getTen(uint sector);
    Digit& getHundred(uint sector);
    const char* getSectorName(uint sector);
    bool sectorIsNull(uint sector);
    bool sectorIsNeeded(uint sector);
    bool numberIsNull();
    uint countActiveSectors();
    static const inline char* units [10]
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
    static const inline char* tens [10]
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
    static const inline char* teens [10]
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
    static const inline char* hundreds [10]
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
    static const inline char* unitsFemale [3]
    {
        "ноль",
        "одна",
        "две"
    };
    static const inline char* rubel [3]
    {
        "рубль",
        "рубля",
        "рублей"
    };
    static const inline char* thousand [3]
    {
        "тысяча",
        "тысячи",
        "тысяч"
    };
    static const inline char* million [3]
    {
        "миллион",
        "миллиона",
        "миллионов"
    };
};

#endif // NUMTOTXT_H
