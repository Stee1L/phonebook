#include <iostream>
#include <string>
#include "PhoneBook.h"
#include <windows.h>
using namespace std;

int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    PhoneBook::Interface();

    //string filename = "db.txt";
    //string** data = PhoneBook::readDataToArray(filename);

    //int size = PhoneBook::rowsCount(filename);
    //// создаем и заполняем массив объектов
    //PhoneBook* Book = new PhoneBook[size];
    //for (int i = 0; i < size; i++)
    //{
    //    Book[i] = PhoneBook(data[i][0], data[i][1], data[i][2], data[i][3]);
    //    Book[i].printData();
    //}

    //// меняем местами верхние и нижние элементы книжки и записываем в файл
    //for (int i = 0; i < size / 2; i++)
    //    swap(Book[i], Book[size - i - 1]);

    ////PhoneBook::writeToFile(filename, Book, size);
    //for (int i = 0; i < sizeof(Book); i++) { Book[i].printData(); }

    //// сортировка методом вставки или пузырька (нужное раскомментировать)
    //PhoneBook::insertSortByAlphabet(Book, size);
    ////bubbleSortByAlphabet(Book, 20);

    ////PhoneBook::writeToFile(filename, Book, size);
    //for (int i = 0; i < size; i++) { Book[i].printData(); }
}
