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
	static void writeToFile(string filename, PhoneBook* Book, int size);
};

string** readDataToArray(string filename);
PhoneBook* insertSortByAlphabet(PhoneBook* Book, int size);
PhoneBook* bubbleSortByAlphabet(PhoneBook* Book, int size);