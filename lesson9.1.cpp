#include <iostream>
#include <functional>
#include <cstring>

//enum бывает unscouped (все переменные не будут принадлежать 1 енаму) и scouped (будут принадлежать 1 енаму при использовании енам класс) 

enum ChoiseUser {
    SELECT,
    COPY,
    UNDEFINED,
    COUNT_USER_CHOISE
};

const char kSelect[]{ "select" };
const char kCopy[]{ "copy" };

void select_user() {
    std::cout << __FUNCTION__ << std::endl; //__PRETTY_FUNCTION__ может не определяться тогда нужно использовать __FUNCTION__
}

void copy() {
    std::cout << __FUNCTION__ << std::endl;
}

void undefined() {
    std::cout << __FUNCTION__ << std::endl;
}

using Func = std::function<void()>;
Func array[COUNT_USER_CHOISE]{select_user,copy,undefined};
ChoiseUser user_command() {
    char select_[1024]{ };
    std::cin >> select_;

    if (strcmp(select_, kSelect) == 0) {
        //strcmp сравнивает 2 строки, если они равны то == 0
        return ChoiseUser::SELECT;

    }

    if (strcmp(select_, kCopy) == 0) {
        return ChoiseUser::COPY;

    }
    else {
        return ChoiseUser::UNDEFINED;
    }


}

int main()
{
    ChoiseUser choise = user_command();
    array[choise];

    return 0;
}
