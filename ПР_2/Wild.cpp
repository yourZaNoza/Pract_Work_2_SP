#include "Wild.h"
using namespace std;

// ����������
Wild::~Wild() {}

//������������
Wild::Wild() : Wild("undefined", "undefined", "undefined", 0, 0, "undefined") {}

// ������ �������������
Wild::Wild(std::string animalName, std::string animalType, std::string animalColor, int animalAge, float animalWeight, std::string naturePlace) :
    IAnimal(animalName, animalType, animalColor, animalAge, animalWeight), _naturePlace(correctAlpha(naturePlace)) {}

// ������������� �������������
Wild::Wild(std::string naturePlace) : _naturePlace(correctAlpha(naturePlace)) {}

// ������� � �������
void Wild::setNaturePlace(std::string naturePlace) {
    this->_naturePlace = correctAlpha(naturePlace);
}
std::string Wild::getNaturePlace() {
    return _naturePlace;
}

// ������������� ��������� 
Wild Wild::operator++() {
    setAnimalWeight(getAnimalWeight() + 0.52);
    return *this;
}

Wild Wild::operator--() {
    if (getAnimalWeight() > 0)
    {
        setAnimalWeight(getAnimalWeight() - 0.52);
        return *this;
    }
    else cout << "��� ������ 1 ��!" << endl;
}

bool Wild::operator< (Wild other) {
    return this->getAnimalWeight() < other.getAnimalWeight();
}

bool Wild::operator> (Wild other) {
    return this->getAnimalWeight() > other.getAnimalWeight();
}

ostream& operator<< (ostream& output, Wild a) {
    setlocale(LC_ALL, "");
    output << "���: " << a.getAnimalName() << endl
        << "���: " << a.getAnimalType() << endl
        << "�����: " << a.getAnimalColor() << endl
        << "�������: " << a.getAnimalAge() << endl
        << "���: " << a.getAnimalWeight() << endl
        << "__________________" << endl;
    return output;
}

void Wild::readFromConsole() {
    IAnimal::readFromConsole();
    cout << "������� ����� ��������: "; cin >> _naturePlace;
}

void Wild::display() {
    IAnimal::display();
    cout << "����� ��������: " << _naturePlace << endl;
}

void Wild::writeToFile() {
    std::ofstream out;
    out.open("Animal.txt", std::ios::app);
    if (out.is_open()) {
        out << "���: " << getAnimalName() << endl
            << "���: " << getAnimalType() << endl
            << "�����: " << getAnimalColor() << endl
            << "�������: " << getAnimalAge() << endl
            << "����� ��������: " << _naturePlace << endl
            << "__________________" << endl;
    }
    out.close();
}