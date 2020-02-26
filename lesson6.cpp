#include <iostream>
#include <cstring>

#define _UNUSED_

//bool swap(int *const value1, int * const value2) { /* указание константности для аргументов (не указателей!) не мейна может быть исбыточным, 
//                                                    *для указателей константность наоборот может быть важной (но если например const int *ptr, а не когда int* const ptr)
//                                                    *если мы зададим переменные через ссылки & а не через указатели * то начальная проверка нам будет не нужна
//                                                    *но если мы работаем еще с С помимо С++ то нужно будет использовать указатели,
//                                                    *а если используем только С++ то можно обойтись и без указателей
//                                                    */
//    if (value2 == nullptr || value1 == nullptr || value1==value2) { // если заместь || написать | будет проверять все соотношения а не до первого нужного
//        return false; // начальная проверка
//    }
//    int tmp = *value1;
//    *value1 = *value2;
//    *value2 = tmp;
//    return true;
//}

//const size_t kSize{ 5 };
//void print_array(int array[kSize]){ //если просто снова создать новый масив заместь указателя * (лучше указать) будет лишняя копия и ошибка
//                                /* заместь обьема масима можно вводить kSize с заданой величиной, 
//                                 *но только для того что бы заставить обратить внимание на обьем масива
//                                 */
//    for (size_t i{ 0 }; i < kSize; ++i) {
//        std::cout << array[i] << " "<< std::endl;
//    }
//    std::cout << std::endl;
//
//}

//const size_t kSize{ 5 };
//void print(const int *begin, const int * const end) {
//    if (begin == nullptr) //важнее проверять начало (бегин), а не конец (енд) потому что мы его розименовуем
//    {
//        return;
//    }
//    while (begin!=end) {
//        std::cout << *begin++ << " " << std::endl;
//    }
//    std::cout << std::endl;
//
//}

//void promt() {
//    char begin[13]{};
//    std::cin >> begin; //если в аррей через син ввести больше чем обьем масива у нас не будет \0
//    size_t size = strlen(begin);
//    if (size >= 13) {
//        return;
//    }
//}

//void promt(int* value1, int* value2) {
//    if (value1 == nullptr || value2 == nullptr) {
//        std::cout << "Enter values\n";
//        std::cin >> *value1 >> *value2;
//    }
//}

//    int& f1() {
//    int value3;
//    std::cin >> value3;
//}

const size_t Size{5};
void f1(int(&array)[Size]) { // обьявляем статический масив*!!!

}

void f2(int a, int b=10,int c=30 /*int vali _UNUSED_*/) { // ввели аргументам дефолтные значения
                                    // при вводе дефолтных нужно обязательно задавать дефолтные значения последующим переменным
                                    // так же для пропуска ненужных дефолтных можно прописать 0\ 
                                    // *инициализация строковога литерала через char* (-)
    std::cout << a << "\t" << b <<"\t"<<c<< std::endl;
}

 const size_t kSize{ 5 };
void print(const int *begin, const int * const end) {
    if (begin == nullptr) //важнее проверять начало (бегин), а не конец (енд) потому что мы его розименовуем
    {
        return;
    }
    while (begin!=end) {
        std::cout << *begin++ << " " << std::endl;
    }
    std::cout << std::endl;

}

 //void print(int array[]) {
 //    std::cout << sizeof (array) / sizeof (array(0)) <<std::endl;
 //}


size_t IncDecOddEven(size_t value8) {
    int value{ 100 };
    return (value % 2 != 0) ? value + 1 : value - 1;
} //!!!*

int main(int argc, char const *argv[]) 
{
    //int array[5];
    //f1(array);

    int value4{ 100 }, value5{ 300 }, val;
    f2(value4,value5); //!!*


    //int left;
    //int right;
    //std::cout << (left == right) ? "IM luck" : "IM not luck") << std::endl;

    //int* ptr;
    //int& ref = *ptr; // это нормально
    //ref = 300; // вызовет UB

    //char* promt();
    //    char array3[100]{};
    //    auto array3 = promt(); // это висячий указатель (проблема, плохо), UB
    //                           // никогда не возвращать ссылку на локальный компонент функции, всегда возвращать по значению

    //int value1, value2;
    //swap(&value1, &value2);
    //std::cout << value1 << value2 << std::endl;

    //int array[kSize]{ 1,2,3,4,5 };
    //print_array(array, kSize);

    int array[kSize]{ 1,2,3,4,5 };
    print(array, array+kSize);
    int array1[kSize]{};

    memcpy(array1,array,sizeof(int)*kSize);     //memcpy берет кусок памяти для его записи в другой кусок памяти
                                //при навождении курсора на функцию показывает что нужно в нее ввести (dst,stc,size)
    for (auto var : array1) {
        std::cout << var <<" "<< std::endl;
    } // мы скопировали масив 

    //char array1[]{ 'H','e','l','l','o' };//не будет \0, будет работать пока он не попадеться в мусоре
    //std::cout << array1 << std::endl;
    //char array2[]{ "Hello" };
    //std::cout << strlen(array2) << std::endl;
    //char * array_dst[7] {};
    ////strncpy(array_dst, array); //dst - destination
    ////strcmp();
    //std::cout << array_dst << std::endl;

    int value1, value2;
    int& ref=value1; // создана ссылка
    int* ptr = &value1; // создан указатель
    std::cout << sizeof(ref) <<"\t"<< sizeof(ptr) << std::endl; // 4 - размер инта, 4-размер указателя, потому указатель весит 8, зависит от того на что поставлена машины
    std::cout << ref <<"\t"<< ptr << std::endl;  //используя ссылку мы получаем нашу переменную, а по указателю получаем указатель (его нужно розименовать)
                                                // работая со ссылкой мы работаем с переменной, а
                                          //работая с указателем мы работаем с указателем (его нужно розименовать что бы начать работать с переменной через него)
    //* ptr = 400;
    //ptr = &value2; // указатель можно переприсвоить
    //ref = 300; // а вот ссылку нельзя изменить после обьявления

    return 0;
}
