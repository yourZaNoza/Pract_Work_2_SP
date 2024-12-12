#pragma once
#include "IAnimal.h"
#include "House.h"
#include "Wild.h"

class Street : public House, Wild {
public:
    // конструкторы
    Street();
    Street(std::string animalName, std::string animalType, std::string animalColor, int animalAge, int animalWeight, std::string livingPlace, std::string naturePlace, std::string livingStreet);

    // деструктор
    ~Street();

    // геттеры и сеттеры
    void setLivingStreet(std::string livingStreet);
    std::string getLivingStreet();

    // перегруженные операторы
    Street operator++();
    Street operator--();
    bool operator< (Street other);
    bool operator> (Street other);
    friend std::ostream& operator<< (std::ostream& output, Street s);

    // метод
    void readFromConsole();
    void display();
    void writeToFile();
private:
    std::string _livingStreet;
};


