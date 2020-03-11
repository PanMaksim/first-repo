//lesson9.2
#include <iostream>
#include <functional>
#include <cstring>

//если c++17, то использовать std::variant, если нет с++17, тогда boost::variant
//есть 2 типа библиотек статические и динамические (если переносить на другую платформу то нужно еще передевать и длл, со файлы, лучше передать всю библиотеку через хидер)
//header only library - все библиотеки в заголовке
//буст славиться этой возможностью

struct A {
	int a;
	int b;
	double c;
};

union U {
	double d;
	int t;
	int array[20];
}; //розмер юниона будет соответствовать саому большому полю (елементу), он в 1 момент времени может работать только с 1 полем

struct Point2D {
	int x;
	int y;
};

struct Point3D {
	int x;
	int y;
	int z;
};

int* alloc(size_t size) {
	return new int[size];
}

void test(bool status) {
	int* ptr2 = new int{ 10 };
	if (status) {
		delete ptr2;//@
		return;//@тут ошибка что мы удаляем в случае успешного иф
	}
	delete ptr2;
}



int main()
{
	U a;
	std::cout << sizeof(U) << std::endl;

	a.d = 10.10;
	std::cout << a.t << std::endl;
	a.t = 0;

	//p1=p2//мы не можем преобразовать 2-х мерное преобразовать в 3-х мерное без сторонних действий
	union {
		Point2D p1;
		Point3D p2;
	};

	p1={ 10,20 };
	std::cout << p2.x << " " << p2.y << std::endl;

	int* ptr = new int[10]{};//выделили память, если попытаемся ввести через син птр, то будет UB потому что мы выдели память под 1 обьект, 
							 //а пытаемся обратиться к обьекту который нам не принадлежит
							 //через нью можем работать с большими данными которые в обычной ситуации переполняют стек
	std::cout << ptr[1] << std::endl;
	delete[] ptr;//освободили память, если делит без [], то мы удаляем только 1 обьект, и будет утечка памяти - UB

	auto ptr1 = alloc(10);
	delete[] ptr1;

	return 0;
}
