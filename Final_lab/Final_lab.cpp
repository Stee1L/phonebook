#include <iostream>
#include <string>
#include "PhoneBook.h"
#include <windows.h>
using namespace std;

int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    string** data = readDataToArray("db.txt");

    // создаем и заполняем массив объектов
    PhoneBook Book[20];
    for (int i = 0; i < 20; i++)
    {
        Book[i] = PhoneBook(data[i][0], data[i][1], data[i][2], data[i][3]);
        Book[i].printData();
    }

    // меняем местами верхние и нижние элементы книжки и записываем в файл
    for (int i = 0; i < 10; i++)
        swap(Book[i], Book[19 - i]);

    PhoneBook::writeToFile("db.txt", Book, 20);
    for (int i = 0; i < 20; i++) { Book[i].printData(); }

    // сортировка методом вставки или пузырька (нужное раскомментировать)
    insertSortByAlphabet(Book, 20);
    //bubbleSortByAlphabet(Book, 20);

    PhoneBook::writeToFile("db.txt", Book, 20);
    for (int i = 0; i < 20; i++) { Book[i].printData(); }
}
