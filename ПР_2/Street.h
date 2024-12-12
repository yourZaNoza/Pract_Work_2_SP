#pragma once
#include "IAnimal.h"
#include "House.h"
#include "Wild.h"

class Street : public House, Wild {
public:
    // ������������
    Street();
    Street(std::string animalName, std::string animalType, std::string animalColor, int animalAge, int animalWeight, std::string livingPlace, std::string naturePlace, std::string livingStreet);

    // ����������
    ~Street();

    // ������� � �������
    void setLivingStreet(std::string livingStreet);
    std::string getLivingStreet();

    // ������������� ���������
    Street operator++();
    Street operator--();
    bool operator< (Street other);
    bool operator> (Street other);
    friend std::ostream& operator<< (std::ostream& output, Street s);

    // �����
    void readFromConsole();
    void display();
    void writeToFile();
private:
    std::string _livingStreet;
};


