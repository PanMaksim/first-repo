#include <iostream>
[[nodiscard]]
auto calc(int value, int value1, bool mult) { //если в конце прописать ->double то мы зафорсим преобрзование в дабл
										//функция void означает что функция ничего не возвращает, если () пустые означает что функция ничего не принимает
										// нельзя обьявлять через запятую как в мейне, все отдельно
										// auto писать в обьявлении функции нельзя писать в соответствиии со стандартами
	std::cout << value << std::endl;
	std::cout << value1 << std::endl;
	if (mult){
		int* ptr = &value;
		double value_d{ 1.2345 };
		//return value*value1;
	}
	return 0;
}

void promt(int *value3, int *value4) {
	/*if (value3 != nullptr || value4 != nullptr) { // начальная проверка на валидность
		std::cout<<"Invalid arguments"<<std::endl;
		return;
	}*/
	std::cout << "Enter values\n";
	std::cin >> *value3 >> *value4;
}

int main(int argc, char const *argv[]) //функция main означает что программа принимает какие-то параметры, и что-то возвращает
{
	int value1{ 10 }, value2{ 100 }, mult (true);
	calc(value1, value2, mult); // происходит прыжок с 1 участка на 2 памяти при начатии функциии калк

	int value4, value5;
	promt( &value4, &value5);
	std::cout << value4 << value5<<std::endl;

	/*int* ptrе = nullptr; // =nullptr никуда не указывает, показывает на необязательность выполнения
	*ptrе = 100;*/

	/*int value{ 10 };
	int* ptr = &value;

	*ptr = 100;

	const int c_value{ 100 };
	const int *ptr_c = &c_value;
	const int c_value1{ 100 };
	ptr_c = &c_value; // можно переприсваивать цель указателя, 
						//но менять констатные указатели нельзя, потому что они только для чтения 
						// указатели тоже могут быть константными const int * const ptr =&c_value (после * параметр указателя), но
						// если елемент константный его нужно сразу инициализировать (=)
						*/
	/*
	int array[5];
	array[1] = 100;
	int*ptr = array;
	int* ptr_4 = &array[4];
	std::cout << ptr << "" << array << std::endl;
	std::cout << ptr_4 << "" << array << std::endl;
	*/

	/*int value;
	int value1;
	int*ptr1 = &value;
	int*ptr2 = &value1;
	if (ptr1 < ptr2) // на общих архитектурах так не делать, проверка куда растет стек
	*/
	
	int array[5]{ 1,2,3,4,5 };
	int* ptr = array;
	std::cout << ptr << std::endl;
	++array[0]; // первый елемент масива увеличиваем на 1
	++ptr; // сдвигаем указатель на байт (байтовая арифметика), передвигаем на 1 елемент
	std::cout << ptr << std::endl;
	ptr += 2;
	std::cout << ptr << std::endl;
	
	/*
	int array[5]{ 1,2,3,4,5 };
	const int* begin = array;
	/*const int* const end = array + 5;//сдвиг на 5 елементов, елемент за последним елементом (не дальше) масива можно использвать для проверки конца масива
	while (begin != end)
	{
		std::cout << begin << std::endl;
		++begin; //считает пока не дойдет до нужного "енд" елемента
	}*//*
	while (*begin)//до нультерминального символа "\0"
	{
		std::cout << begin++ << std::endl;
	}
	std::cout << array[0] /* в другом виде *(array + 0), если написать + 3 то будет смещение на 3 елемента от начала масива*//* << std::endl;*/
	// array +=3; сам масив менять нельзя
	



	return 0;
}
