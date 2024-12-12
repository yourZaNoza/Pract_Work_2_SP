#include "Street.h"
using namespace std;

// ����������
Street::~Street() {}

// �����������
Street::Street() : Street("undefined", "undefined", "undefined", 0, 0, "undefined", "undefined", "undefined") {}

// ������ �������������
Street::Street(std::string animalName, std::string animalType, std::string animalColor, int animalAge, int animalWeight, std::string livingPlace, std::string naturePlace, std::string livingStreet) :
    IAnimal(animalName, animalType, animalColor, animalAge, animalWeight), House(livingPlace), Wild(naturePlace), _livingStreet(livingStreet) {}

// ������� � �������
void Street::setLivingStreet(std::string livingStreet) {
    this->_livingStreet = correctAlpha(livingStreet);
}
std::string Street::getLivingStreet() {
    return _livingStreet;
}

// ������������� ��������� 
Street Street::operator++() {
    setAnimalWeight(getAnimalWeight() + 0.52);
    return *this;
}

Street Street::operator--() {
    if (getAnimalWeight() > 0)
    {
        setAnimalWeight(getAnimalWeight() - 0.52);
        return *this;
    }
    else cout << "��� ������ 1 ��!" << endl;
}

bool Street::operator< (Street other) {
    return this->getAnimalWeight() < other.getAnimalWeight();
}

bool Street::operator> (Street other) {
    return this->getAnimalWeight() > other.getAnimalWeight();
}

ostream& operator<< (ostream& output, Street s) {
    setlocale(LC_ALL, "");
    output << "���: " << s.getAnimalName() << endl
        << "���: " << s.getAnimalType() << endl
        << "�����: " << s.getAnimalColor() << endl
        << "�������: " << s.getAnimalAge() << endl
        << "����� ����������: " << s.getLivingPlace() << endl
        << "�����: " << s.getAnimalWeight() << endl
        << "__________________" << endl;
    return output;
}

// ������
void Street::readFromConsole() {
    IAnimal::readFromConsole();
    std::cout << "������� ����� ����������: ";
    std::string livingPlace; std::cin >> livingPlace; setLivingPlace(livingPlace);
    std::cout << "������� ����� ��������: ";
    std::string naturePlace; std::cin >> naturePlace; setNaturePlace(naturePlace);
    std::cout << "������� �����: "; std::cin >> _livingStreet;
}

void Street::display() {
    IAnimal::display();
    cout << "����� ����������: " << getLivingPlace() << endl;
    cout << "����� ��������: " << getNaturePlace() << endl;
    cout << "�����: " << _livingStreet << endl;
}

void Street::writeToFile() {
    std::ofstream out;
    out.open("Animal.txt", std::ios::app);
    if (out.is_open()) {
        out << "���: " << getAnimalName() << endl
            << "���: " << getAnimalType() << endl
            << "�����: " << getAnimalColor() << endl
            << "�������: " << getAnimalAge() << endl
            << "����� ����������: " << getLivingPlace() << endl
            << "����� ��������: " << getNaturePlace() << endl
            << "�����: " << _livingStreet << endl
            << "__________________" << endl;
    }
    out.close();
}