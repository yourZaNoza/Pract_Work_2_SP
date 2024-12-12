#pragma once
#include "IAnimal.h"

class House : virtual public IAnimal {
public:
    // конструкторы
    House();
    House(std::string animalName, std::string animalType, std::string animalColor, int animalAge, float animalWeight, std::string livingPlace);
    House(std::string _livingPlace);

    // деструктор
    ~House();

    // перегруженные операторы
    House operator++();
    House operator--();
    bool operator< (House other);
    bool operator> (House other);
    friend std::ostream& operator<< (std::ostream& output, House h);

    // геттеры и сеттеры
    void setLivingPlace(std::string livingPlace);
    std::string getLivingPlace();

    // метод
    void readFromConsole();
    void display();
    void writeToFile();
private:
    std::string _livingPlace;
};

