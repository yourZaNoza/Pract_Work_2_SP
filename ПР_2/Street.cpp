#include "Street.h"
using namespace std;

// деструктор
Street::~Street() {}

// конструктор
Street::Street() : Street("undefined", "undefined", "undefined", 0, 0, "undefined", "undefined", "undefined") {}

// список инициализации
Street::Street(std::string animalName, std::string animalType, std::string animalColor, int animalAge, int animalWeight, std::string livingPlace, std::string naturePlace, std::string livingStreet) :
    IAnimal(animalName, animalType, animalColor, animalAge, animalWeight), House(livingPlace), Wild(naturePlace), _livingStreet(livingStreet) {}

// геттеры и сеттеры
void Street::setLivingStreet(std::string livingStreet) {
    this->_livingStreet = correctAlpha(livingStreet);
}
std::string Street::getLivingStreet() {
    return _livingStreet;
}

// перегруженные операторы 
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
    else cout << "Вес меньше 1 кг!" << endl;
}

bool Street::operator< (Street other) {
    return this->getAnimalWeight() < other.getAnimalWeight();
}

bool Street::operator> (Street other) {
    return this->getAnimalWeight() > other.getAnimalWeight();
}

ostream& operator<< (ostream& output, Street s) {
    setlocale(LC_ALL, "");
    output << "Имя: " << s.getAnimalName() << endl
        << "Вид: " << s.getAnimalType() << endl
        << "Окрас: " << s.getAnimalColor() << endl
        << "Возраст: " << s.getAnimalAge() << endl
        << "Место жительства: " << s.getLivingPlace() << endl
        << "Улица: " << s.getAnimalWeight() << endl
        << "__________________" << endl;
    return output;
}

// методы
void Street::readFromConsole() {
    IAnimal::readFromConsole();
    std::cout << "Введите место жительства: ";
    std::string livingPlace; std::cin >> livingPlace; setLivingPlace(livingPlace);
    std::cout << "Введите среду обитания: ";
    std::string naturePlace; std::cin >> naturePlace; setNaturePlace(naturePlace);
    std::cout << "Введите улицу: "; std::cin >> _livingStreet;
}

void Street::display() {
    IAnimal::display();
    cout << "Место жительства: " << getLivingPlace() << endl;
    cout << "Среда обитания: " << getNaturePlace() << endl;
    cout << "Улица: " << _livingStreet << endl;
}

void Street::writeToFile() {
    std::ofstream out;
    out.open("Animal.txt", std::ios::app);
    if (out.is_open()) {
        out << "Имя: " << getAnimalName() << endl
            << "Вид: " << getAnimalType() << endl
            << "Окрас: " << getAnimalColor() << endl
            << "Возраст: " << getAnimalAge() << endl
            << "Место жительства: " << getLivingPlace() << endl
            << "Среда обитания: " << getNaturePlace() << endl
            << "Улица: " << _livingStreet << endl
            << "__________________" << endl;
    }
    out.close();
}