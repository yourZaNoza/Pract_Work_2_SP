#include "House.h"
using namespace std;

// ����������
House::~House() {}

//������������
House::House() : House("undefined", "undefined", "undefined", 0, 0, "undefined") {}

// ������ �������������
House::House(std::string animalName, std::string animalType, std::string animalColor, int animalAge, float animalWeight, std::string livingPlace) :
    IAnimal(animalName, animalType, animalColor, animalAge, animalWeight), _livingPlace(correctAlpha(livingPlace)) {}

// ������������� �������������
House::House(std::string livingPlace) : _livingPlace(correctAlpha(livingPlace)) {}

// ������� � �������
void House::setLivingPlace(std::string livingPlace) {
    this->_livingPlace = correctAlpha(livingPlace);
}
std::string House::getLivingPlace() {
    return _livingPlace;
}

// ������������� ��������� 
House House::operator++() {
    setAnimalWeight(getAnimalWeight() + 0.52);
    return *this;
}

House House::operator--() {
    if (getAnimalWeight() > 0)
    {
        setAnimalWeight(getAnimalWeight() - 0.52);
        return *this;
    }
    else cout << "��� ������ 1 ��!" << endl;
}

bool House::operator< (House other) {
    return this->getAnimalWeight() < other.getAnimalWeight();
}

bool House::operator> (House other) {
    return this->getAnimalWeight() > other.getAnimalWeight();
}

ostream& operator<< (ostream& output, House h) {
    setlocale(LC_ALL, "");
    output << "���: " << h.getAnimalName() << endl
        << "���: " << h.getAnimalType() << endl
        << "�����: " << h.getAnimalColor() << endl
        << "�������: " << h.getAnimalAge() << endl
        << "���: " << h.getAnimalWeight() << endl
        << "__________________" << endl;
    return output;
}

// ������
void House::readFromConsole() {
    IAnimal::readFromConsole();
    cout << "������� ����� ����������: "; cin >> _livingPlace;
}

void House::display() {
    IAnimal::display();
    cout << "�e��� ����������: " << _livingPlace << endl;
}

void House::writeToFile() {
    std::ofstream out;
    out.open("Animal.txt", std::ios::app);
    if (out.is_open()) {
        out << "���: " << getAnimalName() << endl
            << "���: " << getAnimalType() << endl
            << "�����: " << getAnimalColor() << endl
            << "�������: " << getAnimalAge() << endl
            << "����� ����������: " << _livingPlace << endl
            << "__________________" << endl;
    }
    out.close();
}