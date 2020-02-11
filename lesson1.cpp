// ConsoleApplication1.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>

int main(int argc, char const *argv[])
{   
	std::cout << "My first project" << '\n'; // новая строка
	std::cout << 5 << '\t'; // табуляция
	std::cout << "My first project" << '\n' << '\t'<<"New" ;
	std::cout << R"(My first project)" << '\n';
	std::cout << 05 << std::endl;
	std::cout << 0xF1 << std::endl;
	std::cout << 100'000 << std::endl;
	std::cout << 1.25 << std::endl;
	std::cout << std::boolalpha << std::endl; // без 0 и 1 - true\false
	std::cout << true << std::endl;
	std::cout << false << std::endl;
	std::cout << std::noboolalpha << std::endl; // отключить bool
	std::cout << true << std::endl;
	std::cout << false << std::endl;
	std::cout << 0b11110000 << std::endl; // написать за что отвечает каждый бит что бы не розшифровывать самому
	std::cout << nullptr << std::endl;
	return 0;
}

// Запуск программы: CTRL+F5 или меню "Отладка" > "Запуск без отладки"
// Отладка программы: F5 или меню "Отладка" > "Запустить отладку"
