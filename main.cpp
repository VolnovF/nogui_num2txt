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
    char input{'y'};
    while (input != 'n')
    {
        std::cout << "\nВведите число: ";
        std::cin >> number;
        std::cout << numToTxt(number) << '\n';
        std::cout << "Чтобы закончить введите n: ";
        std::cin >> input;
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    };
    return 0;
}
