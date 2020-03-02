#include <iostream>
#include <functional>

//bool More(int a, int b) {
//    return a > b;
//}
//bool Less(int a, int b) {
//    return a < b;
//} //через Море, Лесс больше не пишут

//@-означает написано уже другой код
// @сигнатура функции
//разные сигнатуры - разные входные параметры

//typedef bool (*Comp) (int, int); // превратили Comp в тип
// лучше избегать typedef в новых форматах и использовать using
using Comp = std::function<bool(int, int)>;

using Comp_Find = bool (*)(int);

void sort(int* begin, const int* const end, Comp cmp) { // @Comp еще часто указывают как (*Comp)
    //cmp - лямбда
    std::cout << __PRETTY_FUNCTION__ << std::endl; //для дебага, выводит аргументы функций
    if (begin == nullptr || end == nullptr || begin == end) {
        return;
    }
    for (int* it_level1 = begin; it_level1 != end; ++it_level1) {
        for (int* it_level2 = it_level1 + 1;it_level2 != end;++it_level2) {
            if (cmp(*it_level1, *it_level2)) { //@тут ограничение что мы сортируем только в 1 сторону (после добавления ордера начали сортировать в обе стороны)
                int tmp = *it_level1;
                *it_level1 = *it_level2;
                *it_level2 = tmp;
            }
        }
    }
    //большой минус этого сорта что он работает только с интом
}

bool Equal_45(int current) {
    return current == 45;
} // Если мы ищем число 45

int is_even(int current) {
    return current % 2 == 0;
}


bool find_fist_of(int* begin, const int* const end, Comp_Find cmp) {
    if (begin == nullptr || end == nullptr || begin == end) {
        return false;
    }
    for (int* it_level1 = begin; it_level1 != end; ++it_level1) {
        if (cmp(*it_level1)) {
            return true;
        }
    }
    return false;
}

inline bool IsEven(int value) { return value % 2 == 0; }
//inline подсказывает компилятору как ему лучше подставить, но это уже устаревший способ, потому что компилятор уже сам лучше знает


int main(int argc, char const* argv[])
{
    //нельзя обьявлять функцию внутри другой функции, только классы можно обьявлять внури функций (локальные классы)
    const int kSize{ 6 };
    int array[kSize]{ 3,1,9,3,5,7 };
    sort(array, array + kSize, [](int a, int b) ->bool {
        return a > b;
        });
        // [] означает что мы добавляем необьявленую функцию, это самое сложное оно добавляет много подводных камней
        //здесь можно писать сколько угодно функций, как в обычном теле, но так не стоит писать, потому что если она содержит больше 5 строк,
        //то лучше вынести уже как отельную функцию наверх
        //эта функция [](int a, int b) ->bool {} назыв. лямбда
         //тоже самое что если бы писали сверху через иф/елсе но более коротко
    /* другой вариант написания 
    auto more = [](int a, int b) ->bool {
        return a > b;};
    //для лямбды всегда писать авто
    sort(array, array + kSize, more);*/
    for (auto var : array) {
        std::cout << var << "";
    }
    std::cout << std::endl;
    std::cout << std::boolalpha; // буллальфа дает тру/фолс заместь 0/1
    //std::cout << find_fist_of(array, array + kSize, [](int a) ->bool {return a%2==0;});
    int find_value{};
    std::cin >> find_value;
    std::cout << find_fist_of(array, array + kSize, [&find_value](int a) mutable {
        //[&f_v] - когда захватываем {int a} - когда уже изменяем
    find_value++;//в рамках этого тела она константная,т.к мы её захватили, значит мы не можем её менять
    // но mutable позволяет нам её менять
    // т.к. мы её захватили через ссылку то мы поулчим уже изменное значение, напримем 106 заместо 100, что показывает сколько раз мы прошли
    // то что мы захватили по ссылке тоже обезпечивает возможность изменения
    return a == find_value;
        });



    std::cout << std::boolalpha;
    std::cout << IsEven(2) << std::endl;
    // так это будет подставлять комплиятор std::cout << (2%2==0) << std::endl;


    return 0;
}

// полиморфизм - одно имя, несколько реализаций; компилятор может по разному реализовать; бывает статическим и динамическим
// статический - компилятор выберает правильную перегрузку вызова функции (метод вызова) на основе типов аргументов
// null можно подставить как int так и указатель
// nullptr только как указатель
// если пропишем void test и double test компилятору будет всеравно, он будет видеть их как одинаковые
// при вызове функции компилятор игнорирует константность при выборе лучшей функции (например int и const int)
// (для компилятора) указатель на int* и const int* совершенно разные типы, так же со ссылками
// int* и int* const тоже разные потому что на выходе получаем разное (например testPi (pointer int) и testPKi (pointer const int))
// (для компилятора) указатель - адрес на обьект, ссылка - тот же обьект (но в памяти ссылка как указатель; ссылка всегда прийдет как валидная(не nullptr))
// inline говорит что функция
