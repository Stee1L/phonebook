#include <string>
#include <iostream>
#include <fstream>
#include "PhoneBook.h"
using namespace std;

/*=========================== EXTERNAL FUNCTIONS ===========================*/

// ������ ������ �� ����� � ������ data
string** readDataToArray(string filename)
{
    // �������� ����� � ������ filename
    ifstream file(filename);
    if (file.is_open()) cout << "���� ������ �������!" << endl;


    // ���� ����� � �����
    int rows = 0;
    string line;
    while (getline(file, line)) { rows++; }             // ������ ����� ������� getline() ��������� ���� ������ 
                                                        // �� ��� ���, ���� �� ��������� ����� �����

    string** data = new string * [rows];                // ��������� ������ ��� ������������� ���������� �������
    for (int i = 0; i < rows; i++)
        data[i] = new string[4];

    file.clear();                                       // ����� clear() ������������ ��� ������ ��������� ������
    file.seekg(0, ios::beg);                            // ��������� ������� ������ � ������ ����� 
                                                        // (0 - �������, ios::beg - ������ � ������ �����)
    // ��������� ������ ������� �� �����
    for (int i = 0; i < rows; i++)
        for (int j = 0; j < 4; j++)
            file >> data[i][j];                         // ����� ������������ ������������� �������� >> ������ ifstream,
                                                        // ������� � ��������� ����� ������� �� ������ ������ �������� �����
                                                        // � ���������� � ��������������� ������ ������� data
    file.close();
    return data;
}

// ���������� ������� �������
PhoneBook* insertSortByAlphabet(PhoneBook* Book, int size)
{
    for (int i = 0; i < size; i++)
    {
        for (int j = i; j > 0 && Book[j - 1].getSurname() > Book[j].getSurname(); j--)
        {
            swap(Book[j - 1], Book[j]);
        }
    }
    return Book;
}

// ���������� ������� ��������
PhoneBook* bubbleSortByAlphabet(PhoneBook* Book, int size)
{
    for (int i = 0; i < size - 1; i++)
    {
        for (int j = 0; j < size - 1; j++)
        {
            if (Book[j].getSurname() > Book[j + 1].getSurname())
            {
                string temp = Book[j].getSurname();
                Book[j].setSurname(Book[j + 1].getSurname());
                Book[j + 1].setSurname(temp);
            }
        }
    }
    return Book;
}