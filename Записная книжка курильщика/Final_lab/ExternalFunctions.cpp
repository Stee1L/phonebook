#include <string>
#include <iostream>
#include <fstream>
#include "PhoneBook.h"
using namespace std;

/*=========================== EXTERNAL FUNCTIONS ===========================*/

// чтение данных из файла в массив data
string** readDataToArray(string filename)
{
    // открытие файла с именем filename
    ifstream file(filename);
    if (file.is_open()) cout << "‘айл открыт успешно!" << endl;


    // счЄт строк в файле
    int rows = 0;
    string line;
    while (getline(file, line)) { rows++; }             // каждый вызов функции getline() считывает одну строку 
                                                        // до тех пор, пока не достигнет конца файла

    string** data = new string * [rows];                // выделение пам€ти дл€ динамического двумерного массива
    for (int i = 0; i < rows; i++)
        data[i] = new string[4];

    file.clear();                                       // метод clear() используетс€ дл€ сброса состо€ни€ потока
    file.seekg(0, ios::beg);                            // установка позиции чтени€ в начале файла 
                                                        // (0 - позици€, ios::beg - отсчЄт с начала файла)
    // заполн€ем массив данными из файла
    for (int i = 0; i < rows; i++)
        for (int j = 0; j < 4; j++)
            file >> data[i][j];                         // здесь используетс€ перегруженный оператор >> класса ifstream,
                                                        // начина€ с указанной ранее позиции он читает каждое значение файла
                                                        // и записывает в соответствующую €чейку массива data
    file.close();
    return data;
}

// сортировка методом вставки
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

// сортировка методом пузырька
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