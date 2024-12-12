#pragma once
#include "IAnimal.h"

class Wild : virtual public IAnimal {
public:
    // конструкторы
    Wild();
    Wild(std::string animalName, std::string animalType, std::string animalColor, int animalAge, float animalWeight, std::string naturePlace);
    Wild(std::string naturePlace);

    // деструктор
    ~Wild();

    // перегруженные операторы
    Wild operator++();
    Wild operator--();
    bool operator< (Wild other);
    bool operator> (Wild other);
    friend std::ostream& operator<< (std::ostream& output, Wild w);

    // геттеры и сеттеры
    void setNaturePlace(std::string naturePlace);
    std::string getNaturePlace();

    // метод
    void display();
    void readFromConsole();
    void writeToFile();
private:
    std::string _naturePlace;
};

