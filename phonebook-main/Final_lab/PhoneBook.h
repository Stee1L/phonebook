#pragma once
#include <string>
using namespace std;

class PhoneBook
{
private: 
	static int Counter;															// ����� ������� ��� ���� ��������
	int ID;																		// ���������� ID �������

	string Number;																// ����� � ���
	string Name;
	string Surname;
	string Patronymic;


public:
	PhoneBook();																// ����������� � ����������
	PhoneBook(string number, string name, string surname, string patronymic);	
	~PhoneBook();

	void setName(string name);													// �������
	void setNumber(string number);
	void setSurname(string surnname);
	void setPatronymic(string patronymic);

	string getName();															// �������
	string getSurname();
	string getPatronymic();
	string getNumber();
	int getID();

	// ������� � ������� ������������ ��� ������������������ ������� � ���������� ��������� ������

	void printData();
	static void Interface();
	static int rowsCount(string filename);
	static void writeToFile(string filename, PhoneBook* Book, int size);
	static string** readDataToArray(string filename);
	static PhoneBook* insertSortByAlphabet(PhoneBook* Book, int size);
	static PhoneBook* bubbleSortByAlphabet(PhoneBook* Book, int size);
	static void searchByName(PhoneBook* book, string name);
	static void searchBySurname(PhoneBook* book, string surname);
	static void searchByPatronymic(PhoneBook* book, string patronymic);
	static void searchByNumber(PhoneBook* book, string number);
	static PhoneBook getByID(PhoneBook* book, int ID);
	static void changeData(PhoneBook* Book);
};
