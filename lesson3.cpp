
#include <iostream>
#include <limits>
#include <bitset>

int main(int argt, char const* arfv[])
{
    size_t value;
    std::cin>> value;
    size_t i{};
    while (i < value) {
        std::cout << ++i << std::endl;
    }


   /* int value{ 12345 };
    for (auto value_copy{ value }; value_copy > 0;value_copy/=10 ) {
        if (value_copy % 10 == 0) {
            std::cout << "even\n";
        }
        else
            std::cout << "odd\n";
        
        return 0;
    }

   /* int iter;
    std::cin >> iter;
    for (size_t i = 1; i < iter; i++) //size_t самый максимальный тип на любой платформе
    {
        std::cout << "before check\n";
        if (i == 2)
            continue;
        std::cout << "i+1\n";
    }

   /*
    enum {
        FIRST=1,
        SECOND,
        UNDEFINED
        /*A='A',
        B,
        C
    };
    int value;
    switch (value)
    {
    case FIRST: /*еще можно 1..10:FIRST
        std::cout << "1" << std::endl;
        break;
      case SECOND:
          std::cout << "2" << std::endl;
      case UNDEFINED:
          std::cout << "undefined" << std::endl;
       default:
          std::cout << "not match" << std::endl;
          break;
    }
 */
    //std::cout << (10 % 2) << std::endl; //остаток от деления исп. для проверки на четность так же для поулчения последних чисел из числа можно поделить на 10, 100 и тд.

    /*int v1{ 1 };
    int v2{ 2 };
    double res = (v1+0.f) / v2; //если не будет 0.ф то число будет округлено до целого числа, в даном случае нуля

    /*int val3{ 2 };
    std::cout << (val3 & 1) <<std::endl;

    /*int val1{ 10 };
    int val2{ 20 };
    uint16_t value = 0b000'000'000'000'000'1;
    std::bitset<8> bit{ 126 };
    std::cout << bit.to_string() << std::endl;
    bit.set(2, false);
    std::cout << bit.to_string() << std::endl;
    std::cout << bit.count() << std::endl;

 /*   std::cout << std::boolalpha;
    bool is_state = (val1 == val2);
    std::cout << is_state << std::endl;
    is_state = { val1 < val2 };
    std::cout << is_state << std::endl;
    bool is_access = val2 < 30 && val2 > 30;
    std::cout << is_access << std::endl;
    bool is_access = val2 < 30 || val2 > 30;
    std::cout << is_access << std::endl;
    bool is_access = !(val2 < 30 || val2 > 30);
    std::cout << is_access << std::endl;*/

    return 0;
}

