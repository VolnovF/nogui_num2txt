#include <iostream>
#include <string>
//#include <stdio.h>
//#include <locale>

#include "numtotxt.h"
//#include "Windows.h"

int main()
{
    //setlocale(LC_ALL, "Rus");
    auto converter = NumToTxt();
    std::string number;
    std::string text;
    bool ok {true};
    char continueCycle {'y'};
    while (continueCycle != 'n')
    {
        std::cout << "\nВведите число: ";
        std::cin >> number;
        ok = converter.setNumber(number);
        if (ok)
        {
            text = converter.toText();
            std::cout << "Пропись: " << text << '\n';
        }
        else
        {
            std::cout << "Ошибка в преобразовании\n";
        }
        std::cout << "Продолжить? (y/n): ";
        std::cin >> continueCycle;
        //continueCycle = getchar();
    };
    return 0;
}
