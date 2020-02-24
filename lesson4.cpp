#include <iostream>
#include <cmath>
enum {
    FIRST,
    SECOND,
    LAST
};
int main(int argc, char const *argv[])
{
    int array1[2] = { 1,2 }; /*вводим масив на 2 елемента; 
                              *компилятор может сам вывести размер масива, 
                              *если его не указать в зависимости от количества указаных елементов внутри
                              *можно ввести константный масив, но только если указать все его елементы*/
    std::cout << array1[1] << std::endl; // на месте 1 можно так же писать целые переменные

    int array2[10] = { 1 }; //все елементы после заданой 1 равны нулям
    double array3[4] = {};   //все елементы масива равны нулям
    const int array4[LAST]{ 54,55 };
    char karray5[]{ "HElloWorld" }; /*компилятор добавит нультерминальный скрытый символ \0', 
                                     *компилятор всегда в чаре будет добавлять 1 системный символ 
                                     *но если все символы самому прописать через запятые то \0' не будет добавлять*/
    const size_t kSizeArray{ 5 };
    int value[kSizeArray]{ 1,2,3 };
    for (size_t i = 1; i < kSizeArray; i++)
        {
        std::cout << value[i] << std::endl;
        }
    std::cout << sizeof(value) << std::endl;

    char ch_ar[]{ "Hello" };
    std::cout << sizeof(ch_ar) << std::endl; //выводит размер ch_ar

    std::cout << sizeof(value) / sizeof(value[0]) << std::endl; /*sizeof работает только с типами
                                                                 *например если написать заместь 0 четыре млн то оно всеравно посчитает 
                                                                  *потому что заместь 4 млн поставит тип переменной что равна 4 млн*/
    //std::size //c C++17
    for (auto i: value) { //для обхода всей последовательности используют for
        std::cout << i << std::endl;
    }

    std::cout << ch_ar << std::endl;

    /*int value3{ 10 };
    int* value3_ptr = &value3; // &value означает что мы ссылаемся на адрес value
    std::cout << &value3 << "" << &value3_ptr << std::endl;
    std::cout << value3 << "" << value3_ptr << std::endl;
    int *value3_ptr = nullptr; /* указателю из литералов можно указывать только 0, но это тоже несет проблемы
                                * лучше указывать только nullptr*/
    //std::cout << value3 << "" << value3_ptr << std::endl;*/

    /*void* ptr = &value; //void* позволяет обмануть ограничения и преобразовывать то что обычно не разрешает
    double d{ 1 };
    ptr = &d;
    *(static_cast<int*>(ptr)) = 300;
    std::cout << d<< std::endl;*/ //ссылаясь с меньшего типа на больший с помощью обмана, мы кораптим память

    char char1;
    std::cin >> char1;
    std::cout << char1 << std::endl;
    return 0;
}
