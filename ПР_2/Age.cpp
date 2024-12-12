#include <iostream>
#include "Age.h"

std::string age::correctAlpha(std::string str) {
	setlocale(LC_ALL, "");
	for (int i = 0; i < str.length(); ++i) {
		if (!isalpha(str.at(i)) && !ispunct(str.at(i))) {
			std::cout << "Некорректный ввод данных в поле" << std::endl << "\n" << std::endl;
			return "undefined";
		}
	}
	if (!(str == "undefined")) return str;
}

int age::correctCount(int count) {
	setlocale(LC_ALL, "");
	if (count >= 0) return count;
	else {
		std::cout << "Некорректный ввод данных в поле" << std::endl << "\n" << std::endl;
		return 0;
	}
}