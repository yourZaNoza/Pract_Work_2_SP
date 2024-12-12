#include <iostream>
#include <fstream>
#include "Street.h"
using namespace std;

int main() {
	House* ani1 = new House;
	Wild* ani2 = new Wild;
	House* ani3 = new House;
	Wild* ani4 = new Wild;
	Street* ani5 = new Street;

	IAnimal** arr = new IAnimal * [5] {ani1, ani2, ani3, ani4, ani5};

	bool start = true;
	do
	{
		setlocale(LC_ALL, "");
		std::cout
			<< "Выберите животное: " << std::endl
			<< "1 - домашнее" << std::endl << "2 - дикое" << std::endl
			<< "3 - домашнее" << std::endl << "4 - дикое" << std::endl
			<< "5 - уличное" << std::endl << "0 - выход\n" << std::endl;

		char choice1;
		std::cin >> choice1;
		switch (choice1)
		{
		case '1':
			arr[0]->readFromConsole();
			std::cout
				<< "Выберите действие: " << std::endl
				<< "1 - кормить" << std::endl << "2 - сменить имя" << std::endl
				<< "3 - вывести информацию" << "0 - выход\n" << std::endl;
			char choice2;
			std::cin >> choice2;
			switch (choice2) {
			case '1':
				arr[0]->Feed();
			case '2':
				arr[0]->NameChange();
			case '3':
				arr[0]->display();
			case '0':
				start = false;
				break;
			default:
				break;
			}
			break;
		case '2':
			arr[1]->readFromConsole();
			std::cout
				<< "Выберите действие: " << std::endl
				<< "1 - кормить" << std::endl << "2 - сменить имя" << std::endl
				<< "3 - вывести информацию\n" << "0 - выход\n" << std::endl;
			char choice3;
			std::cin >> choice3;
			switch (choice3) {
			case '1':
				arr[1]->Feed();
			case '2':
				arr[1]->NameChange();
			case '3':
				arr[1]->display();
			case '0':
				start = false;
				break;
			default:
				break;
			}
			break;
		case '3':
			arr[2]->readFromConsole();
			std::cout
				<< "Выберите действие: " << std::endl
				<< "1 - кормить" << std::endl << "2 - сменить имя" << std::endl
				<< "3 - вывести информацию\n" << "0 - выход\n" << std::endl;
			char choice4;
			std::cin >> choice4;
			switch (choice4) {
			case '1':
				arr[2]->Feed();
			case '2':
				arr[2]->NameChange();
			case '3':
				arr[2]->display();
			case '0':
				start = false;
				break;
			default:
				break;
			}
			break;
		case '4':
			arr[3]->readFromConsole();
			std::cout
				<< "Выберите действие: " << std::endl
				<< "1 - кормить" << std::endl << "2 - сменить имя" << std::endl
				<< "3 - вывести информацию\n" << "0 - выход\n" << std::endl;
			char choice5;
			std::cin >> choice5;
			switch (choice5) {
			case '1':
				arr[3]->Feed();
			case '2':
				arr[3]->NameChange();
			case '3':
				arr[3]->display();
			case '0':
				start = false;
				break;
			default:
				break;
			}
			break;
		case '5':
			arr[4]->readFromConsole();
			std::cout
				<< "Выберите действие: " << std::endl
				<< "1 - кормить" << std::endl << "2 - сменить имя" << std::endl
				<< "3 - вывести информацию\n" << "0 - выход\n" << std::endl;
			char choice6;
			std::cin >> choice6;
			switch (choice6) {
			case '1':
				arr[4]->Feed();
			case '2':
				arr[4]->NameChange();
			case '3':
				arr[4]->display();
			case '0':
				start = false;
				break;
			default:
				break;
			}
			break;
		case '0':
			for (int i = 0; i < 5; ++i)
			{
				arr[i]->display();
			}
			start = false;
			break;
		default:
			break;
		}
	} while (start);

	std::ofstream out("Animal.txt", std::ios::out | std::ios::trunc);
	out.close();

	for (int i = 0; i < 5; ++i)
	{
		arr[i]->writeToFile();
		std::cout << "Имя \"" << arr[i]->getAnimalName() << "\" успешно записано в файл." << std::endl;
	}

	delete ani1;
	delete ani2;
	delete ani3;
	delete ani4;
	delete ani5;
	delete[] arr;

	return 0;
};