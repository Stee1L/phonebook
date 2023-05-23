#pragma once
#include <string>
using namespace std;

class PhoneBook
{
private:
	static int Count;															// ����� ������� ��� ���� ��������
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
	void setID(int id);

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
	static void searchByName(PhoneBook* book, string name, int size);
	static void searchBySurname(PhoneBook* book, string surname, int size);
	static void searchByPatronymic(PhoneBook* book, string patronymic, int size);
	static void searchByNumber(PhoneBook* book, string number, int size);
	static PhoneBook getByID(PhoneBook* book, int ID, int size);
	static PhoneBook* changeData(PhoneBook* Book, string filename);
	static PhoneBook* removeData(PhoneBook* Book, int size, int id);
	static PhoneBook* addData(PhoneBook* Book, int size);
};
