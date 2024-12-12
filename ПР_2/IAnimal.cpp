#include "IAnimal.h"
using namespace std;

// деструктор
IAnimal::~IAnimal() {}

//конструкторы
IAnimal::IAnimal() : IAnimal("undefined", "undefined", "undefined", 0, 0) {}

// список инициализации
IAnimal::IAnimal(std::string animalName, std::string animalType, std::string animalColor, int animalAge, float animalWeight) : _animalName(correctAlpha(animalName)),
_animalType(correctAlpha(animalType)), _animalColor(correctAlpha(animalColor)), _animalAge(correctCount(animalAge)), _animalWeight(correctCount(animalWeight)) {}

// делегирование конструкторов

// геттеры и сеттеры
void IAnimal::setAnimalName(std::string animalName) {
    this->_animalName = correctAlpha(animalName);
}
std::string IAnimal::getAnimalName() {
    return _animalName;
}
void IAnimal::setAnimalType(std::string animalType) {
    this->_animalType = correctAlpha(animalType);
}
std::string IAnimal::getAnimalType() {
    return _animalType;
}
void IAnimal::setAnimalColor(std::string animalColor) {
    this->_animalColor = correctAlpha(animalColor);
}
std::string IAnimal::getAnimalColor() {
    return _animalColor;
}
void IAnimal::setAnimalAge(int animalAge) {
    this->_animalAge = correctCount(animalAge);
}
int IAnimal::getAnimalAge() {
    return _animalAge;
}
void IAnimal::setAnimalWeight(float animalWeight) {
    this->_animalWeight = correctCount(animalWeight);
}

float IAnimal::getAnimalWeight() {
    return _animalWeight;
}

// метод
void IAnimal::display() {
    setlocale(LC_ALL, "");
    cout << "Имя: " << _animalName << endl;
    cout << "Вид: " << _animalType << endl;
    cout << "Окрас: " << _animalColor << endl;
    cout << "Возраст: " << _animalAge << endl;
    cout << "Вес: " << _animalWeight << endl;
}
void IAnimal::readFromConsole() {
    setlocale(LC_ALL, "");
    std::cout << "Введите имя: "; std::cin >> _animalName;
    std::cout << "Введите вид: "; std::cin >> _animalType;
    std::cout << "Введите окрас: "; std::cin >> _animalColor;
    std::cout << "Введите возраст: "; std::cin >> _animalAge;
    std::cout << "Введите вес: "; std::cin >> _animalWeight;
}
void IAnimal::writeToFile() {}

double IAnimal::Feed() {
    double weight = getAnimalWeight();
    int days;
    cout << "Сколько дней кормим: ";
    cin >> days;
    double newWeight = weight;
    for (int i = 0; i < days; ++i)
    {
        newWeight += 0.01;
    }
    cout << "Новый вес: " << newWeight << endl;
    return newWeight;
}

void IAnimal::NameChange() {
    int answer;
    string newName;
    cout << "Хотите сменить имя? 1 - да, 2 - нет: ";
    cin >> answer;
    if (answer == 1) {
        cout << "Введите новое имя: ";
        cin >> newName;
        cout << "Вписали" << endl;
        setAnimalName(newName);
        cout << "" << endl;
    }
    if (answer == 2) {
        cout << "Оставляем как есть" << endl;
        cout << "" << endl;
    }

}