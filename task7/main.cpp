#include "Set.h"

int main() {
    Set <int> a(5);
    for (int i = 0; i < 2; i++) {
        std::cin >> a;
    }

    Set <int> b(5);
    for (int i = 0; i < 2; i++) {
        std::cin >> b;
    }

    std::cout << "множество а: " << a << std::endl;
    std::cout << "множество b: " << b << std::endl;

    std::cout << "количество элементво а: " << int(a) << std::endl;
    std::cout << "количество элементво b: " << int(b) << std::endl;

    std::cout << "Объединение а + b: " << a + b << std::endl;
    std::cout << "разность а - b: " << a - b << std::endl;

    Set <int> d(5);
    d = a & b;
    std::cout << "пересечение множеств: " << d << std::endl;



    Set <int> temp(5);



    temp = a;

    std::cout << "temp : " << temp << std::endl;


    temp = temp + 11;
    std::cout << "temp после добавления a: " << temp << std::endl;

    std::cout << "temp[1] " << temp[1] << std::endl;

	std::cout << "XXX";
	//for (Set<int>::iterator it = temp.begin(); it != temp.end(); it++) {
	//	std::cout << *it << std::endl;
	//}
	for (auto &it : temp) { // range based loop, equals to ---> for (Set<int>::iterator it = temp.begin(); it != temp.end(); it++) {}
		std::cout << it << std::endl;
	}
	std::cout << "YYY";

    return 0;
}
