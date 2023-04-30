#include "PhoneBook.h"
#include <iostream>
#include <functional>
#include <string>
#include <fstream>

using namespace std;
int PhoneBook::Counter = 1;

/*============================== CONSTRUCTORS ==============================*/
PhoneBook::PhoneBook(string number, string surname, string name, string patronymic)
{
	ID = Counter++;
	Name = name;
    Surname = surname;
    Patronymic = patronymic;
	Number = number;
}

PhoneBook::PhoneBook() { Name = ""; Surname = ""; Patronymic = ""; Number = ""; }
PhoneBook::~PhoneBook() {}

/*================================ SETTERS ================================*/
void PhoneBook::setName(string name)                { Name = name; }
void PhoneBook::setSurname(string surnname)         { Surname = surnname; }
void PhoneBook::setPatronymic(string patronymic)    { Patronymic = patronymic; }
void PhoneBook::setNumber(string number)            { Number = number; }

/*================================ GETTERS ================================*/
string PhoneBook::getName()		    { return Name; }
string PhoneBook::getSurname()      { return Surname; }
string PhoneBook::getPatronymic()   { return Patronymic; }
string PhoneBook::getNumber()       { return Number; }
int PhoneBook::getID()              { return ID; }

/*=============================== FUNCTIONS ===============================*/

void PhoneBook::printData()
{
    cout << "ID: " << this->getID() << endl;
    cout << "�������: " << this->getSurname() << endl;
    cout << "���: " << this->getName() << endl;
    cout << "��������: " << this->getPatronymic() << endl;
    cout << "����� ��������: " << this->getNumber() << endl << endl;
}

void PhoneBook::writeToFile(string filename, PhoneBook* Book, int size)
{
    // ��������� ��������� �� ���� ������ ��������, � ����� ���������� �������� ������� ������� � ����
    ofstream file(filename, ios::in | ios::out);
    string line;

    if (file.is_open()) cout << "���� ������ �������!" << endl;

    // ������ ����� ������ � ����
    for (int i = 0; i < size; i++)
    {
        file << Book[i].getNumber();
        file << " ";
        file << Book[i].getSurname();
        file << " ";
        file << Book[i].getName();
        file << " ";
        file << Book[i].getPatronymic();
        file << endl;
    }
}
