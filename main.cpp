#include <iostream>
#include <string>
#include <stdio.h>
//#include <locale>

#include "converter_function.h"
//#include "Windows.h"

int main()
{
    //setlocale(LC_ALL, "Rus");
    //auto converter = NumToTxt();
    int number;
    //std::string text;
    int stop{ 1 };
    while (stop)
    {
        std::cout << "\nВведите число: ";
        std::cin >> number;
        number = 713567;
        //text = NumToTxt(number);
        std::cout << NumToTxt(number) << '\n';
        std::cout << "Что-бы закончить введите 0: ";
        std::cin >> stop;
        //stop = std::getchar();
    };
    return 0;
}
