#pragma once
#include "IAnimal.h"

class House : virtual public IAnimal {
public:
    // ������������
    House();
    House(std::string animalName, std::string animalType, std::string animalColor, int animalAge, float animalWeight, std::string livingPlace);
    House(std::string _livingPlace);

    // ����������
    ~House();

    // ������������� ���������
    House operator++();
    House operator--();
    bool operator< (House other);
    bool operator> (House other);
    friend std::ostream& operator<< (std::ostream& output, House h);

    // ������� � �������
    void setLivingPlace(std::string livingPlace);
    std::string getLivingPlace();

    // �����
    void readFromConsole();
    void display();
    void writeToFile();
private:
    std::string _livingPlace;
};

