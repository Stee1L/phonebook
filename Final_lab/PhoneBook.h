#pragma once
#include <string>
using namespace std;

class PhoneBook
{
private: 
	static int Counter;															// общий счётчик для всех объектов
	int ID;																		// уникальный ID объекта

	string Number;																// номер и ФИО
	string Name;
	string Surname;
	string Patronymic;


public:
	PhoneBook();																// конструктор и деструктор
	PhoneBook(string number, string name, string surname, string patronymic);	
	~PhoneBook();

	void setName(string name);													// сеттеры
	void setNumber(string number);
	void setSurname(string surnname);
	void setPatronymic(string patronymic);

	string getName();															// геттеры
	string getSurname();
	string getPatronymic();
	string getNumber();
	int getID();

	// сеттеры и геттеры используются для санкционированного доступа к защищенным свойствам класса

	void printData();
	static void writeToFile(string filename, PhoneBook* Book, int size);
};

string** readDataToArray(string filename);
PhoneBook* insertSortByAlphabet(PhoneBook* Book, int size);
PhoneBook* bubbleSortByAlphabet(PhoneBook* Book, int size);