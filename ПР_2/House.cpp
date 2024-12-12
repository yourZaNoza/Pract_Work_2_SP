#include "House.h"
using namespace std;

// деструктор
House::~House() {}

//конструкторы
House::House() : House("undefined", "undefined", "undefined", 0, 0, "undefined") {}

// список инициализации
House::House(std::string animalName, std::string animalType, std::string animalColor, int animalAge, float animalWeight, std::string livingPlace) :
    IAnimal(animalName, animalType, animalColor, animalAge, animalWeight), _livingPlace(correctAlpha(livingPlace)) {}

// делегирование конструкторов
House::House(std::string livingPlace) : _livingPlace(correctAlpha(livingPlace)) {}

// геттеры и сеттеры
void House::setLivingPlace(std::string livingPlace) {
    this->_livingPlace = correctAlpha(livingPlace);
}
std::string House::getLivingPlace() {
    return _livingPlace;
}

// перегруженные операторы 
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
    else cout << "Вес меньше 1 кг!" << endl;
}

bool House::operator< (House other) {
    return this->getAnimalWeight() < other.getAnimalWeight();
}

bool House::operator> (House other) {
    return this->getAnimalWeight() > other.getAnimalWeight();
}

ostream& operator<< (ostream& output, House h) {
    setlocale(LC_ALL, "");
    output << "Имя: " << h.getAnimalName() << endl
        << "Вид: " << h.getAnimalType() << endl
        << "Окрас: " << h.getAnimalColor() << endl
        << "Возраст: " << h.getAnimalAge() << endl
        << "Вес: " << h.getAnimalWeight() << endl
        << "__________________" << endl;
    return output;
}

// методы
void House::readFromConsole() {
    IAnimal::readFromConsole();
    cout << "Введите место жительства: "; cin >> _livingPlace;
}

void House::display() {
    IAnimal::display();
    cout << "Мeсто жительства: " << _livingPlace << endl;
}

void House::writeToFile() {
    std::ofstream out;
    out.open("Animal.txt", std::ios::app);
    if (out.is_open()) {
        out << "Имя: " << getAnimalName() << endl
            << "Вид: " << getAnimalType() << endl
            << "Окрас: " << getAnimalColor() << endl
            << "Возраст: " << getAnimalAge() << endl
            << "Место жительства: " << _livingPlace << endl
            << "__________________" << endl;
    }
    out.close();
}