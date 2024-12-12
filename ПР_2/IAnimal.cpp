#include "IAnimal.h"
using namespace std;

// ����������
IAnimal::~IAnimal() {}

//������������
IAnimal::IAnimal() : IAnimal("undefined", "undefined", "undefined", 0, 0) {}

// ������ �������������
IAnimal::IAnimal(std::string animalName, std::string animalType, std::string animalColor, int animalAge, float animalWeight) : _animalName(correctAlpha(animalName)),
_animalType(correctAlpha(animalType)), _animalColor(correctAlpha(animalColor)), _animalAge(correctCount(animalAge)), _animalWeight(correctCount(animalWeight)) {}

// ������������� �������������

// ������� � �������
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

// �����
void IAnimal::display() {
    setlocale(LC_ALL, "");
    cout << "���: " << _animalName << endl;
    cout << "���: " << _animalType << endl;
    cout << "�����: " << _animalColor << endl;
    cout << "�������: " << _animalAge << endl;
    cout << "���: " << _animalWeight << endl;
}
void IAnimal::readFromConsole() {
    setlocale(LC_ALL, "");
    std::cout << "������� ���: "; std::cin >> _animalName;
    std::cout << "������� ���: "; std::cin >> _animalType;
    std::cout << "������� �����: "; std::cin >> _animalColor;
    std::cout << "������� �������: "; std::cin >> _animalAge;
    std::cout << "������� ���: "; std::cin >> _animalWeight;
}
void IAnimal::writeToFile() {}

double IAnimal::Feed() {
    double weight = getAnimalWeight();
    int days;
    cout << "������� ���� ������: ";
    cin >> days;
    double newWeight = weight;
    for (int i = 0; i < days; ++i)
    {
        newWeight += 0.01;
    }
    cout << "����� ���: " << newWeight << endl;
    return newWeight;
}

void IAnimal::NameChange() {
    int answer;
    string newName;
    cout << "������ ������� ���? 1 - ��, 2 - ���: ";
    cin >> answer;
    if (answer == 1) {
        cout << "������� ����� ���: ";
        cin >> newName;
        cout << "�������" << endl;
        setAnimalName(newName);
        cout << "" << endl;
    }
    if (answer == 2) {
        cout << "��������� ��� ����" << endl;
        cout << "" << endl;
    }

}