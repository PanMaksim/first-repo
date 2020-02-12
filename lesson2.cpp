#include <iostream>
#include <limits>
typedef unsigned long long my_time_t;

int main(int argc /*количество аргументов */, const char** argv/*все аргументы*/)
{
    bool b = false;
    float value1;
    double value2;
    long double value3;
    uint32_t value5 = 1;
    uint32_t value6 = std::numeric_limits<uint32_t>::max();
    uint32_t value7 = value6 + 2; //будет переполнение и откат до минимального значения
    uint16_t value8 = 1;
    uint16_t value9{ 20 };
    uint8_t value10 = static_cast <uint8_t>(value9);
    double a  { 1.23 };
    int i = a;
    double d=10;
    auto d_=d; // обязательна инициализация для исп. авто
    decltype(d_) new_; // для присваивания типа переменной
    int j{}; // если писать (),то не {} считаеться ошибкой
    int value11 = 10;
    int value12 = value11;
    auto res = value11 + value12; //если написать int а не auto то будет переполнение
    long rews_1 = value11 - value12; //другой вариант решения через лонг, но авто универсальнее
    /*при цельночисленном делении на ноль будет выдавать ошибку CPU, но при исп. вещественных ошибки не будет, напримпер будет получен "нан"
      *вычисления могут идти справо-налево, скобки ограничивают это (действие из скобок выделит как отдельную переменную
       (lvalue если можем взять адресс,для дальнейшего применения lvalue нужно использовать & перед переменной),
        иногда лучше самому вынести это как отдельную переменную), можно проверить на compiler exlorer*/
    int g;
    ++g; //
    std::cout << b << std::endl;
    std::cout << sizeof(bool)<<std::endl;
    std::cout << value5 << std::endl;
    std::cout << value6 << std::endl;
    std::cout << value7 << std::endl;
    std::cout << value8 << std::endl;
    std::cout << i << std::endl;
    std::cout << value10 << std::endl;
    std::cout << d << std::endl;
    std::cout << i << std::endl;
    std::cout << res << std::endl;
    std::cout << rews_1 << std::endl;
    return 0;


}